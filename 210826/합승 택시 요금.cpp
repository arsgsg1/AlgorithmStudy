#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

const int INF = 2e9;
vector<vector<pii>> graph;

vector<int> dijkstra(int src, int n) {
    vector<int> fares(n + 1, INF);
    priority_queue<pii, vector<pii>, greater<>> pq;
    fares[src] = 0;
    pq.push({fares[src], src});
    
    while (!pq.empty()) {
        int d = pq.top().first;
        int v = pq.top().second;
        pq.pop();
        
        if (d > fares[v]) continue;
        
        for (auto& adj : graph[v]) {
            int nv = adj.first;
            int nd = d + adj.second;
            if (nd < fares[nv]) {
                fares[nv] = nd;
                pq.push({fares[nv], nv});
            }
        }
    }
    return fares;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    graph.resize(n + 1);
    for (auto& fare : fares) {
        graph[fare[0]].push_back({fare[1], fare[2]});
        graph[fare[1]].push_back({fare[0], fare[2]});
    }
    
    vector<int> fares_ab = dijkstra(s, n);
    vector<int> fares_a = dijkstra(a, n);
    vector<int> fares_b = dijkstra(b, n);
    
    for (int i = 1; i <= n; i++)
        answer = min(answer, fares_ab[i] + fares_a[i] + fares_b[i]);
    
    return answer;
}
