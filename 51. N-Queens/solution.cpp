#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    bool isSafe(vector<string> &board, int row, int col, int n)
    {
        int i, j;
        for (i = 0; i < col; i++)
        {
            if (board[row][i] == 'Q')
                return false;
        }
        for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 'Q')
                return false;
        }
        for (i = row + 1, j = col - 1; i < n && j >= 0; i++, j--)
        {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void solve(vector<string> &board, vector<vector<string>> &ans, int col,
               int n)
    {

        if (col == n)
        {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++)
        {
            if (isSafe(board, row, col, n))
            {
                board[row][col] = 'Q';
                solve(board, ans, col + 1, n);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        solve(board, ans, 0, n);
        return ans;
    }
};

int main() {
    int n = 4;
    Solution sol;
    vector<vector<string>> result = sol.solveNQueens(n);
 
    cout << "Total solutions for " << n << "-Queens: " << result.size() << "\n\n";
    for (int i = 0; i < (int)result.size(); i++) {
        cout << "Solution " << i + 1 << ":\n";
        for (const string& row : result[i])
            cout << "  " << row << "\n";
        cout << "\n";
    }
    return 0;
}