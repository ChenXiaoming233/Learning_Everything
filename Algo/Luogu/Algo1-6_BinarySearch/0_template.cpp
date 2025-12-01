#include <bits/stdc++.h>

using namespace std;

int binary(int p, vector<int> &nums)
{
    int l = -1, r = nums.size(); // l 为已知可行值，r 为已知不可行值
    // ! 注意某些情况（涉及除法）下 m 为 0 会导致错误，l 应从 0 开始
    while (l + 1 != r)
    {
        int m = (l + r) / 2;
        if (m < p) // isBlue 条件
            l = m;
        else
            r = m;
    }
    return l; // 返回 l 或 r
}
// (isBlue == < p, return r) -> >= p
// (isBlue == < p, return l) -> < p
// (isBlue == <= p, return r) -> > p
// (isBlue == <= p, return l) -> <= p
// is Blue == > p 或 is Blue == >= p 时翻转 l 与 r （求最大可行值）

int main()
{
    vector<int> nums = {1, 3, 2, 5, 5, 9, 8};
    sort(nums.begin(), nums.end());
    int m = binary(5, nums);
    cout << m;
}