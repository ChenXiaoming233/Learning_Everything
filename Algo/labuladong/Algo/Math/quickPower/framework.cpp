// 快速幂

#include <iostream>
using namespace std;
typedef long long ll;

// 计算 base^exponent % mod
ll quickPow(ll base, ll exponent, ll mod)
{
    ll result = 1; // 初始化结果为 1

    // ! 注意
    base %= mod;

    while (exponent > 0)
    {
        // 如果 **二进制下** 指数最低位为 1
        if (exponent % 2 == 1)
        {
            result = (result * base) % mod;
        }

        // 指数右移一位，去除已处理的二进制低位（相当于除以2）
        exponent /= 2;

        // 对应下一位指数的幂
        base = (base * base) % mod;
    }

    return result;
}

int main()
{
    ll base, exponent, mod;
    cin >> base >> exponent >> mod;

    ll ans = quickPow(base, exponent, mod);
    cout << ans << endl;

    return 0;
}