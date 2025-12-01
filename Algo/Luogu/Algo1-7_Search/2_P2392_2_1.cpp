// 二叉树子集搜索 (0/1 选择)

#include <bits/stdc++.h>
using namespace std;

int s[4], a[21];
int ans = 0;
int sumAll; // 当前科目所有作业时间之和
int maxA;   // 枚举中 A 能取得的最大合法时间

void dfs(int idx, int now, int n)
{
    if (idx > n)
    {
        maxA = max(maxA, now);
        return;
    }

    if (now + a[idx] <= sumAll / 2)
        dfs(idx + 1, now + a[idx], n);
    dfs(idx + 1, now, n);
}

int main()
{
    cin >> s[0] >> s[1] >> s[2] >> s[3];
    for (int i = 0; i < 4; i++)
    {
        sumAll = 0;
        for (int j = 1; j <= s[i]; j++)
        {
            cin >> a[j];
            sumAll += a[j];
        }
        maxA = 0;
        dfs(1, 0, s[i]);
        ans += (sumAll - maxA); // sumAll - maxA 是另一半的时间
    }

    cout << ans;
    return 0;
}
