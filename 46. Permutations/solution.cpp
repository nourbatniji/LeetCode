#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    void permute(int index, vector<int>& nums, vector<vector<int>>& ans) {

        // base case
        if(index == nums.size()) {
            ans.push_back(nums);
            return;
        }

        // try every number at current position
        for(int i = index; i < nums.size(); i++) {

            // choose
            swap(nums[index], nums[i]);

            // recurse
            permute(index + 1, nums, ans);

            // backtrack
            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;

        permute(0, nums, ans);

        return ans;
    }
};

int main() {

    Solution s;

    vector<int> nums = {1, 2, 3};

    vector<vector<int>> result = s.permute(nums);

    for(auto permutation : result) {

        for(int num : permutation) {
            cout << num << " ";
        }

        cout << endl;
    }

    return 0;
}