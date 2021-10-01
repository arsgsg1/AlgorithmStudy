#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

const int MAX = 100001;
const int INF = 2e9;
vector<pair<int, int>> graph[MAX];
int n, m, s, e, c, answer;

bool dijkstra(int limit) {
    vector<int> costs(n + 1, INF);
    priority_queue<pii, vector<pii>, greater<>> pq;
    costs[s] = 0;
    pq.push({costs[s], s});

    while (!pq.empty()) {
        auto [cost, cur] = pq.top();
        pq.pop();

        if (cost != costs[cur]) continue;

        for (auto& adj : graph[cur]) {
            int next = adj.first;
            int nc = cost + adj.second;
            if (adj.second <= limit && nc < costs[next]) {
                costs[next] = nc;
                pq.push({costs[next], next});
            }
        }
    }

    return costs[e] <= c;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> s >> e >> c;
    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back({to, cost});
        graph[to].push_back({from, cost});
    }

    answer = -1;
    for (int i = 20; i >= 1; i--)
        if (dijkstra(i)) answer = i;

    cout << answer << endl;

    return 0;
}