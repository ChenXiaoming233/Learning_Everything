// DSX OJ 队列作业 4.19 优质的随从慕名而来
//
// 题意：
//   n 个随从按顺序被买下，队伍容量为 m，且淘汰规则是先进先出：
//   当新买的随从无法加入队伍时，卖掉队伍中最早买下的那个。
//   买下种类为 x 的随从时，若队伍里已经有 2 个 x，则触发“三连”：
//   队中那 2 个 x 被移除，新买的这个 x 变成“金色”并被立刻卖掉（不留在队中），
//   计入一次答案。求最终卖掉的“金色”随从数量。
//
// 思路：
//   用一个双向链表维护队伍，既能 O(1) 弹出队首，也能 O(1) 摘掉中间任意结点。
//   另外为每种随从记录它在链表中的结点编号；因为同一时刻每种随从最多存在 2 个
//   （一旦凑够 2 个，下次再买就会三连清空），所以每种保存 2 个槽位即可。
//
//   处理第 i 个随从 x：
//     1) 若 cnt[x] == 2，先摘掉这两个结点（队伍变小，不需要淘汰队首），答案 +1；
//     2) 否则，若队伍已满 m，则弹出队首并更新被弹出元素的种类计数，再把新结点接到队尾。
//
//   关键点：三连判定必须发生在容量淘汰之前。若先按“满员”淘汰队首，
//   在队首恰好是 x 的情况下会把 count 降为 1，三连就不会触发，答案会偏小。
//
// 复杂度：时间 O(n)，空间 O(n + maxA)。

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    const int MAXV = 1000001;
    vector<int> cnt(MAXV, 0);   // 该种类当前在队伍中的个数（0/1/2）
    vector<int> s1(MAXV, -1);   // 该种类在链表中第 1 个结点的编号，-1 表示没有
    vector<int> s2(MAXV, -1);   // 该种类在链表中第 2 个结点的编号

    // 手写双向链表：结点编号 0..nodeCnt-1，head/tail 为队首/队尾
    vector<int> val(n + 1, 0), nxt(n + 1, -1), prv(n + 1, -1);
    int head = -1, tail = -1, sz = 0, nodeCnt = 0;
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        int x;
        if (scanf("%d", &x) != 1) break;

        if (cnt[x] == 2) {
            // 三连：把队伍里的两个 x 都摘掉
            int a = s1[x], b = s2[x];
            int pa = prv[a], na = nxt[a];
            if (pa != -1) nxt[pa] = na; else head = na;
            if (na != -1) prv[na] = pa; else tail = pa;
            sz--;
            // 先摘 a 再读 b 的前驱后继，保证相邻时指针依然正确
            int pb = prv[b], nb = nxt[b];
            if (pb != -1) nxt[pb] = nb; else head = nb;
            if (nb != -1) prv[nb] = pb; else tail = pb;
            sz--;
            cnt[x] = 0;
            s1[x] = -1;
            s2[x] = -1;
            ans++;
        } else {
            if (sz == m) {
                // 队伍已满：卖掉最早买下的（队首）
                int f = head;
                int fv = val[f];
                int nf = nxt[f];
                head = nf;
                if (nf != -1) prv[nf] = -1; else tail = -1;
                sz--;
                cnt[fv]--;
                if (s1[fv] == f) { s1[fv] = s2[fv]; s2[fv] = -1; }
                else { s2[fv] = -1; }
            }
            // 新随从加入队尾
            int id = nodeCnt++;
            val[id] = x;
            prv[id] = tail;
            nxt[id] = -1;
            if (tail != -1) nxt[tail] = id; else head = id;
            tail = id;
            sz++;
            cnt[x]++;
            if (s1[x] == -1) s1[x] = id; else s2[x] = id;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
