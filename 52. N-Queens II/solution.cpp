#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        vector<int> board(n, -1);
        int count = 0;
        solve(board, 0, n, count); // helper function
        return count;
    }

private:
    void solve(vector<int>& board, int row, int n, int& count) {
        if (row == n) { // all rows filled
            count++;
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col)) {
                board[row] = col;
                solve(board, row + 1, n, count);
                board[row] = -1; // backtrack
            }
        }
    }
    bool isSafe(vector<int>& board, int row, int col) {
        for (int i = 0; i < row; i++) {
            if (board[i] == col || board[i] - col == i - row ||
                board[i] - col == row - i) {
                return false;
            }
        }
        return true;
    }
}

;