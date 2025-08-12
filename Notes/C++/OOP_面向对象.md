# OOP_面向对象

## 类与对象

### 构造函数

构造函数是 C++ 中一种特殊的成员函数，它在对象**被创建时**自动调用，用来*初始化对象的成员变量*。它有如下几个要点：

- 名字和类（或结构体）的名字**完全相同**（区分大小写）。

- 没有返回值类型（连 `void` 都不能写）。

- 可以有参数，也可以没有参数（无参构造）。

- 在对象定义时，构造函数会自动执行一次。

构造函数的用法示例：

```c++
Bigint a;         // 调用 Bigint(0) 构造，表示数字 0
Bigint b(12345);  // 定义 + 初始化，调用 Bigint(12345) 构造，
b.Bigint(12345);  // ❌ 错误！构造函数不能这样手动调用
```



### 运算符重载

运算符重载是 C++ 的一项特性，允许你为自定义类型（类、结构体）*重新定义或扩展内置运算符的行为*。这意味着你可以用 `+`, `-`, `[]`, `<<` 等符号直接操作自己设计的对象，就像操作基本数据类型一样自然而符合直觉。

运算符重载的基本语法：

```c++
返回类型 operator 运算符 (参数列表) {
    // 函数体，定义运算符行为
}	
```

`operator` 是关键字，后面紧跟要重载的运算符符号，如 `+`、`[]`、`()` 等；

函数可以是**成员函数**或**非成员函数**（一般二元运算符支持两种形式）；

参数数量和类型由运算符的“固有规则”决定，比如：

- 一元运算符（`++`、`!`）一个参数或无参数
- 二元运算符（`+`、`-`、`[]`）两个参数（成员函数中其实是一个，隐含调用对象是第一个）

下面是一些例子：

二元运算符（加法）：

```c++
struct Point { // 成员函数重载加法
    int x, y;
    Point(int _x=0, int _y=0) : x(_x), y(_y) {} 
    Point operator+(const Point& other) const { 
        return Point(x + other.x, y + other.y);
    }
};

Point p1(1, 2), p2(3, 4);
Point p3 = p1 + p2; // p3 = (4, 6)

```

下标运算符：

```cpp
struct ArrayWrapper {
    int arr[5]{1,2,3,4,5};
    int& operator[](int index) {
        return arr[index];
    }
    const int& operator[](int index) const {
        return arr[index];
    }
};

ArrayWrapper a;
a[0] = 100;           // 修改第一个元素
int x = a[2];         // 读取第三个元素

```

函数调用运算符：

```cpp
struct Multiplier {
    int factor;
    Multiplier(int f) : factor(f) {} // 通过成员初始化列表将 factor 初始化为 f
    int operator()(int x) { // 重载了 () 运算符，使得该类的对象可以像函数一样被调用，即在该类下 (i) 相当于调用 mul.operator()(i)
        return x * factor;
    }
};

Multiplier mul(3);
int res = mul(5);  // 结果是15
```

重载了 `operator()` 的类（**函数对象**，即 `Multiplier` ）可以像普通函数一样被调用，这正是它的核心用途。它的行为类似于函数，但**本质是一个对象，因此可以保存状态、作为模板参数、被编译器内连**，比普通函数更灵活。

**函数对象可以保存状态**：函数对象（如 `Multiplier`）的本质是**类的实例**，因此它可以通过成员变量保存内部状态。这里的“状态”指的是对象在生命周期内持有的数据。

```cpp
void process(int x, Multiplier op) {
    std::cout << op(x);  // 调用函数对象
}

int main() {
    Multiplier triple(3); // 状态：factor = 3
    process(10, triple); // 使用状态：3 * 10 = 30，保留了 factor 的值
}

// 若使用函数指针：
int multiply(int x, int factor) { return x * factor; }
multiply(2, 4); // 每次需传递 factor
```

**函数对象可以作为模板参数**：C++ 模板在编译时需要具体类型。函数对象是**类型**（类的实例），因此可以直接作为模板参数，而函数指针需要额外处理。

一个在 STL 算法中使用的例子：

```cpp
std::vector<int> nums = {1, 2, 3};
Multiplier times2(2);

// std::transform 的模板参数需要可调用对象的类型
std::transform(nums.begin(), nums.end(), nums.begin(), times2);
// nums 变为 {2, 4, 6}

// 若使用函数指针：
int (*func_ptr)(int) = [](int x) { return x * 2; }; // 函数指针
std::transform(nums.begin(), nums.end(), nums.begin(), func_ptr); // 也可工作，但效率可能更低
```

