#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int V, E;
int scc_num = 0;                //  scc 개수
vector<bool> visited;
vector<int> num;    //  정점에 기록된 num_cnt 순으로 정점 번호 저장
vector<vector<int> > forward_g; //  정방향 그래프
vector<vector<int> > reverse_g; //  역방향 그래프
vector<vector<int> > scc;       //  strongly connected components

void dfs1(int v) {
    visited[v] = true;

    for(int i = 0; i < forward_g[v].size(); i++)
        if(!visited[forward_g[v][i]]) 
            dfs1(forward_g[v][i]);

    num.push_back(v);
    return;
}

void dfs2(int v) {
    visited[v] = true;

    for(int i = 0; i < reverse_g[v].size(); i++)
        if(!visited[reverse_g[v][i]]) 
            dfs2(reverse_g[v][i]);

    scc[scc_num].push_back(v);
    return;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> V >> E;

    visited.assign(V + 1, false);
    forward_g.assign(V + 1, vector<int>());
    reverse_g.assign(V + 1, vector<int>());

    for(int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;

        forward_g[a].push_back(b);
        reverse_g[b].push_back(a);
    }

    //  첫 번째 DFS, 모든 정점에 num_cnt 기록
    for(int i = 1; i <= V; i++) {
        if(!visited[i])
            dfs1(i);
    }

// 
    // for(int i = 0; i < num.size(); i++)
    //     cout << num[i] << " ";
    // cout << '\n';
// 
    for(int i = 0; i <= V; i++)
        visited[i] = false;

    //  두 번째 DFS, 역방향 그래프에서 num_cnt가 큰 정점부터 DFS, 한 정점부터 시작해서 방문할 수 있는 모든 정점이 SCC의 구성 정점임
    while(!num.empty()) {
        int v = num.back();
        // cout << "v : " << v << '\n';
        num.pop_back();

        if(!visited[v]) {
            scc.push_back(vector<int>());
            dfs2(v);
            scc_num++;
        }
    }

    for(int i = 0; i < scc.size(); i++)
        sort(scc[i].begin(), scc[i].end());
    sort(scc.begin(), scc.end());

    cout << scc_num << '\n';
    for(int i = 0; i < scc.size(); i++) {
        for(int j = 0; j < scc[i].size(); j++)
            cout << scc[i][j] << ' ';
        cout << -1 << '\n';
    }

    return 0;
}