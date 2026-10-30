// DSX OJ 排序与选择作业 5.20 老校长皮卡丘
//
// 题意：
//   N 个精灵各有初始技能值，每训练一次技能值 +1。要把 N 个精灵两两配对
//   （保证 N 是偶数），且每队两人的技能值必须相等，求最少的总训练次数。
//
// 思路：
//   技能值只能加不能减，所以排序后两两相邻配对 (a[0],a[1])、(a[2],a[3]) ……
//   总代价就是答案。交换论证：若存在交叉配对 a[i] 配 a[j]、a[k] 配 a[l]
//   （i<k<j<l），改成相邻配对 a[i] 配 a[k]、a[j] 配 a[l] 不会让总代价变大，
//   因此相邻配对一定最优。
//
// 复杂度：时间 O(N log N)（排序），空间 O(N)。

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int answer = 0;
    for (int i = 0; i + 1 < n; i += 2) {
        answer += a[i + 1] - a[i];
    }

    cout << answer << endl;
    return 0;
}
