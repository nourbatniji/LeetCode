#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;

        int n = matrix.size();
        int m = matrix[0].size();

        int low = 0;
        int high = n * m - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int row = mid / m;
            int col = mid % m;

            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> matrix = {
        {1, 3, 5},
        {7, 9, 11},
        {13, 15, 17}
    };

    int target = 9;

    if (sol.searchMatrix(matrix, target))
        cout << "Found\n";
    else
        cout << "Not Found\n";

    return 0;
}