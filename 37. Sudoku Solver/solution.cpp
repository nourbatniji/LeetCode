#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, int n, char num) {
        for (int i = 0; i < n; i++) {
            if (board[row][i] == num) return false;
            if (board[i][col] == num) return false;
            if (board[row - row % 3 + i / 3][col - col % 3 + i % 3] == num) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        int row = -1, col = -1;
        int n = board.size();
        bool isEmpty = true;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') {
                    row = i; col = j;
                    isEmpty = false;
                    break;
                }
            }
            if (!isEmpty) break;
        }
        if (isEmpty) return true;

        for(char num = '1'; num <= '9'; num++){
            if (isSafe(board, row, col, n, num)){
                board[row][col] = num;
                if(solve(board)) return true;
                board[row][col] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

void printBoard(const vector<vector<char>>& board) {
    cout << "+-------+-------+-------+\n";
    for (int i = 0; i < 9; i++) {
        cout << "| ";
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
            if ((j + 1) % 3 == 0) cout << "| ";
        }
        cout << "\n";
        if ((i + 1) % 3 == 0) cout << "+-------+-------+-------+\n";
    }
}
 
int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
 
    cout << "Input:\n";
    printBoard(board);
 
    Solution sol;
    sol.solveSudoku(board);
 
    cout << "\nOutput:\n";
    printBoard(board);
 
    return 0;
}
 