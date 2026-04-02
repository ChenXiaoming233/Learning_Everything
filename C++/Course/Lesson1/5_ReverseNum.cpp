#include <iostream>
using namespace std;

int main()
{
    int num = 0, result = 0;
    bool plus = true;
    cin >> num;
    if (num < 0) // 标记负数
    {
        num = -num;
        plus = false;
    }
    while (num > 0)
    {
        int n = num % 10;         // 取出最后一位
        result = result * 10 + n; // 合成新数
        num = num / 10;           // 去除最后一位
    }
    if (plus == false) // 处理负数
        result = -result;
    cout << result;
    return 0;
}