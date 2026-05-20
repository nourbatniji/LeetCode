#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solve(int i, vector<int>& candidates, int target,
               vector<int>& subset, vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(subset);
            return;
        }

        if (i == candidates.size()) {
            return;
        }

        // skip current number
        solve(i + 1, candidates, target, subset, ans);

        // take current number
        if (candidates[i] <= target) {
            subset.push_back(candidates[i]);

            // i, not i + 1, because we can reuse it
            solve(i, candidates, target - candidates[i], subset, ans);

            subset.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> subset;

        solve(0, candidates, target, subset, ans);

        return ans;
    }
};

int main() {

    Solution s;

    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result =
        s.combinationSum(candidates, target);

    cout << "Combinations:\n";

    for (auto subset : result) {

        cout << "[ ";

        for (int x : subset) {
            cout << x << " ";
        }

        cout << "]\n";
    }

    return 0;
}