// LC1254 - 统计封闭岛屿的数目
// #DFS #岛屿

#include <bits/stdc++.h>

using namespace std;

int closedIsland(vector<vector<int>> &grid)
{
    int res = 0;
    int rowmax = grid.size();
    int colmax = grid[0].size();
    // 将靠四边的岛屿直接淹没不计数
    for (int row = 0; row < rowmax; row++)
    {
        dfs(grid, row, 0);
        dfs(grid, row, colmax - 1);
    }
    for (int col = 0; col < colmax; col++)
    {
        dfs(grid, 0, col);
        dfs(grid, rowmax - 1, col);
    }
    for (int row = 0; row < rowmax; row++)
    {
        for (int col = 0; col < colmax; col++)
        {
            if (grid[row][col] == 0)
            {
                res++;
                dfs(grid, row, col);
            }
        }
    }
    return res;
}

void dfs(vector<vector<int>> &grid, int row, int col)
{
    int rowmax = grid.size();
    int colmax = grid[0].size();
    // ! 注意 排除超出索引边界情况
    if (row < 0 or col < 0 or row >= rowmax or col >= colmax)
    {
        return;
    }
    if (grid[row][col] == 1)
    {
        return;
    }
    grid[row][col] = 1;

    dfs(grid, row - 1, col);
    dfs(grid, row + 1, col);
    dfs(grid, row, col - 1);
    dfs(grid, row, col + 1);
}