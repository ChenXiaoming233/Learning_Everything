// 贪心无法解决

#include <bits/stdc++.h>
using namespace std;

// 贪心策略：将每科题目按耗时从大到小排序，
// 依次加入总和不超过 sum/2 的集合，以尽可能接近 sum/2。
// 最终的科目总耗时 = max(子集和, 总和 - 子集和)

int greedyHalfTime(vector<int> v)
{
    sort(v.begin(), v.end(), greater<int>()); // 从大到小排序
    int sum = accumulate(v.begin(), v.end(), 0);
    int now = 0;

    for (int t : v)
    {
        if (now + t <= sum / 2)
            now += t; // 尽可能接近 sum/2
    }

    // 左右脑同时进行，取两边中较大的时间为该科耗时
    return max(now, sum - now);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> subjects(4);
    for (int i = 0; i < 4; i++)
    {
        int s;
        cin >> s;
        subjects[i].resize(s);
    }

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < subjects[i].size(); j++)
            cin >> subjects[i][j];

    int totalTime = 0;
    for (auto &sub : subjects)
        totalTime += greedyHalfTime(sub);

    cout << totalTime << "\n";
    return 0;
}
