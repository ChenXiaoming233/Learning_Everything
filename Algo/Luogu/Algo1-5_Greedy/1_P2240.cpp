#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct coin
{
    int m, v;
} coins[110];

bool cmp(coin x, coin y)
{
    return x.v * y.m > y.v * x.m;
}

int main()
{
    int n, t, c, i;
    float ans = 0;
    cin >> n >> t;
    c = t;
    for (i = 0; i < n; i++)
    {
        cin >> coins[i].m >> coins[i].v;
    }
    sort(coins, coins + n, cmp);
    for (i = 0; i < n; i++) // 若循环完整结束后共执行 n 次 (0 至 n - 1), **此时 i == n**
    {
        if (coins[i].m > c)
        {
            break;
            // break 跳出循环，由下方的 if 判定来尽可能多地向背包中装入 [i] 堆的物体
        }
        c -= coins[i].m;
        ans += coins[i].v;
    }
    if (i < n) // 防止 coins[i] 越界
    {
        ans += 1.0 * c / coins[i].m * coins[i].v;
        // ! 不能去掉 1.0! 1.0 将整数运算转换为浮点运算，否则后续 c / coins[i].m 会以整数除法而非浮点除法进行，导致小数部分被截断
    }
    printf("%.2lf", ans);
    return 0;
}