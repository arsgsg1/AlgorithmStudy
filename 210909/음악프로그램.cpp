#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<int> in(n + 1, 0);
    
    for (int i = 0; i < m; i++) {
        int cur, prev;
        cin >> k >> prev;
        k--;
        while (k--) {
            cin >> cur;
            graph[prev].push_back(cur);
            in[cur]++;
            prev = cur;
        }
    }
    
    queue<int> q;
    for (int i = 1; i <= n; i++) if (in[i] == 0) q.push(i);
    
    vector<int> answer;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        answer.push_back(cur);
        for (auto next : graph[cur]) if (--in[next] == 0) q.push(next);
    }
    
    if (answer.size() != n) cout << 0 << endl;
    else for (auto a : answer) cout << a << '\n';
    
    return 0;
}
