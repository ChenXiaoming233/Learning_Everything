// LC200 - 岛屿数量
// #DFS #岛屿

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    // 计算岛屿数量
    int numIslands(vector<vector<char>> &grid)
    {
        int res = 0;
        int m = grid.size(), n = grid[0].size();
        // 遍历 grid
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1') // 发现一个岛屿
                {
                    res++;           // 数量 + 1
                    dfs(grid, i, j); // 然后使用 DFS 将岛屿淹了，避免相连陆地块被重复计数
                }
            }
        }
        return res;
    }

    // 从 (i, j) 开始，将与之相邻的陆地都变成海水
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        int m = grid.size(), n = grid[0].size();
        // ! 注意 排除超出索引边界情况
        if (i < 0 || j < 0 || i >= m || j >= n)
        {
            return;
        }
        if (grid[i][j] == '0') // 已经是海水
        {
            return;
        }
        // 将 (i, j) 变成海水
        grid[i][j] = '0';
        // 淹没上下左右的陆地
        dfs(grid, i + 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i - 1, j);
        dfs(grid, i, j - 1);
    }
};