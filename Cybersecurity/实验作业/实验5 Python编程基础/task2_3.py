import sys

import requests


url = "https://postman-echo.com/post"
data = {"username": "admin", "password": "123456"}

try:
    response = requests.post(url, data=data, timeout=15)
except requests.RequestException:
    print("目标服务器暂时不可用，请稍后再试！")
    sys.exit(1)

if response.status_code == 200:
    if "123456" in response.text:
        print("数据提交成功")
    else:
        print("服务器响应中未找到预期字段")
else:
    print("目标服务器暂时不可用，请稍后再试！")
