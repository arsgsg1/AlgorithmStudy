#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int n, m, FROM, TO;
int max_time, ans;
vector<vector<pair<int, int> > > graph;     //  주어진 그래프
vector<vector<pair<int, int> > > reverse_graph;     //  주어진 그래프의 간선 방향 반대
vector<bool> visited;   
vector<int> indegrees;
vector<int> times;

void topology_sort() {
    queue<int> q;

    for(int i = 1; i <= n; i++) {
        if(indegrees[i] == 0)
            q.push(i);
    }

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int i = 0; i < graph[cur].size(); i++) {
            int next_v = graph[cur][i].first;
            int next_c = graph[cur][i].second;

            times[next_v] = max(times[next_v], times[cur] + next_c);
            indegrees[next_v] -= 1;
            if(indegrees[next_v] == 0)
                q.push(next_v);
        }
    }

    max_time = times[TO];
}

void bfs() {
    queue<int> q;
    visited[TO] = true;
    q.push(TO);

    while(!q.empty()) {
        int prev = q.front();
        q.pop();

        for(int i = 0; i < reverse_graph[prev].size(); i++) {
            int next = reverse_graph[prev][i].first;
            int cost = reverse_graph[prev][i].second;

            if(times[next] + cost == times[prev]) {
                ans += 1;
                if(!visited[next]) {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> m;

    graph.assign(n + 1, vector<pair<int, int> >());
    reverse_graph.assign(n + 1, vector<pair<int, int> >());
    indegrees.assign(n + 1, 0);
    times.assign(n + 1, 0);
    visited.assign(n + 1, false);

    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back(make_pair(b, c));
        reverse_graph[b].push_back(make_pair(a, c));
        indegrees[b] += 1;
    }
    cin >> FROM >> TO;

    topology_sort();

    cout << max_time << '\n';
    bfs();
    cout << ans << '\n';

    return 0;
}