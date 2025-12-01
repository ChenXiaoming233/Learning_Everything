#include <bits/stdc++.h>

using namespace std;

int numIsland (vector<vector<char>>& grid){
    int res = 0;
    int rowmax = grid.size(); // 最大行数
    int colmax = grid[0].size(); // 最大列数
    for(int i = 0; i < rowmax; i++){
        for(int j = 0; j < colmax; j++){
            if(grid[i][j] == '1'){
                res++;
                dfs(grid, i, j);
            }
        }
    }
    return res;
}

void dfs(vector<vector<char>>& grid, int i, int j){
    int rowmax = grid.size(); // 最大行数
    int colmax = grid[0].size(); // 最大列数
    if(i < 0 or j < 0 or i >= rowmax or j >= colmax){
        return;
    }
    if(grid[i][j] == '0'){
        return;
    }
    grid[i][j] = '0';
    dfs(grid, i - 1, j);
    dfs(grid, i + 1, j);
    dfs(grid, i, j - 1);
    dfs(grid, i, j + 1);
}