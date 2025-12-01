#include <bits/stdc++.h>

using namespace std;

int n;
int s[15], b[15];
int ans = INT_MAX;

void dfs(int i, int p, int q) // 位置状态与依赖状态相同
{
    if (i > n)
    {
        if (p == 1 and q == 0) // !注意 排除一种配料都不加的情况
            return;
        ans = min(abs(p - q), ans); // !注意 ans应该更新为更小值，所以应该
        return;
    }
    dfs(i + 1, p * s[i], q + b[i]);
    dfs(i + 1, p, q);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i] >> b[i];
    dfs(1, 1, 0); // p 初始若设为 1 则
    cout << ans;
    return 0;
}