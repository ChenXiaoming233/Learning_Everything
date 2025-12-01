// LC37 - 解数独
// #回溯

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    // 全局变量用于标记是否已经找到可行解
    bool found = false;

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        backtrack(board, 0);
    }

private:
    // 路径：board 中小于 index 的位置所填的数字
    // 选择列表：数字 1~9
    // 结束条件：整个 board 都填满数字
    void backtrack(vector<vector<char>> &board, int index)
    {
        int m = 9, n = 9;
        int i = index / n, j = index % n; // 根据一维的 index 顺序定位二维位置

        if (found) // 已经找到一个可行解，立即结束
        {          // ! 注意 只能只能阻止 “刚进入该层” 的时候退出，但是不能阻止 “从子递归回来以后继续工作”
            return;
        }

        if (index == m * n) // 找到一个可行解，触发 base case
        {
            found = true;
            return;
        }

        if (board[i][j] != '.') // 有预设数字，直接跳过
        {
            backtrack(board, index + 1);
            return;
        }

        for (char ch = '1'; ch <= '9'; ch++)
        {
            // 剪枝：如果遇到不合法的数字，就跳过
            if (!isValid(board, i, j, ch))
                continue;

            // 做选择
            board[i][j] = ch;

            backtrack(board, index + 1);

            if (found) // 如果找到一个可行解，立即结束
            {
                // ! 注意 不要撤销选择，否则 board[i][j] 会被重置为 '.'
                return;
            }

            // 撤销选择
            board[i][j] = '.';
        }
    }

    // 判断是否可以在 (r, c) 位置放置数字 num
    bool isValid(vector<vector<char>> &board, int r, int c, char num)
    {
        for (int i = 0; i < 9; i++)
        {
            // 判断行是否存在重复
            if (board[r][i] == num)
                return false;
            // 判断列是否存在重复
            if (board[i][c] == num)
                return false;
            // 判断 3 x 3 方框是否存在重复
            if (board[(r / 3) * 3 + i / 3][(c / 3) * 3 + i % 3] == num)
                return false;
        }
        return true;
    }
};
