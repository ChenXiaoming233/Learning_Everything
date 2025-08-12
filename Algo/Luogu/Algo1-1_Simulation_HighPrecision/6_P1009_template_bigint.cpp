#include <iostream>
#include <cstring>
#define maxn 100

using namespace std;

struct Bigint
{
    int len, a[maxn];
    Bigint(int x = 0)
    {                            // 构造函数
        memset(a, 0, sizeof(a)); // 重置数组 a[maxn] 为 0；
        for (len = 1; x; len++)
        {
            a[len] = x % 10; // 提取每位数字进入数组
            x /= 10;         // 去除已经取出的一位数
        }
        len--; // 修正最后一次多余的 len++
    }
    int &operator[](int i)
    { // 下标运算符重载，可以像访问数组一样访问 x[] 而无需使用 x.a[]
        return a[i];
    }
    void flatten(int L)
    { // 在大数计算后，归位进位且去除多余前导0
        len = L;
        for (int i = 1; i < len; i++)
        {
            a[i + 1] += a[i] / 10; // 将 a[i] 高于个位的值进位至 a[i + 1]
            a[i] %= 10;            // 保留 a[i] 个位
        }
        while (len > 1 and a[len] == 0)
        { // 去除前导0 但至少保留一位数
            len--;
        }
    }
    void print()
    {
        for (int i = max(len, 1); i >= 1; i--)
        {
            cout << a[i];
        }
    }
};

Bigint operator+(Bigint a, Bigint b)
{
    Bigint c;
    int len = max(a.len, b.len);
    for (int i = 1; i <= len; i++)
    {
        c[i] += a[i] + b[i];
    }
    c.flatten(len + 1); // 答案不超过 len + 1 位数
    return c;
}

Bigint operator*(Bigint a, int b)
{
    Bigint c;
    int len = a.len;
    for (int i = 1; i <= len; i++)
    {
        c[i] = a[i] * b;
    }
    c.flatten(len + 11); // int 类型最长能存储 10 位数
    return c;
}

int main()
{
    Bigint ans(0), fac(1); // 分别用 0 与 1 初始化 ans 与
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        fac = fac * i;
        ans = ans + fac; // ans1 和 ans2 是 Bigint 类型，编译器会自动选择定义的 operator+
    }
    ans.print();
}