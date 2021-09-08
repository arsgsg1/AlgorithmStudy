#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

const int INF = 2e9;
vector<pair<int, int>> graph[100001];

vector<int> dijkstra(int src, int n) {
    vector<int> dist(n + 1, INF);
    priority_queue<pii, vector<pii>, greater<>> pq;
    dist[src] = 0;
    pq.push({dist[src], src});
    while (!pq.empty()) {
        int d = pq.top().first;
        int v = pq.top().second;
        pq.pop();
        
        if (d > dist[v]) continue;
        
        for (auto& adj : graph[v]) {
            int nv = adj.first;
            int nd = adj.second + d;
            if (nd < dist[nv]) {
                dist[nv] = nd;
                pq.push({dist[nv], nv});
            }
        }
    }
    return dist;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, a, b, c;
    cin >> n >> a >> b >> c >> m;
    for (int i = 0; i < m; i++) {
        int from, to, dist;
        cin >> from >> to >> dist;
        graph[from].push_back({to, dist});
        graph[to].push_back({from, dist});
    }
    
    vector<vector<int>> dists;
    dists.push_back(dijkstra(a, n));
    dists.push_back(dijkstra(b, n));
    dists.push_back(dijkstra(c, n));
    
    int max_dist = 0, dest = 0;
    for (int i = 1; i <= n; i++) {
        int dist = INF;
        for (int j = 0; j < 3; j++) dist = min(dist, dists[j][i]);
        if (dist > max_dist) {
            max_dist = dist;
            dest = i;
        }
    }
    
    cout << dest << endl;
    
    return 0;
}
