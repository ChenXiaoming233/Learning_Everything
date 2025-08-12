# SL_标准库



## <iomanip>

### 保留有效数字与小数

#### 保留有效数字：

```c++
cout << setprecision(3) << a; // 3 为保留的有效数字位数
```

`std::setprecision` 是一个 I/O 操纵符，用于控制浮点数输出的精度（即显示多少位有效数字或小数位数），通常与`std::fixed`等连用。一旦使用，**后续的所有 `std::cout`（或该流）都会保持这个设定**，直到显式更改或程序结束。

如果需要恢复默认（通常是 6 位有效数字）：

```c++
std::cout << std::defaultfloat; 
```



#### 保留小数：

```c++
cout << setiosflags(ios::fixed) << setprecision(3) << a; // 3 为保留的小数位数
cout << setiosflags(ios::fixed | ios::showpos) << std::setprecision(2) << num << std::endl; // 同时启用 fixed 与 showpos
cout << fixed << setprecision(3) << a; // 简化方法
```

`setiosflags` 用于 **永久性** 设置流的格式标志。一旦使用 `std::setiosflags`（或 `std::fixed`、`std::scientific` 等格式操纵符）设置了流的格式标志，**后续的所有 `std::cout`（或该流）都会保持这个设定**，直到显式更改或程序结束。

 `ios::flag` 是 `std::ios` 命名空间下的格式标志，例如：

- `ios::fixed`：使用**定点表示法**（强制显示小数部分）；
- `ios::scientific`：使用**科学计数法**；
- `ios::showpos`：正数显示 `+` 号；
- `ios::uppercase`：科学计数法中的字母大写（如 `1E+10` 而不是 `1e+10`）；
- `ios::showpoint`：强制显示小数点

可以使用 `std::resetiosflags` 重置所有标志，或切换为其他格式。

```c++
cout << std::resetiosflags(std::ios::fixed); // 取消 fixed
```



