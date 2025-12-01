// 如何高效寻找素数
// #素数 #素数筛

#include <bits/stdc++.h>

using namespace std;

// 判断是否质数
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    
    // ! 注意 i * i <= n
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            // 有其他整除因子
            return false;
    return true;
}


// 埃氏素数筛
int countPrimes(int n)
{
    vector<bool> isPrime(n, true); // 将数组都初始化为 true，标记为有可能是质数
    isPrime[0] = false; // 初始化 0 与 1 
    isPrime[1] = false;
    for (int i = 2; i * i < n; i++)
    {
        // ! 注意 不需要调用 isPrime()函数
        if (isPrime[i] == true) 
        {
            // i 的倍数不可能是素数
            for (int j = i * i; j < n; j += i) // 优化，若从 较小的倍数 起乘，则会和前序 较小数的倍数 重复
            {
                isPrime[j] = false;
            }
        }
    }

    int count = 0;
    for (int i = 2; i < n; i++)
    {
        if (isPrime[i])
        {
            count++;
        }
    }

    return count;
}