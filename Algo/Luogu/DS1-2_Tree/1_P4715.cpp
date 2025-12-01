#include <bits/stdc++.h>

using namespace std;

int n;
int value[260], winner[260];

void dfs(int x)
{
    if (x >= (1 << n)) // 到达叶子节点停止递归
        return;
    else
    {
        dfs(2 * x);
        dfs(2 * x + 1);
        int l = 2 * x;
        int r = 2 * x + 1;
        if (value[l] > value[r])
        {
            value[x] = value[l];   // 记录胜者的能力值
            winner[x] = winner[l]; // 和编号
        }
        else
        {
            value[x] = value[r];
            winner[x] = winner[r];
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= (1 << n); i++)
    {
        cin >> value[i + (1 << n) - 1];
        winner[i + (1 << n) - 1] = i;
    }
    dfs(1);
    cout << (value[1] == value[2] ? winner[3] : winner[2]); // winner[2] 与 winner[3] 分别为冠亚军
    return 0;
}