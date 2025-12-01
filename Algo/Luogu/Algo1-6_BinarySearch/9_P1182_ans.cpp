#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> nums;

bool can(int x)
{
    int count = 1;
    int tot = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > x) // 检查单个元素过大
            return false;
        if (tot + nums[i] <= x)
            tot += nums[i];
        else
        {
            count++;
            tot = nums[i];
        }
    }
    return count <= m;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        nums.push_back(t);
    }

    int left = 0, right = accumulate(nums.begin(), nums.end(), 0);
    while (left + 1 != right)
    {
        int mid = (left + right) / 2;
        if (can(mid))
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
    }
    cout << right;
    return 0;
}