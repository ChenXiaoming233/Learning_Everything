// LC694 - 不同岛屿的数量

#include <bits/stdc++.h>

using namespace std;

int numDistinctIslands(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    // 使用哈希表记录所有岛屿的序列化结果并去重
    unordered_set<string> islands;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                // 淹掉这个岛屿，同时存储岛屿的序列化结果
                string sb;
                // 初始的方向可以随便写，回溯算法关注的是过程而不是具体节点，不影响正确性
                dfs(grid, i, j, sb, 666);
                islands.insert(sb);
            }
        }
    }
    // 不相同的岛屿数量
    return islands.size();
}

void dfs(vector<vector<int>> &grid, int i, int j, string &sb, int dir)
{
    int m = grid.size(), n = grid[0].size();
    if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0)
    {
        return;
    }

    // 利用遍历顺序对岛屿形状序列化，实际上是回溯算法
    // 前序遍历位置：进入 (i, j)
    grid[i][j] = 0;
    sb += to_string(dir) + ','; // dir 记录方向，sb 记录整个遍历顺序

    dfs(grid, i - 1, j, sb, 1);
    dfs(grid, i + 1, j, sb, 2);
    dfs(grid, i, j - 1, sb, 3);
    dfs(grid, i, j + 1, sb, 4);

    // 后序遍历位置：离开 (i, j)
    sb += to_string(-dir) + ',';
}