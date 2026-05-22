#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for (int coin : coins) {
            for (int current = coin; current <= amount; current++) {
                if (dp[current - coin] != INT_MAX) {  // ← fix here
                    dp[current] = min(dp[current], dp[current - coin] + 1);
                }
            }
        }

        return dp[amount] != INT_MAX ? dp[amount] : -1;
    }
};