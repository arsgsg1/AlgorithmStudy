#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAX = 100001;
const ll INF = 2e18;
vector<pii> graph[MAX];
int n, m, s, e, answer;
ll c;

bool dijkstra(int limit) {
    vector<ll> costs(n + 1, INF);
    priority_queue<pll, vector<pll>, greater<>> pq;
    costs[s] = 0;
    pq.push({costs[s], s});

    while (!pq.empty()) {
        auto [cost, cur] = pq.top();
        pq.pop();

        if (cost != costs[cur]) continue;

        for (auto& adj : graph[cur]) {
            int next = adj.first;
            ll nc = cost + adj.second;
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

    answer = 2e9;
    int lo = 1, hi = 1e9;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (dijkstra(mid)) {
            answer = min(answer, mid);
            hi = mid - 1;
        } else
            lo = mid + 1;
    }

    if (answer == 2e9) answer = -1;
    cout << answer << endl;

    return 0;
}