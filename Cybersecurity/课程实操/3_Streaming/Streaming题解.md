# 题解

## 题目考点

本题主要考察以下内容：

1. RTP/H.264 流量提取与视频还原
2. 视频画面中隐藏提示信息的分析
3. 异或预处理
4. AES-ECB 解密
5. ZIP 文件恢复与解包
6. PNG `iDOT` 特性分析，即 macOS 与普通 PNG 查看器显示差异
7. 残缺 MOV/MP4 文件头修复
8. 黑白帧二进制信息提取

## 解题思路

题目给了两个附件：

```text
？.pcapng
？？
```

首先分析 `？.pcapng`，发现其中包含 RTP 传输的 H.264 视频流。将 RTP/H.264 数据提取并还原为视频帧后，可以在画面中看到如下信息：

```text
flag1 is 'flag{3b3a9c08-'
hint:it's not just flag!!!
```

由此得到第一段 flag：

```text
flag{3b3a9c08-
```

同时需要注意画面中的字符串带有单引号：

```text
'flag{3b3a9c08-'
```

该字符串长度正好为 16 字节，因此可以作为 AES-128 的密钥。

接下来处理第二个附件 `？？`。该文件本身是高熵二进制数据，长度为 7008 字节，符合 AES 分组加密后密文的特征。

处理方式如下：

1. 对 `？？` 的每个字节异或 `0xff`
2. 使用 AES-128-ECB 解密
3. 解密密钥为包含两侧单引号的字符串：

```text
'flag{3b3a9c08-'
```

解密后得到一个 ZIP 文件。解压后得到两个文件：

```text
badapple
s4cret
```

其中 `badapple` 实际上是 PNG 图片。查看其文件结构可以发现存在 `iDOT` 块，这是 Apple/macOS 相关的 PNG 特性，会导致 macOS 预览效果与普通图片查看器不同。

使用 `macos_shadow_tank` 项目处理该 PNG：

```text
https://github.com/GGN-2015/macos_shadow_tank
```

将 `badapple` 作为项目中的 `sample/merged.png`，运行：

```bash
python3 preview_macos.py
```

得到 macOS 视角下的图片内容，其中显示：

```text
flag2 is 88e4-4d65-b59e
```

因此第二段 flag 为：

```text
88e4-4d65-b59e
```

然后处理 `s4cret`。该文件是残缺的 MOV 文件，开头缺少文件大小字段。原始开头为：

```text
14 66 74 79 70 ...
```

需要补成合法的 MOV/MP4 atom 头：

```text
00 00 00 14 66 74 79 70 ...
```

也就是在文件头部补充 `00 00 00`，然后改为 `.mov` 文件。

修复后播放或抽帧，可以看到视频由黑白画面闪烁组成。按照规则：

```text
黑色 = 1
白色 = 0
```

将每帧转换为二进制位，再按 8 位一组转 ASCII，得到：

```text
the flag3 is -13891ba324da}
```

因此第三段 flag 为：

```text
-13891ba324da}
```

最后将三段拼接：

```text
flag{3b3a9c08-
88e4-4d65-b59e
-13891ba324da}
```

## 最终输出的 flag

```text
flag{3b3a9c08-88e4-4d65-b59e-13891ba324da}
```
