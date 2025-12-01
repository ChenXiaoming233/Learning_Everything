
// “如果每次要求每次跳跃都有 d >= x, 通过删掉 x 块石头能否做到？”

#include <bits/stdc++.h>

using namespace std;

int l, n, m;
vector<int> stones;

// [] 一种条件的模板
bool can(int x)
{
    int cnt = 0;  // 移除的石头数
    int last = 0; // 上一个保留的石头位置
    for (int i = 0; i < n; i++)
    {
        if (stones[i] - last < x)
            cnt++;
        else
            last = stones[i];
    }
    return cnt <= m;
    // 需要移除的石头数 <= 允许移除的石头数，说明在当前条件（保证最短距离为 x ）下这是 “可行” 的情况，而此时 x 相对于 xp 可以更小，以令需要移除的石头数接近允许移除的石头数，即 x <= xp
}

int main()
{
    cin >> l >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        stones.push_back(t);
    }
    stones.push_back(l);
    n++;
    sort(stones.begin(), stones.end());

    int left = 0, right = l + 1, ans = 0;
    while (left + 1 != right)
    {
        int mid = (left + right) / 2;
        if (can(mid)) // 等价于 x <= xp
            left = mid;
        else
            right = mid;
    }
    cout << left;

    /*
    ! 注意若 can(mid) 等价于 x >= x, 则应翻转 left 与 right (8_P3853):
    while (left + 1 != right)
    {
        int mid = (left + right) / 2;
        if (can(mid)) // 等价于 x >= xp
            right = mid;
        else
            left = mid;
    }
    cout << right;
    */
}