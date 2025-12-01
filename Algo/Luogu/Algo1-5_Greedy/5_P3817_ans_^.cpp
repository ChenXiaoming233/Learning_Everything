// 最优策略是尽量减少右边盒子的糖果，这样不会影响前面已经处理好的对

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    long long x;
    cin >> n >> x;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    long long ans = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        long long sum = a[i] + a[i + 1]; // 变量存储好习惯
        if (sum > x)
        {
            long long excess = sum - x;
            ans += excess;      // !注意 a[i + 1] 后续会变化 先统再变好习惯
            a[i + 1] -= excess; // 减少右侧的糖果数量，避免干扰
            if (a[i + 1] < 0)
                a[i + 1] = 0;
            // count += box[i]; 负数情况下多扣的糖果无需补回来，因为例如 (5,-1) 的情况应当是 (4,0), 但是贪心算法简化操作只调整了右侧的数值以保证下一次计算的正确性，总计需要扣除的糖果数不变
        }
    }

    cout << ans << "\n";
    return 0;
}
