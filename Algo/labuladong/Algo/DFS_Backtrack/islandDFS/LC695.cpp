// LC695 - 岛屿的最大面积
// #DFS #岛屿

#include <bits/stdc++.h>

using namespace std;

int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int res = 0;
    int rowmax = grid.size();
    int colmax = grid[0].size();
    for (int row = 0; row < rowmax; row++)
    {
        for (int col = 0; col < colmax; col++)
        {
            if (grid[row][col] == 1)
            {
                res = max(res, dfs(grid, row, col));
            }
        }
    }
    return res;
}

int dfs(vector<vector<int>> &grid, int row, int col)
{ // 涉及单格的操作在 dfs 中完成 (e.g. 计算格数，计算轨迹)
    int rowmax = grid.size();
    int colmax = grid[0].size();
    // ! 注意 排除超出索引边界情况
    if (row < 0 || col < 0 || row >= rowmax || col >= colmax)
    {
        return 0;
    }
    if (grid[row][col] == 0)
    {
        return 0;
    }
    grid[row][col] = 0;
    // ! 注意 需要 + 1 算上本次淹没的面积！
    int res = 1+ dfs(grid, row - 1, col) + dfs(grid, row + 1, col) + dfs(grid, row, col - 1) + dfs(grid, row, col + 1) ;
    return res;
}