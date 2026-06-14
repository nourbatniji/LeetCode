#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n);
        dp[0] = nums[0];

        int result = dp[0];

        for (int i = 1; i < n; i++) {
            dp[i] = max(nums[i] + dp[i - 1], nums[i]);
            result = max(result, dp[i]);
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << "Maximum subarray sum: "
         << sol.maxSubArray(nums) << endl;

    return 0;
}