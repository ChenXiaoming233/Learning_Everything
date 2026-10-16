// DSX OJ 排序与选择作业 5.21 数学家皮卡丘
//
// 题意：
//   给定非降序数组 a[1..n] 和正整数 k，把它切成 k 段非空的连续子数组，
//   记第 i 段的最大值 max(i)、最小值 min(i)，求 sum(max(i) - min(i)) 的最小值。
//
// 思路：
//   数组有序，所以每段的 max-min 就是 a[右端点] - a[左端点]。把数组切成 k 段，
//   等价于在 n-1 个相邻位置里丢掉 k-1 个切口，每丢一个切口就省掉对应的相邻差：
//       sum(max-min) = (a[n]-a[1]) - (丢掉的那 k-1 个相邻差之和)
//   所以让丢掉的相邻差尽量大：把相邻差从大到小排序，取前 k-1 个，从总跨度
//   a[n]-a[1] 中减掉即可。k=1 时答案是 a[n]-a[1]，k=n 时是 0。
//
// 复杂度：时间 O(n log n)，空间 O(n)。

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    vector<long long> gaps;
    for (int i = 1; i < n; i++) {
        gaps.push_back(a[i] - a[i - 1]);
    }
    sort(gaps.begin(), gaps.end(), greater<long long>());

    long long answer = a[n - 1] - a[0];
    for (int i = 0; i < k - 1 && i < (int)gaps.size(); i++) {
        answer -= gaps[i];
    }

    cout << answer << endl;
    return 0;
}
