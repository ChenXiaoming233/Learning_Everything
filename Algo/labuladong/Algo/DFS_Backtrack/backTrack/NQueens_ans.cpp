// LC51 - N皇后
// #回溯

#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    // 输入棋盘边长 n，返回所有合法的放置
    vector<vector<string>> solveNQueens(int n)
    {
        // '.' 表示空，'Q' 表示皇后，初始化空棋盘。
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0);
        return res;
    }

private:
    vector<vector<string>> res;

    // 路径：board 中小于 row 的那些行都已经成功放置了皇后
    // 选择列表：第 row 行的所有列都是放置皇后的选择
    // 结束条件：row 超过 board 的最后一行
    void backtrack(vector<string> &board, int row) // 以行为单位
    { 
        // 触发结束条件
        if (row == board.size())
        {
            res.push_back(board); // 此时的 board 状态即为答案
            return;
        }

        int n = board[row].size();
        for (int col = 0; col < n; col++)
        {
            // 排除不合法选择
            if (!isValid(board, row, col))
            {
                continue;
            }
            // 做选择
            board[row][col] = 'Q';
            // 进入下一行决策
            backtrack(board, row + 1);
            // 撤销选择
            board[row][col] = '.';
        }
    }

    // 是否可以在 board[row][col] 放置皇后？
    bool isValid(const vector<string> &board, int row, int col)
    {
        int n = board[0].size(); // board 的列数
        // 检查列是否有皇后互相冲突
        for (int i = 0; i < row; i++)
        {
            if (board[i][col] == 'Q')
                return false;
        }
        // 检查右上方是否有皇后互相冲突
        // ! 注意 条件部分应使用 and 而非 , 否则会令前序条件被丢弃
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if (board[i][j] == 'Q')
                return false;
        }
        // 检查左上方是否有皇后互相冲突
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }
};