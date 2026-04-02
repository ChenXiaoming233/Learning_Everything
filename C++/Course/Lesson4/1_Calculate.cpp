#include <iostream>
#include <cmath>
using namespace std;

// 项
class Term
{
public:
    int a;
    int exp;
};

// 多项式
class Poly
{
public:
    Term t[10]; // 项
    int n;      // 项数

    Poly()
    {
        n = 0;
    }

    // 添加项
    void add(int c, int e)
    {
        t[n].a = c;   // 系数
        t[n].exp = e; // 指数
        n++;
    }

    // 计算总值
    double cal(double x)
    {
        double sum = 0;
        for (int i = 0; i < n; i++)
        {
            // 累加
            sum += t[i].a * pow(x, t[i].exp);
        }
        return sum;
    }
};

int main()
{
    double x;
    string s;
    cin >> x >> s;

    Poly p; // 创建多项式对象

    int i = 0;    // 当前读取位置
    int sign = 1; // 当前项的符号，1表示正，-1表示负

    while (i < s.length())
    {
        // 处理符号
        if (s[i] == '+')
        {
            sign = 1;
            i++;
        }
        else if (s[i] == '-')
        {
            sign = -1;
            i++;
        }

        // 读取系数
        int a = 0; // 系数默认为 0
        if (s[i] >= '0' && s[i] <= '9')
        {
            a = 0;
            while (s[i] >= '0' && s[i] <= '9')
            {
                a = a * 10 + (s[i] - '0'); // 将字符转为整数
                i++;
            }
        }
        a *= sign; // 处理正负值

        // 读取指数
        int exp = 1;     // 指数默认为 1
        if (s[i] == 'x') // 如果系数后有 x 未知数则跳过
        {
            i++;
            if (s[i] == '^') // 如果有 ^ 号
            {
                i++;
                exp = 0;
                while (s[i] >= '0' && s[i] <= '9')
                {
                    exp = exp * 10 + (s[i] - '0'); // 读取指数
                    i++;
                }
            }
        }

        // 将该项添加到多项式中
        p.add(a, exp);
    }

    cout << p.cal(x) << endl;

    return 0;
}