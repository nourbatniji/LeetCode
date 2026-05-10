#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') {
                    for (int num = 1; num <= 9; num++) {
                        if (isSafe(board, r, c, num)) {
                            board[r][c] = num + '0';
                            if (isValidSudoku(board))
                                return true;
                            board[r][c] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

private:
    bool isSafe(vector<vector<char>>& board, int row, int col, int num) {
        //check rows
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == num + '0')
                return false;
        }
        //check columns
        for (int j = 0; j < 9; j++) {
            if (board[j][col] == num + '0')
                return false;
        }
        //check 3*3 boxes
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                if (board[startRow + r][startCol + c] == num + '0')
                    return false;
            }
        }
        return true;
    }
};