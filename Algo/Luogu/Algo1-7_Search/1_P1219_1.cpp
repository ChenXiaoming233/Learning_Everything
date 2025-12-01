#include <bits/stdc++.h>

using namespace std;

#define MAXN 100

int n = 0, ans = 0;

int a[MAXN], b1[MAXN], b2[MAXN], b3[MAXN];

void dfs(int x)
{
    if (x > n)
    {
        ans++;
        if (ans <= 3)
        {
            for (int i = 1; i <= n; i++)
                cout << (i == 1 ? "" : " ") << (a[i]);
            cout << endl;
        }
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (b1[i] == 0 and b2[x + i] == 0 and b3[x - i + n] == 0)
        {
            a[x] = i;
            b1[i] = 1;
            b2[x + i] = 1;
            b3[x - i + n] = 1;
            dfs(x + 1);
            b1[i] = 0;
            b2[x + i] = 0;
            b3[x - i + n] = 0;
        }
    }
}

int main()
{
    cin >> n;
    dfs(1);
    cout << ans;
    return 0;
}