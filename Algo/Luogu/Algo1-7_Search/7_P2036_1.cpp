#include <bits/stdc++.h>

using namespace std;

int n;
int ans = INT_MAX;
int s[15], b[15];

void dfs(int idx, int p, int q)
{
    if (idx > n)
    {
        if (p == 1 and q == 0)
            return;
        ans = min(abs(p - q), ans);
        return;
    }

    dfs(idx + 1, p * s[idx], q + b[idx]);
    dfs(idx + 1, p, q);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i] >> b[i];
    }
    dfs(1, 1, 0);
    cout << ans;
}