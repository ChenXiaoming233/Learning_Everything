#include <bits/stdc++.h>
using namespace std;
unsigned long long ans = 0;
int h[330];
bool sum = 0;
signed main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    sort(h + 1, h + n + 1);
    int j = 0, hpast = 0;
    for (int i = 1; i <= n; i++)
    {
        j = n - j + sum;
        sum = !sum;
        ans += (h[j] - hpast) * (h[j] - hpast);
        hpast = h[j];
    }
    cout << ans;
    return 0;
}
