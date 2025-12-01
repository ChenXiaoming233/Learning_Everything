#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> res;

vector<vector<string>> solveNQueens(int n){
    vector<string> board(n, string(n, '.'));
    backtrack(board, 0);
    return res;
}

void backtrack(vector<string>& board, int row){
    if(row == board.size()){
        res.push_back(board);
        return;
    }
    int n = board[row].size(); // 单行格数（列数）
    for(int col = 0; col < n; col++){
        if(isValid(board, row, col) == false){
            continue;
        }
        board[row][col] = 'Q';
        backtrack(board, row + 1);
        board[row][col] = '.';
    }
}

bool isValid(vector<string>& board, int row, int col){
    int n = board[0].size();
    for(int i = 0; i < row; i++){
        if(board[i][col] == 'Q'){
            return false;
        }
    }
    for(int i = row - 1, j = col - 1; i >= 0 and j >= 0; i--, j--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }
    for(int i = row - 1, j = col + 1; i >= 0 and j < n; j++){
        if (board[i][j] == 'Q')
            return false;
    }
    return true;
}