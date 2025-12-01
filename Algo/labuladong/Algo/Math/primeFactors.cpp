// 质因数分解
// #√n试除法

#include <bits/stdc++.h>

using namespace std;

// 将 n 分解成若干质因数，按从小到大输出
void factorize(long long n)
{
    // 先处理 2
    while (n % 2 == 0)
    {
        cout << 2 << " ";
        n /= 2;
    }

    // 处理奇数因子
    for (long long i = 3; i * i <= n; i += 2) // 先除掉 2，剩下的 n 是奇数，因子必然也是奇数
    {
        while (n % i == 0)
        {
            cout << i << " ";
            n /= i;
        }
    }

    // 如果剩下的是大质数
    // ! 注意 n > 1 不能省略，n = 1 表示不用输出
    if (n > 1)
        cout << n;
}