#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 10001;
vector<pair<int, int>> graph[MAX];
int n, source, max_dist;

void dfs(int src, int prev, int dist) {
    if (dist > max_dist) {
        max_dist = dist;
        source = src;
    }
    
    for (auto& adj : graph[src]) {
        if (adj.first == prev) continue;
        dfs(adj.first, src, dist + adj.second);
    }
}

int main() {
    int a, b, d;
    while (~scanf("%d %d %d", &a, &b, &d)) {
        graph[a].push_back({b, d});
        graph[b].push_back({a, d});
    }
    
    dfs(1, 0, 0);
    dfs(source, 0, 0);
    
    cout << max_dist << endl;
    
    return 0;
}
