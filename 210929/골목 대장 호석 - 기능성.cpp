#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 11;
vector<pair<int, int>> graph[MAX];
bool visited[MAX];
int n, m, s, e, c, answer;

void dfs(int v, int max_cost, int total_cost) {
    if (v == e) {
        answer = min(answer, max_cost);
        return;
    }
    for (auto &[next, cost] : graph[v]) {
        if (!visited[next] && total_cost + cost <= c) {
            visited[next] = true;
            dfs(next, max(max_cost, cost), total_cost + cost);
            visited[next] = false;
        }
    }
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

    answer = 1e9;
    dfs(s, 0, 0);
    if (answer == 1e9) answer = -1;
    cout << answer << endl;
    return 0;
}