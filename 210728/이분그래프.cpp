#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int tc, v, e;
vector<vector<int> > graph;
vector<bool> visited;
vector<int> part;
vector<int> comp;
int ncomps;

void dfs(int vertex) {
    visited[vertex] = true;
    for(int i = 0; i < graph[vertex].size(); i++) {
        if(!visited[graph[vertex][i]]) 
            dfs(graph[vertex][i]);
    }
}

bool bfs(int vertex) {
    queue<pair<int, int> > q;   //  (정점 번호, 속한 집합) 속한 집합 = 0(left), 1(right)
    part.assign(v + 1, -1);
    part[vertex] = 0;
    q.push(make_pair(vertex, 0));

    while(!q.empty()) {
        int vnum = q.front().first;
        int snum = q.front().second;
        q.pop();

        for(int i = 0; i < graph[vnum].size(); i++) {
            if(part[graph[vnum][i]] == -1) {
                if(snum == 0) {
                    part[graph[vnum][i]] = 1;
                    q.push(make_pair(graph[vnum][i], 1));
                }
                else if(snum == 1) {
                    part[graph[vnum][i]] = 0;
                    q.push(make_pair(graph[vnum][i], 0));
                }
            }
            else {
                if(part[graph[vnum][i]] == snum)
                    return false;
            }
        }
    }

    return true;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    for(int t = 0; t < tc; t++) {
        ncomps = 0;
        cin >> v >> e;
        graph.assign(v + 1, vector<int>());
        visited.assign(v + 1, false);
        comp.assign(0, 0);

        for(int i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        for(int i = 1; i <= v; i++) {
            if(!visited[i]) {
                dfs(i);
                comp.push_back(i);
                ncomps += 1;
            }
        }

        bool bipartite = true;
        for(int i = 0; i < comp.size(); i++) {
            if(!bfs(comp[i])) {
                bipartite = false;
                cout << "NO" << '\n';
                break;
            }
        }
        if(bipartite) cout << "YES" << '\n';
    }

    return 0;
}