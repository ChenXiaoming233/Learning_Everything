// ^ 一种贪心思路：每一个纪念品都必须在一个组中。假设我们现在想给 i 分组，那么我们一定是找最大的 j 满足条件。如果不是找的最大的 j, 那么就会导致剩下的纪念品中有一个较小的被换成了较大的，一定不优。

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w, n;
    int ans = 0;
    cin >> w >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++)
        cin >> prices[i];
    sort(prices.begin(), prices.end());
    int l, r;
    l = 0;
    r = n - 1;
    while (l <= r)
    {
        if (prices[l] + prices[r] <= w)
            l++, r--, ans++;
        else
            r--, ans++;
    }
    cout << ans;
    return 0;
}
