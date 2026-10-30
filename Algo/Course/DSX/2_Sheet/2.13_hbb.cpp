/*
 * 题目来源：DSX OJ《算法与数据结构实验题 2.13 汉堡包》
 * 语言：C++（按 C++17 标准编译验证）
 *
 * 题目大意：
 *   按顺序处理 n 条操作，最后输出自底向上的汉犇犇编号，数字之间用空格隔开，
 *   行末无空格、无换行；如果汉犇犇被吃光了，则输出 0。
 *   - 1 a：新增一个汉犇犇（第 k 个新增的编号就是 k），插到编号 a 的上面；
 *          如果编号 a 不存在（没出现过或已经被吃掉），就放到最上面。
 *   - 2 a b：从编号 a 开始往上连续吃掉 b 个（含 a 自己）；如果编号 a 不存在，
 *            就从最底下开始；如果不足 b 个，就吃到顶结束。
 *
 * 解题思路：
 *   每个汉犇犇看作链表上的一个结点，编号就是结点编号。
 *   用 before[i] / after[i] 记录结点 i下面和上面的邻居，
 *   bottom / top 记录最底下和最上面的结点，alive[i] 记录结点 i 是否还活着。
 *
 *   - 插入：新结点编号就是新增序号 node。先判断 a 是否活着：
 *     活着就接到 a 的上面（如果 a 原本是最上面的结点，还要更新 top）；
 *     否则接到 top 的上面（空表时同时更新 bottom 和 top）。
 *   - 吃掉：如果 a 活着则从 a 开始，否则从 bottom 开始；
 *     从起点往上一共找 b 个结点，不够就停在顶。记下区间左右两侧的结点，
 *     把区间内的结点逐个标记为不存活，再把左右两侧接起来。
 *
 *   每个结点最多被插入一次、被删除一次，所以总时间是 O(n)。
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(n)，n <= 100000。
 */

#include <iostream>
using namespace std;

int before[100005];  // before[i]：结点 i 下面的那个结点，0 表示没有
int after[100005];   // after[i]：结点 i 上面的那个结点，0 表示没有
bool alive[100005];  // alive[i]：结点 i 是否还在（是否已被吃掉）

int main() {
    int n;
    cin >> n;

    int bottom = 0;  // 最底下的结点，0 表示当前没有结点
    int top = 0;     // 最上面的结点
    int total = 0;   // 已经新增过的结点数量，也就是当前最新编号

    for (int i = 0; i < n; i++) {
        int op;
        cin >> op;

        if (op == 1) {
            int a;
            cin >> a;

            total++;
            int node = total;
            alive[node] = true;
            before[node] = 0;
            after[node] = 0;

            if (a >= 1 && a <= n && alive[a]) {
                // 编号 a 存在：插到 a 的上面
                before[node] = a;
                after[node] = after[a];
                if (after[a] != 0) {
                    before[after[a]] = node;
                } else {
                    top = node;  // a 原本就是最上面的结点
                }
                after[a] = node;
            } else {
                // 编号 a 不存在：放到最上面
                if (top == 0) {
                    bottom = node;
                    top = node;
                } else {
                    before[node] = top;
                    after[top] = node;
                    top = node;
                }
            }
        } else if (op == 2) {
            int a, b;
            cin >> a >> b;

            if (bottom == 0) {
                continue;  // 已经被吃光，什么都不用做
            }

            int start;
            if (a >= 1 && a <= n && alive[a]) {
                start = a;
            } else {
                start = bottom;
            }

            // 从 start 往上一共数 b 个结点，不够就停在最上面
            int end = start;
            int nextNode = after[start];
            int removed = 1;
            while (nextNode != 0 && removed < b) {
                end = nextNode;
                nextNode = after[nextNode];
                removed++;
            }

            int leftPart = before[start];  // 被吃掉区间的下面一个结点
            int rightPart = after[end];    // 被吃掉区间的上面一个结点

            int cur = start;
            for (int j = 0; j < removed; j++) {
                int following = after[cur];
                alive[cur] = false;
                cur = following;
            }

            if (leftPart == 0) {
                bottom = rightPart;
            } else {
                after[leftPart] = rightPart;
            }

            if (rightPart == 0) {
                top = leftPart;
            } else {
                before[rightPart] = leftPart;
            }
        }
    }

    if (bottom == 0) {
        cout << 0;
    } else {
        int cur = bottom;
        bool first = true;
        while (cur != 0) {
            if (!first) {
                cout << " ";
            }
            cout << cur;
            first = false;
            cur = after[cur];
        }
    }

    return 0;
}
