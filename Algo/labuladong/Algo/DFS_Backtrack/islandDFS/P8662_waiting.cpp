// P8662 [蓝桥杯 2018 省 AB] 全球变暖 洛谷

#include <bits/stdc++.h>

using namespace std;

bool dfs(vector<vector<char>>& grid, vector<vector<char>>& grid_origin, int row, int col)
{
    int rowmax = grid.size();
    int colmax = grid[0].size();
    if (row < 0 or col < 0 or row >= rowmax or col >= colmax)
    {
        return false;
    }
    if (grid[row][col] == '.')
    {
        return false;
    }
    grid[row][col] = '.';

    bool survive = true;
    if (grid_origin[row - 1][col] == '#' and grid_origin[row + 1][col] == '#' and grid_origin[row][col - 1] == '#' and grid_origin[row][col + 1] == '#')
    {
        return 1 + dfs(grid, grid_origin, row - 1, col) + dfs(grid, grid_origin, row + 1, col) + dfs(grid, grid_origin, row, col - 1) + dfs(grid, grid_origin, row, col + 1);
    }
    else
    {
        return dfs(grid, grid_origin, row - 1, col) + dfs(grid, grid_origin, row + 1, col) + dfs(grid, grid_origin, row, col - 1) + dfs(grid, grid_origin, row, col + 1);
    }
}

int island(vector<vector<char>>& grid)
{
    vector<vector<char>> grid_origin(grid);
    int rest = 0;
    int rowmax = grid.size();
    int colmax = grid[0].size();
    for (int row = 0; row < rowmax; row++)
    {
        for (int col = 0; col < colmax; col++)
        {
            if (grid[row][col] == '#')
            {
                rest += dfs(grid, grid_origin, row, col);
            }
        }
    }
    return rest;
}



int main()
{
    int n;
    cin >> n;
    vector<vector<char>> grid;
    for (int i = 0; i < n; i++)
    {
        vector<char> line;
        for (int j = 0; j < n; j++)
        {
            char index;
            cin >> index;
            line.push_back(index);
        }
        grid.push_back(line);
    }
    int rest = island(grid);
    cout << rest;
}