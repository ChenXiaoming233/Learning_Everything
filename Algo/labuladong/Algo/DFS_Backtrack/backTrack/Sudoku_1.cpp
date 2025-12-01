#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool hasfound = false;
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board, 0);
        return;
    }
private:
    void backtrack(vector<vector<char>>& board, int index){
        int rowmax = board.size(); // 总行数
        int colmax = board[0].size(); // 总列数（一行有几个）
        int row = index / colmax; // 当前行数
        int col = index % colmax; // 当前列数（当行第几个）
        if(hasfound){
            return;
        }
        if(index == rowmax * colmax){
            hasfound = true;
            return;
        }
        if(board[row][col] != '.'){
            backtrack(board, index + 1);
            return;
        }
        for(char i = '1'; i <= '9'; i++){
            if(isValid(board, row, col, i) == true){
                board[row][col] = i;
                backtrack(board, index + 1);
                if(hasfound == true){
                    return;
                }
                board[row][col] = '.';
            }
        }
    }
    
    bool isValid(vector<vector<char>>& board, int row, int col, char n){
        for(int i = 0; i < 9; i++){
            if(board[i][col] == n){
                return false;
            }
            if(board[row][i] == n){
                return false;
            }
            if (board[(row / 3) * 3 + i / 3][(col / 3) * 3 + i % 3] == n){
                return false;
            }
        }
        return true;
    }
};