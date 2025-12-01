// 素数筛

#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

#define MAX 100005

using namespace std;

int a[MAX];
void Sifting() // []埃氏素数筛
{
    a[0] = a[1] = 1;
    int sq = sqrt(MAX) + 1; // 避免浮点数取整问题
    for (int i = 2; i <= sq; i++)
    {
        if (a[i] == 0)
            for (int j = i * i; j < MAX; j += i) // 将素数的所有倍数都标记为合数, 从 i 的 i 倍数开始更高效，更小的数都被之前更小的素数筛过了
                a[j] = 1;
    }
}
// 对于埃氏筛法，例如 120 = 2 * 2 * 2 * 3 * 5, 会在遍历到 2, 3, 5 时被重复处理

int b[MAX];
vector<int> prime;
void EulerSieve() // []欧拉素数筛
{
    b[0] = b[1] = true;
    for (int i = 2; i < MAX; i++) // 欧拉筛必须完整遍历，因为每个合数需要被它的最小质因数处理
    {
        if (b[i] = 0)
            prime.push_back(i);
        for (int j = 0; j < prime.size() && i * prime[j] < MAX; j++) // 遍历已经找到的素数；同时防止越界，保证要标记的 i 与素数 prime[j] 的乘积也在限定范围内
        {
            b[i * prime[j]] = 1; // 将所有已知的素数与 i 相乘，乘积标记为合数，
            if (i % prime[j] == 0)
                break; // 保证每个合数只被最小素因数标记一次
        }
    }
}

int main()
{
    Sifting();
    int n;
    cin >> n;
    int sum = 3, num = 0;
    for (int i = 0; i <= n; i++) // i = n 取等，n 本身可能也是质数
    {
        if (a[i] == 0)
        {
            if (i - sum == 2)
                // m = i; // ×
                num++;
            sum = i; // 在每次遇到素数时都更新，而非只在发现孪生素数时才更新
        }
    }
    cout << num << endl;
    return 0;
}