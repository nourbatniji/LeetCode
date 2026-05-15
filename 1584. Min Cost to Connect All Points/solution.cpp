#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    typedef pair<int, int> pii;
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<int> key(n, INT_MAX);
        vector<bool> inMST(n, false);
        vector<int> parent(n, -1);

        priority_queue<pii, vector<pii>, greater<pii>> pq;

        key[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {

            int u = pq.top().second;
            pq.pop();

            if (inMST[u])
                continue;
            inMST[u] = true;

            for (int v = 0; v < n; v++) {
                if (!inMST[v]) {
                    int weight = abs(points[u][0] - points[v][0]) +
                                 abs(points[u][1] - points[v][1]);

                    if (weight < key[v]) {
                        key[v] = weight;
                        parent[v] = u;
                        pq.push({weight, v});
                    }
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < key.size(); i++) {
            sum += key[i];
        }
        return sum;
    }
};