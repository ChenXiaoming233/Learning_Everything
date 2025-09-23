#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define maxn 2000

// 支持对大数的存储、加乘与输出，不支持直接输入大数
struct Bigint
{
    int len;
    int a[maxn]; // 数组 a 的高位一直存在，通过 len 的值控制循环终止来限制对高位的访问

    // 构造函数，支持 int 类型参数输入
    Bigint(int x = 0)
    {
        len = 0;
        memset(a, 0, sizeof(a)); // 重置数组 a[maxn] 为 0；
        do
        {
            a[++len] = x % 10; // 提取每位数字进入数组
            x /= 10;           // 去除已经取出的一位数

        } while (x > 0); // x = 0 时提取完毕退出
    }

    // 下标运算符重载，可以像访问数组一样访问 x[] 而无需使用 x.a[]
    int &operator[](int i)
    {
        return a[i];
    }

    // 用于常量版本的下标运算符重载
    const int &operator[](int i) const // 后一个 const 表示成员函数不会修改调用对象
    {
        return a[i];
    }

    // 在大数计算后，归位进位且去除多余前导0
    void flatten(int L) // L 为当前运算结果的最大可能长度，需另外提供，用于后续加乘运算的进位退位问题中控制处理长度
    {
        len = L; // 传入预估最大长度 L 而非使用原有 len，确保完全处理
        for (int i = 1; i < len; i++)
        {
            a[i + 1] += a[i] / 10; // 将 a[i] 高于个位的值进位至 a[i + 1]
            a[i] %= 10;            // 保留 a[i] 个位
        }

        // 去除前导0 但至少保留一位数，确定大数 len 的值
        while (len > 1 and a[len] == 0) // 注意倒序处理 len 的同时也将 len 作为循环操作数
        {
            len--;
        }
    }
    void print()
    {
        for (int i = len; i >= 1; i--)
        {
            cout << a[i];
        }
    }
};

Bigint operator+(const Bigint &a, const Bigint &b)
{
    Bigint c(0);
    int len = max(a.len, b.len); // c.len 为 c 的实际长度 由结构体自行管理，不应当直接操作，需另外新建变量 len 存储预估长度
    for (int i = 1; i <= len; i++)
    {
        c[i] += a[i] + b[i]; // 注意累加！保留原有进位
    }
    c.flatten(len + 1); // 答案不超过 len + 1 位数
    return c;
}

Bigint operator*(const Bigint &a, const int &b)
{
    Bigint c(0);
    int len = a.len;
    for (int i = 1; i <= len; i++)
    {
        c[i] += a[i] * b; // 注意累加！保留原有进位
    }
    c.flatten(len + 11); // int 类型最长能存储 10 位数
    return c;
}

int main()
{
    Bigint f[5010];
    int N;
    cin >> N;
    f[1] = Bigint(1);
    f[2] = Bigint(2);
    for (int i = 3; i <= N; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }
    f[N].print();
    return 0;
}