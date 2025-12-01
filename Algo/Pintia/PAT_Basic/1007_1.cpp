#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>

#define MAX 100005

using namespace std;

int a[MAX];
void Sifting()
{
    a[0] = a[1] = 1;
    int sq = sqrt(MAX);
    for (int i = 2; i < sq + 1 && i < MAX; i++)
    {
        if (a[i] == 0)
            for (int j = i * i; j < MAX; j += i)
            {
                a[j] = 1;
            }
    }
}

int b[MAX];
vector<int> prime;
void EulerSieve()
{
    b[0] = b[1] = 1;
    for (int i = 2; i < MAX; i++)
    {
        if (b[i] == 0)
        {
            prime.push_back(i);
        }
        for (int j = 0; j < prime.size() && i * prime[j] < MAX; j++)
        {
            b[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}

int main()
{
    EulerSieve();
    int m = 3, num = 0;
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) // i = n 取等，n 本身可能也是质数
    {
        if (b[i] == 0)
        {
            if (i - m == 2)
                // m = i; // ×
                num++;
            m = i; // 在每次遇到素数时都更新，而非只在发现孪生素数时才更新
        }
    }
    cout << num;
    return 0;
}