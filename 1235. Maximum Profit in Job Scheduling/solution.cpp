#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    struct Job {
        int start, end, profit;
    };

    static bool compare(Job a, Job b) {
        return a.end < b.end;
    }

    int findPrev(vector<Job>& jobs, int index) {

        for (int i = index - 1; i >= 0; i--) {

            if (jobs[index].start >= jobs[i].end) {
                return i;
            }
        }

        return -1;
    }

    int solve(vector<Job>& jobs) {

        int n = jobs.size();

        sort(jobs.begin(), jobs.end(), compare);

        vector<int> dp(n);

        // base case
        dp[0] = jobs[0].profit;

        for (int i = 1; i < n; i++) {

            // take current job
            int take = jobs[i].profit;

            int prev = findPrev(jobs, i);

            if (prev != -1) {
                take += dp[prev];
            }

            // leave current job
            int leave = dp[i - 1];

            // recurrence relation
            dp[i] = max(take, leave);
        }

        return dp[n - 1];
    }

    int jobScheduling(vector<int>& startTime,
                      vector<int>& endTime,
                      vector<int>& profit) {

        vector<Job> jobs;

        for (int i = 0; i < startTime.size(); i++) {

            jobs.push_back({
                startTime[i],
                endTime[i],
                profit[i]
            });
        }

        return solve(jobs);
    }
};

int main() {

    Solution s;

    vector<int> startTime = {1, 2, 3, 3};
    vector<int> endTime   = {3, 4, 5, 6};
    vector<int> profit    = {50, 10, 40, 70};

    cout << s.jobScheduling(startTime, endTime, profit);

    return 0;
}