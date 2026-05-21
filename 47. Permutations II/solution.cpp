#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:

    void permute(vector<int>& nums,
                 vector<vector<int>>& ans,
                 int index) {

        // base case
        if(index == nums.size()) {
            ans.push_back(nums);
            return;
        }

        // stores values already used at THIS level
        unordered_set<int> used;

        for(int i = index; i < nums.size(); i++) {

            // skip duplicate values
            if(used.count(nums[i]))
                continue;

            used.insert(nums[i]);

            // choose
            swap(nums[index], nums[i]);

            // recurse
            permute(nums, ans, index + 1);

            // backtrack
            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        vector<vector<int>> ans;

        permute(nums, ans, 0);

        return ans;
    }
};

int main() {

    Solution s;

    vector<int> nums = {1,1,2};

    vector<vector<int>> ans = s.permuteUnique(nums);

    for(auto permutation : ans) {

        for(int num : permutation) {
            cout << num << " ";
        }

        cout << endl;
    }

    return 0;
}