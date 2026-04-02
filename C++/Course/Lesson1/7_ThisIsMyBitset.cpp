#include <iostream>
using namespace std;

int twoToTen(int two)
{
    int ten = 0; // 十进制结果
    int x = 1;   // 当前 2 的幂次
    while (two > 0)
    {
        int lastTwo = two % 10;  // 二进制最后一位
        ten = ten + lastTwo * x; // 合成十进制
        two = two / 10;          // 二进制去掉最后一位
        x = x * 2;               // 增加当前幂次
    }
    return ten;
}

int main()
{
    int two;
    cin >> two;
    int result = twoToTen(two);
    cout << result;
    return 0;
}