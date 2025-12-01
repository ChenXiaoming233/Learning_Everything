// [] 二分答案

#include <bits/stdc++.h>
using namespace std;

long long n, m;
vector<int> trees;

bool P(int h) // 当砍树高度为 h 时，能否得到大于 m 的木材
{
    long long tot = 0;
    for (int i = 0; i < n; i++)
        if (trees[i] > h)
            tot += trees[i] - h; // 模拟题意
    return tot >= m;             
    // 返回当前条件（砍树高度为 h）下 “超额完成” 的情况
    // "<=" -> 尽量大但不超过限制
    // ">=" -> 尽量小但能达到要求    
    // 结果出现偏移可能是判定条件错误
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        trees.push_back(t);
    }
    sort(trees.begin(), trees.end());

    // [] 二分答案模板
    int l = -1, r = trees.back(); // ! 注意 l 与 r 不再是 vector 的左右两端下标，而是最大最小值 **本身**
    int ans = 0;
    while (l + 1 != r)
    {
        int mid = (l + r) / 2;
        if (P(mid)) // 如果 P 为真，**则答案可以为mid**，真正的答案可能在 mid 右侧，左端点右移
            l = mid;
        else // 如果 P 为假，则真正的答案可能在 mid 左侧，右端点左移
            r = mid;
    }

    cout << l;
    return 0;
}
