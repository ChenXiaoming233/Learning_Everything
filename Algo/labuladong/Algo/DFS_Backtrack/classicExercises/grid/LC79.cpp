// LC79 - 单词搜索
// #回溯 #图

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isExist = false;
    // 由于无需返回具体结果，事实上无需记录 track 的具体内容，仅需记录 board 的使用情况与 track 的长度
    string track;
    vector<vector<bool>> pathUsed;
    bool exist(vector<vector<char>> &board, string word)
    {
        pathUsed = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));
        int rowmax = board.size();
        int colmax = board[0].size();
        // 主函数中循环，尝试以每一个方块作为起点
        // 若 (rA, cA) 为起点失败后，回溯过程中会擦除 pathUsed 状态信息，不会冲突
        for (int row = 0; row < rowmax; row++)
        {
            for (int col = 0; col < colmax; col++)
            {
                dfs(board, row, col, word);
                if (isExist)
                {
                    return true;
                }
            }
        }
        return false;
    }

    void dfs(vector<vector<char>> &board, int row, int col, string &word)
    {
        int rowmax = board.size();
        int colmax = board[0].size();
        if (track.size() == word.size())
        {
            isExist = true;
            return;
        }
        if (isExist)
        {
            return;
        }
        if (row < 0 or col < 0 or row >= rowmax or col >= colmax)
        {
            return;
        }
        // 是否与 word 的下一位匹配
        if (board[row][col] != word[track.size()])
        {
            return;
        }
        // 是否被使用，防止走回头路
        if (pathUsed[row][col] == true)
        {
            return;
        }
        track.push_back(board[row][col]);
        pathUsed[row][col] = true;
        dfs(board, row - 1, col, word);
        dfs(board, row + 1, col, word);
        dfs(board, row, col - 1, word);
        dfs(board, row, col + 1, word);
        pathUsed[row][col] = false;
        track.pop_back();
    }
};