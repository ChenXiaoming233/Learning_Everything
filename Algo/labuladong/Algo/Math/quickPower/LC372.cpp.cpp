// LeetCode372 - 超级平方
// #快速幂 #取模 #数组指数 #递归

#include <bits/stdc++.h>

using namespace std;

int base = 1337;

// 计算 a 的 k 次方与 base 求模的结果
int myPow_base(int a, int k)
{ // a 为底数，k 为指数
    a %= base;
    int res = 1;
    for (int i = 0; i < k; i++)
    {
        // ! 注意 乘法是潜在的溢出点
        res *= a;
        res %= base; // 每次循环都对结果求模
    }
    return res; // 返回值为 ((a ^ k) % k)
}
// # 模运算技巧: (a * b) % k = (a % k) * (b % k) % k


// 快速幂算法
int myPow(int a, int k)
{
    if (k == 0)
        return 1;

    // 每一步都对结果取模，防止溢出
    a %= base; 

    if (k % 2 == 1) // k 是奇数
    {
        return (a * myPow(a, k - 1)) % base;
    }
    else // k 是偶数
    {
        int sub = myPow(a, k / 2);
        return (sub * sub) % base;
    }
}


int superPow(int a, vector<int> &b)
{
    if (b.empty())
    {
        return 1;
    }
    int last = b.back();
    b.pop_back();
    int part1 = myPow(a, last);
    int part2 = myPow(superPow(a, b), 10);
    return (part1 * part2) % base; // (part1 * part2) 只是 a^[b] 的结果，还需要最后取模一次
}
// # 处理数组指数：a ^ [1,5,6,4] = (a ^ 4) * (a ^ [1,5,6] ^ 10)