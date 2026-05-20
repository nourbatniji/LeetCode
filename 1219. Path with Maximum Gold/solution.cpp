#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int dr[4] = {1, 0, 0, -1};
    int dc[4] = {0, 1, -1, 0};

    bool isValid(vector<vector<int>>& grid, int row, int col, int N, int M) {
        return row >= 0 && col >= 0 &&
               row < N && col < M &&
               grid[row][col] != 0;
    }

    void solve(vector<vector<int>>& grid,
               int row, int col,
               int N, int M,
               int currentGold,
               int& maxGold) {

        if (!isValid(grid, row, col, N, M))
            return;

        int gold = grid[row][col];

        currentGold += gold;

        maxGold = max(maxGold, currentGold);

        // mark visited
        grid[row][col] = 0;

        // move in 4 directions
        for (int i = 0; i < 4; i++) {
            int nextRow = row + dr[i];
            int nextCol = col + dc[i];

            solve(grid,
                  nextRow,
                  nextCol,
                  N,
                  M,
                  currentGold,
                  maxGold);
        }

        // backtrack
        grid[row][col] = gold;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int N = grid.size();
        int M = grid[0].size();

        int maxGold = 0;

        // start from every gold cell
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < M; col++) {

                if (grid[row][col] != 0) {

                    solve(grid,
                          row,
                          col,
                          N,
                          M,
                          0,
                          maxGold);
                }
            }
        }

        return maxGold;
    }
};

int main() {

    vector<vector<int>> grid = {
        {0, 6, 0},
        {5, 8, 7},
        {0, 9, 0}
    };

    Solution obj;

    cout << obj.getMaximumGold(grid) << endl;

    return 0;
}