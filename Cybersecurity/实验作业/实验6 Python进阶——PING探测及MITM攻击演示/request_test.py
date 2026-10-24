import requests
#1.模拟登录，获取 Cookie
response=requests.get("https://httpbingo.org/cookies/set?vip_card=admin666")

print("---第一次请求返回值---")
print(response.text)
#2. 模拟访问后台页面
response = requests.get("https://httpbingo.org/cookies")
print("---第二次请求返回值---")
print(response.text) 