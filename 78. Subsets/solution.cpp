#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    void solve(int i,
               int n,
               vector<int>& nums,
               vector<int>& subset,
               vector<vector<int>>& ans)
    {
        // Store current subset
        ans.push_back(subset);

        for (int j = i; j < n; j++) {

            // Choose
            subset.push_back(nums[j]);

            // Explore
            solve(j + 1, n, nums, subset, ans);

            // Backtrack
            subset.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> subset;

        solve(0, nums.size(), nums, subset, ans);

        return ans;
    }
};

int main() {

    Solution s;

    vector<int> nums = {1, 2, 3};

    vector<vector<int>> result = s.subsets(nums);

    cout << "All subsets:\n";

    for (auto subset : result) {

        cout << "[ ";

        for (int x : subset) {
            cout << x << " ";
        }

        cout << "]\n";
    }

    return 0;
}