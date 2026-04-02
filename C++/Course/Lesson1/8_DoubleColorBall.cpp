#include <iostream>
using namespace std;

long long int getC(int n, int k) // 计算组合数
{
    long long int result = 1;
    for (int i = 1; i <= k; i++)
        result = result * (n - i + 1) / i;
    return result;
}

double getP(int prize) // 计算奖项可能性
{
    long long totalWay = getC(33, 6) * 16; // 所有可能性
    long long way = 0;
    if (prize == 1)
        way = getC(6, 6) * getC(27, 0) * 1;
    else if (prize == 2)
        way = getC(6, 6) * getC(27, 0) * 15; // 排除一等奖后的15个蓝球
    else if (prize == 3)
        way = getC(6, 5) * getC(27, 1) * 1;
    else if (prize == 4)
    {
        long long case1 = getC(6, 5) * getC(27, 1) * 15;
        long long case2 = getC(6, 4) * getC(27, 2) * 1;
        way = case1 + case2;
    }
    else if (prize == 5)
    {
        long long case1 = getC(6, 4) * getC(27, 2) * 15;
        long long case2 = getC(6, 3) * getC(27, 3) * 1;
        way = case1 + case2;
    }
    else
    {
        long long case1 = getC(6, 2) * getC(27, 4) * 1;
        long long case2 = getC(6, 1) * getC(27, 5) * 1;
        long long case3 = getC(6, 0) * getC(27, 6) * 1;
        way = case1 + case2 + case3;
    }
    double p = way * 1.0 / totalWay;
    return p;
}

int main()
{
    int prize;
    cin >> prize;
    double result = getP(prize);
    cout << result;
    return 0;
}