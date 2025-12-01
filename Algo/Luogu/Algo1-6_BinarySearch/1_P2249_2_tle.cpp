#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> nums(n + 1);
    vector<int> qs(m);
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> qs[i];
    }
    vector<int> ans(m);
    for (int i = 0; i < m; i++)
    {
        vector<int>::iterator it = find(nums.begin(), nums.end(), qs[i]);
        if (it == nums.end())
            ans[i] = -1;
        else
            ans[i] = it - nums.begin();
    }
    for (int i = 0; i < m; i++)
    {
        cout << (i == 0 ? "" : " ") << ans[i];
    }
    return 0;
}