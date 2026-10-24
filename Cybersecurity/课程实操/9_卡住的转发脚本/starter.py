#!/usr/bin/env python3
"""Fix four course-level request-flow defects, then run this file locally."""
import json
import urllib.error
import urllib.request
from http.cookiejar import CookieJar


def set_path(data, dotted_path, value):
    current = data
    parts = dotted_path.split(".")
    for part in parts[:-1]:
        current = current[part]
    current[parts[-1]] = value


def get_path(data, dotted_path):
    current = data
    for part in dotted_path.split("."):
        current = current[part]
    return current


config = json.load(open("config.json", encoding="utf-8"))
base = config["api_base"]
receipts = []

opener = urllib.request.build_opener(urllib.request.HTTPCookieProcessor(CookieJar()))


def request_json(method, path, payload=None):
    body = None
    headers = {"Accept": "application/json"}
    if payload is not None:
        body = json.dumps(payload).encode("utf-8")
        headers["Content-Type"] = "application/json"
    request = urllib.request.Request(base + path, data=body, headers=headers, method=method)
    try:
        with opener.open(request) as response:
            return response.status, json.load(response)
    except urllib.error.HTTPError as error:
        try:
            return error.code, json.load(error)
        except json.JSONDecodeError:
            raise


status, _ = request_json("POST", "/api/bootstrap", {})
if status >= 400:
    raise RuntimeError(f"bootstrap failed: {status}")

transform = config["transform"]
for _ in range(config["event_count"]):
    status, event = request_json("GET", "/api/events/next")
    if status >= 400:
        raise RuntimeError(f"next event failed: {status}")

    target_value = get_path(event, transform["target_path"])
    if transform["operation"] == "prefix":
        set_path(event, transform["target_path"], transform["prefix"] + target_value)
    else:
        raise ValueError(f"unsupported transform operation: {transform['operation']}")
    set_path(event, transform["required_field"], transform["required_value"])

    while True:
        status, body = request_json("POST", "/api/upstream", {"event": event})
        if status in config["retry_statuses"]:
            if body.get("retryable") is True:
                continue
        if status >= 400:
            raise RuntimeError(f"upstream failed: {status} {body}")
        receipts.append(body["receipt"])
        break

with open("result.json", "w", encoding="utf-8") as output:
    json.dump(receipts, output)
status, body = request_json("POST", "/api/claim", {"receipts": receipts})
print(json.dumps(body, ensure_ascii=False))
if status >= 400:
    raise RuntimeError(f"claim failed: {status} {body}")
