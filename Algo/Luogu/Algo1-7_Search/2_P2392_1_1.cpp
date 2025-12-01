// 0/1 背包问题（双背包平衡）；无法使用贪心，不满足贪心选择性质，**是否选择某个元素依赖于未来能否组合出更优的子集，当前 “放或不放” 并非独立决策**，若干较小元素的组合可以比单个较大元素更接近目标值

#include <bits/stdc++.h>

using namespace std;

int nowtime, maxtime, sum; // 子集的时间和，最大合法时间和，总时长
int ans, maxdeep;          // 答案，递归层数限制（作业数量）
int s[4], a[21];          

void dfs(int x)
{
    if (x > maxdeep)
    {
        maxtime = max(maxtime, nowtime);
        return;
    }
    if (nowtime + a[x] <= sum / 2)
    {
        nowtime += a[x]; // 若放入该作业是合法的，则放入
        dfs(x + 1);
        nowtime -= a[x];
    }
    dfs(x + 1); // 若放入该作业是不合法的，直接跳过进入下一层
}

int main()
{
    cin >> s[0] >> s[1] >> s[2] >> s[3];
    for (int i = 0; i < 4; i++) // 没必要一次录入所有数据
    {
        nowtime = 0; // ! 注意 不要忘记每次输入都要初始化！
        maxtime = 0;
        maxdeep = s[i];
        sum = 0;
        for (int j = 1; j <= s[i]; j++)
        {
            cin >> a[j];
            sum += a[j];
        }
        dfs(1);
        ans += (sum - maxtime);
    }
    cout << ans;
    return 0;
}