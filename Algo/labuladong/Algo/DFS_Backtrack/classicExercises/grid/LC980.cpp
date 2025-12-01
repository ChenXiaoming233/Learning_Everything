// LC980 - 不同路径Ⅲ
// #回溯 #图

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int visitCount = 0;
    int totalCount = 0;
    int count = 0;
    vector<vector<bool>> visited;

    int uniquePathsIII(vector<vector<int>> &grid)
    {
        int rowmax = grid.size();
        int colmax = grid[0].size();
        visited = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));
        int row0 = 0;
        int col0 = 0;
        for (int i = 0; i < rowmax; i++)
        {
            for (int j = 0; j < colmax; j++)
            {
                if (grid[i][j] == 1)
                {
                    row0 = i;
                    col0 = j;
                }
                // ! 注意 应当统计所有非障碍格子
                if (grid[i][j] != -1)
                {
                    totalCount++;
                }
            }
        }
        backtrack(grid, row0, col0);
        return count;
    }

    void backtrack(vector<vector<int>> &grid, int row, int col)
    {
        int rowmax = grid.size();
        int colmax = grid[0].size();
        if (row < 0 or col < 0 or row >= rowmax or col >= colmax)
        {
            return;
        }
        if (grid[row][col] == 2)
        {
            // ! 注意 visitCount 不包含终点所在的格子，visitCount 在后序才刷新
            if (visitCount + 1 == totalCount) // +1 算上终点自己
                count++;
            // ! 注意 终点本质上是死路，无论有无经过所有格子，都必须停止向下搜索
            return;
        }
        if (grid[row][col] == -1 or visited[row][col] == true)
        {
            return;
        }

        visited[row][col] = true;
        visitCount++;
        backtrack(grid, row - 1, col);
        backtrack(grid, row + 1, col);
        backtrack(grid, row, col - 1);
        backtrack(grid, row, col + 1);
        visited[row][col] = false;
        visitCount--;
    }
};