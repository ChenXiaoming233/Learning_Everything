#include <iostream>
using namespace std;

int main() {
    // 自增与乘法、加法混用
    int a = 5;
    int r1 = a++ * 2 + 3;      // 等价于 (a++) * 2 + 3
    cout << "a++ * 2 + 3 = " << r1 << ", a = " << a << endl;

    a = 5;
    int r2 = a * 2 + 3;        // 先乘后加
    cout << "a * 2 + 3   = " << r2 << ", a = " << a << endl;

    // 前缀自增与加法
    int b = 5;
    int r3 = ++b + 10 * 2;     // 等价于 (++b) + (10 * 2)
    cout << "++b + 10 * 2 = " << r3 << ", b = " << b << endl;

    // 自减与除法、减法混用
    int c = 10;
    int r4 = c-- / 2 - 1;      // 等价于 (c--) / 2 - 1
    cout << "c-- / 2 - 1 = " << r4 << ", c = " << c << endl;

    // 后缀自增与赋值
    int e = 3;
    int f = e++;               // f 得到旧值，e 自增
    cout << "f = e++  => f = " << f << ", e = " << e << endl;

    return 0;
}