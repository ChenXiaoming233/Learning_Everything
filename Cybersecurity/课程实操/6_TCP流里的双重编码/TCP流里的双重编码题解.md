# TCP 流里的双重编码题解

## 题目考点

本题主要考察以下内容：

1. 使用 Wireshark 分析 PCAP 网络流量
2. 通过 `Follow TCP Stream` 重组完整的 TCP 会话
3. 识别 HTTP 请求中的自定义请求头 `X-Trace`
4. 识别并还原 URL 百分号编码
5. 识别并解码 Base64 数据
6. 根据题目提示判断多层编码的正确解码顺序

## 解题思路

使用 Wireshark 打开题目附件 `tcp_trace.pcap`，在数据包列表中找到 HTTP 请求流量。由于题目提示线索位于完整 TCP 会话中，因此选中相关数据包，右键依次选择：

```text
Follow → TCP Stream
```

在重组后的 TCP 会话中可以看到如下 HTTP 请求：

```http
GET /submit HTTP/1.1
Host: updates.intra
User-Agent: campus-agent/1.0
X-Trace: VFJBQ0UtM0xLSVQzUkFXUEc2N0ZTRklNNFZIWEZZWVdVTw%3D%3D
Accept: */*
Connection: close
```

其中，可疑的 `X-Trace` 请求头内容为：

```text
VFJBQ0UtM0xLSVQzUkFXUEc2N0ZTRklNNFZIWEZZWVdVTw%3D%3D
```

字符串末尾的 `%3D` 是字符 `=` 的 URL 百分号编码。按照题目给出的顺序，首先进行 URL 解码，得到：

```text
VFJBQ0UtM0xLSVQzUkFXUEc2N0ZTRklNNFZIWEZZWVdVTw==
```

解码后的字符串由字母、数字以及末尾的 `==` 组成，符合 Base64 编码的常见特征。继续进行 Base64 解码，得到：

```text
TRACE-3LKIT3RAWPG67FSFIM4VHXFYYWUO
```

也可以使用 Python 一次完成两层解码：

```python
import base64
import urllib.parse

encoded = "VFJBQ0UtM0xLSVQzUkFXUEc2N0ZTRklNNFZIWEZZWVdVTw%3D%3D"
url_decoded = urllib.parse.unquote(encoded)
flag = base64.b64decode(url_decoded).decode()

print(flag)
```

## 最终输出的 flag

```text
TRACE-3LKIT3RAWPG67FSFIM4VHXFYYWUO
```
