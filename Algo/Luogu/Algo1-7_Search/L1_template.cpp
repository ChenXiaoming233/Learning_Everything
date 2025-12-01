// [] 回溯算法与深度优先搜索
#include <bits/stdc++.h>

#define SIZE 5

using namespace std;

int n = (SIZE - 1) * (SIZE - 1), ans = 0;
int a[SIZE * SIZE];
int b1[SIZE][SIZE], b2[SIZE][SIZE], b3[SIZE][SIZE]; // 分别记录横行，竖行，小块中的每个位置的可选项（1 2 3 4）是否被占用

void dfs(int x) // 每一格的序号，此时最小颗粒度为单格 (递归层数)
{
    if (x > n) // 某次递归令所有空都填满时输出本次结果，但递归并未全部结束（基础情况处理）
    {
        ans++;
        for (int i = 1; i <= n; i++) // 输出结果
        {
            cout << a[i] << " ";
            if (i % 4 == 0)
                cout << endl;
        }
        // 结束当前这一层递归调用，返回到上一级调用点
        return; // !跳出递归时记得 return!
    }

    int row = (x - 1) / 4 + 1;                                         // 位置对应的横行编号
    int col = (x - 1) % 4 + 1;                                         // 位置对应的竖排编号
    int block = ((row - 1) / 2) * 2 + (col - 1) / 2 + 1;               // 位置对应的小块编号
    for (int i = 1; i <= 4; i++)                                       // 枚举可行的选项
        if (b1[row][i] == 0 and b2[col][i] == 0 and b3[block][i] == 0) // 如果合法
        {
            // 记录当前选项情况
            a[x] = i;       // 记录放置位置
            b1[row][i] = 1; // 标记可选项（1 2 3 4）在该行、该列与该小块被占用
            b2[col][i] = 1;
            b3[block][i] = 1;
            // 下层递归
            dfs(x + 1);
            // 复原当前选项的影响
            b1[row][i] = 0; // 取消占位
            b2[col][i] = 0;
            b3[block][i] = 0;
        }
}

int main()
{
    dfs(1);
    cout << ans;
    return 0;
}