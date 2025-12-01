// #最大公约数 #最小公倍数
#include <bits/stdc++.h>

using namespace std;

// 最大公约数 欧几里得算法
// 原理: gcd(a, b) = gcd(b, a mod b)
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

// 最小公倍数
// 原理: lcm(a, b) = a * b / gcm(a, b)
int lcm(int a, int b)
{
    return a / gcd(a, b) * b; // 先除后乘避免溢出
}

// 多个数的最大公因数
// 原理: gcd(a, b, c, d, …) = gcd(gcd(gcd(a, b), c), d), …
int gcd_multi(vector<int>& nums) {
    int g = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        g = gcd(g, nums[i]);
    }
    return g;
}

// 多个数的最小公倍数
int lcm_multi(vector<int>& nums) {
    int cur = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        cur = lcm(cur, nums[i]); 
    }
    return cur;
}
