#include <bits/stdc++.h>

using namespace std;

int n, k;
int ans = 0;
int a[21];

bool isPrime(int x)
{
    if (x == 1)
        return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}

void dfs(int now, int sum, int idx)
{
    if (now >= k)
    {
        if (isPrime(sum))
            ans++;
        return;
    }
    if (n - idx + 1 < k - now)
        return;
    dfs(now + 1, sum + a[idx], idx + 1);
    dfs(now, sum, idx + 1);
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dfs(0, 0, 1);
    cout << ans;
    return 0;
}