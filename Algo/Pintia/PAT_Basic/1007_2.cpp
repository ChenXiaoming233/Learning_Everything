#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#define MAX 100005

using namespace std;

int a[MAX];
void Sifting()
{
    a[0] = a[1] = 1;
    int sq = sqrt(MAX) + 1;
    for (int i = 2; i <= sq and i < MAX; i++)
    {
        if (a[i] == 0)
        {
            for (int j = i * i; j < MAX; j += i)
            {
                a[j] = 1;
            }
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
        for (int j = 0; j < prime.size() and i * prime[j] < MAX; j++)
        {
            b[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}

int main()
{
    return 0;
}