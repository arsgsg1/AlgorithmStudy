#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 301;
int parent[MAX];
vector<pair<int, pair<int, int>>> graph;
int n;

int find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int cost;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> cost;
        graph.push_back({cost, {i, 0}});
        parent[i] = i;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> cost;
            if (i > j) graph.push_back({cost, {i, j}});
        }
    }
    
    sort(graph.begin(), graph.end());
    
    int answer = 0;
    for (auto& edge : graph) {
        int cost = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if (find(u) != find(v)) {
            answer += cost;
            parent[find(u)] = find(v);
        }
    }
    
    cout << answer << endl;
    
    return 0;
}
