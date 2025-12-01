#include <bits/stdc++.h>

using namespace std;

#define maxn 100

int ans = 0, n = 0;
int a[maxn], b1[maxn], b2[maxn], b3[maxn];

void dfs(int x) // x 为每一行的序号（当前递归层数），每行仅有一个皇后，故可将最小颗粒度定为单行
{
    if (x > n) // 终止条件为 **超过** 最大层数
    {
        ans++; // 更新答案
        if (ans <= 3)
        {
            for (int i = 1; i <= n; i++)
                cout << (i == 1 ? "" : " ") << a[i];
            cout << endl;
        }
        return;
    }
    for (int i = 1; i <= n; i++) // i 为 **每一列** 的序号
    {
        // [] 标记对角线点
        if (b1[i] == 0 and b2[x + i] == 0 and b3[x - i + n] == 0) // ! 注意 下标数不是格子的序号！
        // 同在一条左斜线上的点都满足 x - i = 相同的常数，同在一条右斜线上的点都满足 x + i = 相同的常数
        {
            a[x] = i;
            b1[i] = 1;
            b2[x + i] = 1;
            b3[x - i + n] = 1;
            dfs(x + 1);
            b1[i] = 0;
            b2[x + i] = 0;
            b3[x - i + n] = 0;
        }
    }
}

int main()
{
    cin >> n;
    dfs(1);
    cout << ans;
    return 0;
}