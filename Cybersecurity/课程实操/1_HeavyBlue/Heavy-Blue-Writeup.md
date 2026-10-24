# Heavy Blue 题解

## 题目信息

- 题目名称：Heavy Blue
- 题目类型：Misc
- 题目分值：10 PT
- 题目附件：`flag.bmp`
- 题目描述：`In your eyes there's a heavy blue.`

## 解题思路

题目名称和描述都强调了 `Blue`，因此优先检查 BMP 图片的蓝色通道。

### 1. 查看附件信息

使用 `file` 查看图片格式：

```bash
file flag.bmp
```

输出如下：

```text
flag.bmp: PC bitmap, Windows 3.x format, 433 x 433 x 24
```

附件是一张尺寸为 `433 × 433` 的 24-bit BMP 图片。24-bit BMP 通常按照 `BGR` 顺序保存每个像素，即每个像素的第一个字节是蓝色通道。

### 2. 提取蓝色通道

查看像素数据可以发现，蓝色通道中存在大量类似下面的可打印字符：

```text
/mAQfjvMkfL/k8Qg0k+kb7pEAoBDQ/BlQ/CQE+z9...
```

这些字符符合 Base64 的字符特征。

BMP 文件的每一行按 4 字节对齐，因此提取像素时需要跳过行尾的 padding。此外，本题 BMP 的高度为正数，表示扫描行按照从下到上的顺序存储。要按照正常顺序恢复隐藏数据，需要先反转扫描行，再依次提取每个像素的蓝色分量。

### 3. Base64 解码

将蓝色通道数据按照正确的行顺序拼接，去除用于填充的 `NUL` 字节，然后进行 Base64 解码。解码后的数据文件头如下：

```text
FD 37 7A 58 5A 00
```

这是 XZ 压缩格式的文件头。

### 4. 递归解压

解压第一层 XZ 后会得到 ZIP 文件。ZIP 内的 `flag` 文件仍然是压缩数据，后续内容在以下三种格式之间反复嵌套：

- XZ：文件头为 `FD 37 7A 58 5A 00`
- ZIP：文件头为 `50 4B 03 04`
- GZIP：文件头为 `1F 8B`

因此，可以根据文件头判断当前压缩格式并递归解压，直到内容不再匹配上述格式。

本题总共需要处理 1999 层压缩：

- XZ：666 层
- ZIP：661 层
- GZIP：672 层

## 解题脚本

将以下代码保存为 `solve.py`，并与 `flag.bmp` 放在同一目录中：

```python
import base64
import gzip
import io
import lzma
import struct
import zipfile
from pathlib import Path


BMP_PATH = Path("flag.bmp")


def extract_blue_channel(path: Path) -> bytes:
    data = path.read_bytes()

    if data[:2] != b"BM":
        raise ValueError("附件不是有效的 BMP 文件")

    pixel_offset = struct.unpack_from("<I", data, 10)[0]
    width = struct.unpack_from("<i", data, 18)[0]
    height = struct.unpack_from("<i", data, 22)[0]
    bits_per_pixel = struct.unpack_from("<H", data, 28)[0]

    if bits_per_pixel != 24:
        raise ValueError(f"不支持的位深：{bits_per_pixel}")

    row_size = ((width * 3 + 3) // 4) * 4
    rows = []

    for y in range(abs(height)):
        start = pixel_offset + y * row_size
        row = data[start:start + width * 3]

        # 24-bit BMP 使用 BGR 顺序，第一个字节为蓝色分量。
        rows.append(row[0::3])

    # 高度为正数的 BMP 从下往上存储扫描行。
    if height > 0:
        rows.reverse()

    encoded = b"".join(rows)

    # 去除图片中未使用位置的 NUL 填充字节。
    return encoded.replace(b"\x00", b"")


def unpack_layers(data: bytes) -> bytes:
    counts = {
        "xz": 0,
        "zip": 0,
        "gzip": 0,
    }

    for layer in range(1, 10000):
        if data.startswith(b"\xfd7zXZ\x00"):
            data = lzma.decompress(data)
            counts["xz"] += 1

        elif data.startswith(b"PK\x03\x04"):
            with zipfile.ZipFile(io.BytesIO(data)) as archive:
                names = archive.namelist()

                if len(names) != 1:
                    raise ValueError(
                        f"第 {layer} 层 ZIP 包含多个文件：{names}"
                    )

                data = archive.read(names[0])

            counts["zip"] += 1

        elif data.startswith(b"\x1f\x8b"):
            data = gzip.decompress(data)
            counts["gzip"] += 1

        else:
            print(f"解压完成，共处理 {layer - 1} 层")
            print(f"XZ: {counts['xz']}")
            print(f"ZIP: {counts['zip']}")
            print(f"GZIP: {counts['gzip']}")
            return data

    raise RuntimeError("压缩层数超过预期")


encoded = extract_blue_channel(BMP_PATH)
compressed = base64.b64decode(encoded, validate=True)
result = unpack_layers(compressed)

print(result.decode())
```

运行脚本：

```bash
python3 solve.py
```

运行结果：

```text
解压完成，共处理 1999 层
XZ: 666
ZIP: 661
GZIP: 672
flag{0c9ed26d-9c6d-4e88-8def-37914ff9f642}
```

## 最终 Flag

```text
flag{0c9ed26d-9c6d-4e88-8def-37914ff9f642}
```

