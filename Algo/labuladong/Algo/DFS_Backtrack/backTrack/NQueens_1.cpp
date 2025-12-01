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
    void backtrack(vector<string> &board, int row)
    {
        if (row == board.size())
        {
            res.push_back(board);
            return;
        }

        int size = board[row].size();
        for (int col = 0; col < size; col++)
        {
            if (!isValid(board, row, col))
            {
                continue;
            }
            board[row][col] = 'Q';
            backtrack(board, row + 1);
            board[row][col] = '.';
        }
    }
    bool isValid(vector<string> &board, int row, int col)
    {
        int n = board.size();
        for (int i = 0; i < row; i++)
        {
            if (board[i][col] == 'Q')
            {
                return false;
            }
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if (board[i][j] == 'Q')
                return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }
};
