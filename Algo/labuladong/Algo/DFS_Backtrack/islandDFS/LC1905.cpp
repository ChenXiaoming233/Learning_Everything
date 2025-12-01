// LC1905 - 不同的岛屿数量
// #DFS #岛屿

#include <bits/stdc++.h>

using namespace std;

int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
{
    int rowmax = grid1.size();
    int colmax = grid1[0].size();

    // 如果岛屿 B 中存在一片陆地，在岛屿 A 的对应位置是海水，那么岛屿 B 就不是岛屿 A 的子岛。
    for (int row = 0; row < rowmax; row++)
    { // 涉及整个岛屿的操作在主函数中完成 (e.g. 是否淹没，判定岛屿)
        for (int col = 0; col < colmax; col++)
        {
            if (grid1[row][col] == 0 and grid2[row][col] == 1) // 只有出现在 grid2 中是陆地而 grid1 中是海水的格子，才将岛屿淹没
            {
                dfs(grid2, row, col); // 全程在 grid2 中操作, 不影响 grid1
            }
        }
    }
    // 现在 grid2 中剩下的岛屿都是子岛，计算岛屿数量
    int res = 0;
    for (int row = 0; row < rowmax; row++)
    {
        for (int col = 0; col < colmax; col++)
        {
            if (grid2[row][col] == 1)
            {
                res++;
                dfs(grid2, row, col);
            }
        }
    }
    return res;
}

// 从 (i, j) 开始，将与之相邻的陆地都变成海水
void dfs(vector<vector<int>> &grid, int i, int j)
{
    int m = grid.size(), n = grid[0].size();
    if (i < 0 || j < 0 || i >= m || j >= n)
    {
        return;
    }
    if (grid[i][j] == 0)
    {
        return;
    }

    grid[i][j] = 0;
    dfs(grid, i + 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i - 1, j);
    dfs(grid, i, j - 1);
}