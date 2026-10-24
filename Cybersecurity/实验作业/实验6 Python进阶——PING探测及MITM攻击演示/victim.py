import requests

# 受害者以为这是“校园网极速登录节点”官方的登录接口，这儿使用本地环回地址做测试
fake_gateway_url = "http://127.0.0.1:8080/login"

# 受害者输入自己真实的账号密码
login_data = {
    "username": "freshman_xiaobai"
    "password": "MySuperSecretPassword"
}

print("[😇 受害者] 正在向极速节点发送登录请求...")
response = requests.post(fake_gateway_url, data=login_data)

# 受害者查看服务器返回的结果
print("\n[😇 受害者] 收到服务器的返回数据：")
print(response.text)