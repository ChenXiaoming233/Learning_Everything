#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct coin
{
    int m, v;
} coins[100];

bool cmp(coin x, coin y)
{
    return x.v * y.m > x.m * y.v;
}

int main()
{
    int n, t, restM, i;
    cin >> n >> t;
    float totalV = 0;
    restM = t;
    for (i = 0; i < n; i++)
    {
        cin >> coins[i].m >> coins[i].v;
    }
    sort(coins, coins + n, cmp);
    for (i = 0; i < n; i++)
    {
        if (restM < coins[i].m)
        {
            break;
        }
        else
        {
            restM -= coins[i].m;
            totalV += coins[i].v;
        }
    }
    if (i < n)
    {
        totalV += 1.0 * restM / coins[i].m * coins[i].v;
    }
    printf("%.2lf", totalV);
    return 0;
}