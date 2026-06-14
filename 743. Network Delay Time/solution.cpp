#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> pii;

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pii>> graph(n + 1);

    for (auto &t : times) {
        int u = t[0];
        int v = t[1];
        int w = t[2];
        graph[u].push_back({v, w});
    }

    vector<int> dist(n + 1, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[k] = 0;
    pq.push({0, k});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u])
            continue;

        for (auto &edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    int answer = 0;

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX)
            return -1;

        answer = max(answer, dist[i]);
    }

    return answer;
}

int main() {
    vector<vector<int>> times = {
        {2, 1, 1},
        {2, 3, 1},
        {3, 4, 1}
    };

    int n = 4;
    int k = 2;

    cout << "Network Delay Time = "
         << networkDelayTime(times, n, k)
         << endl;

    return 0;
}