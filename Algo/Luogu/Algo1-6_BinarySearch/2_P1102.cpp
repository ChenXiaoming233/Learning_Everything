#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, c, t;
    long long ans = 0;
    cin >> n >> c;
    vector<int> nums;
    for (int i = 0; i < n; i++)
        cin >> t, nums.push_back(t);
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
        ans += upper_bound(nums.begin(), nums.end(), nums[i] + c) - lower_bound(nums.begin(), nums.end(), nums[i] + c);
    // 查找对于每一个 b, 有多少个 a == b + c 满足要求；若找不到满足条件的 a，则两者均返回 nums.end() 相减得 0
    cout << ans;
    return 0;
}