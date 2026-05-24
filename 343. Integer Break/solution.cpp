#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> memo;

    int solve(int n) {

        // base case
        if (n == 1)
            return 1;

        // already calculated
        if (memo[n] != -1)
            return memo[n];

        int maxProduct = 0;

        for (int i = 1; i < n; i++) {

            // split into two parts
            int profit = max(i * (n - i),
                             i * solve(n - i));

            maxProduct = max(maxProduct, profit);
        }

        memo[n] = maxProduct;
        return maxProduct;
    }

    int integerBreak(int n) {

        memo.resize(n + 1, -1);

        return solve(n);
    }
};

int main() {

    Solution s;

    int n;
    cin >> n;

    cout << s.integerBreak(n);

    return 0;
}