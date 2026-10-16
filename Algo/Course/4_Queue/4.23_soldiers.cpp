// DSX OJ 队列作业 4.23 soldiers（4.1 士兵队列训练问题）
//
// 题意：
//   n 名新兵按 1..n 编号排成一行。反复执行：
//     从头开始“一至二报数”，报到 2 的出列，剩下的向小序号方向靠拢；
//     再从头开始“一至三报数”，报到 3 的出列，剩下的靠拢；
//     之后不断在“一至二”和“一至三”之间轮流，直到剩下的人数不超过 3 为止。
//   输出剩下新兵最初的编号。多组数据，每组一行。
//
// 思路：
//   题目主题就是队列，直接用一个队列模拟：
//   一轮开始时先记下本轮人数 sz（因为循环中会不停 pop/push，不能边做边取 size），
//   然后做 sz 次“取队首”：报数 cnt 加一，若 cnt 等于本轮的数 k 则该人出列（丢弃），
//   否则把它重新压回队尾。一轮结束后 k 在 2 和 3 之间切换。
//   人数不足或已剩 3 人以内时结束，最后顺序输出队列内容。
//
// 复杂度：人数不超过 5000，每轮至少淘汰一批人，时间 O(n log n) 级别，空间 O(n)。

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--) {
        int n;
        if (scanf("%d", &n) != 1) break;

        queue<int> q;
        for (int i = 1; i <= n; i++) q.push(i);

        int k = 2; // 先“一至二报数”，然后 3、2、3……轮流
        while ((int)q.size() > 3) {
            int sz = (int)q.size(); // 本轮要处理的固定人数
            int cnt = 0;            // 当前报到几
            for (int i = 0; i < sz; i++) {
                int v = q.front();
                q.pop();
                cnt++;
                if (cnt == k) cnt = 0; // 报到 k，出列
                else q.push(v);        // 否则排到队尾，等待下一轮
            }
            k = (k == 2) ? 3 : 2;
        }

        // 剩下不超过 3 人，按原编号顺序输出
        bool first = true;
        while (!q.empty()) {
            if (!first) printf(" ");
            first = false;
            printf("%d", q.front());
            q.pop();
        }
        printf("\n");
    }
    return 0;
}
