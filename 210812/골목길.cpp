#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#define INF      1e9
using namespace std;

int n, m;
int START = 1;
int END;
bool find_path = true;
vector<pair<pair<int, int>, int> > edges;
vector<vector<int> > graph;
vector<int> parents;
vector<bool> visited;
vector<int> dist;
vector<int> path;

void bfs() {
    queue<int> q;
    visited[END] = true;
    q.push(END);

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int i = 0; i < graph[cur].size(); i++) {
            if(!visited[graph[cur][i]]) {
                visited[graph[cur][i]] = true;
                q.push(graph[cur][i]);
            }
        }
    }
}

void bellman_ford() {
    parents[START] = START;
    dist[START] = 0;

    for(int i = 0; i < n - 1; i++) {    //  n - 1번 
        for(int j = 0; j < edges.size(); j++) { //  모든 간선에 대하여 relaxation
            //  정점 a에서 정점 b로 가는 비용이 w
            int a = edges[j].first.first;   
            int b = edges[j].first.second;
            int w = edges[j].second;

            if(dist[a] != INF && dist[a] + w < dist[b]) { //  기존 b까지 가는 거리보다 a를 거쳐서 b를 가는 게 빠를 경우
                parents[b] = a;
                dist[b] = dist[a]  + w;
            }
        }
    }

    for(int i = 0; i < edges.size(); i++) {
        int a = edges[i].first.first;   
        int b = edges[i].first.second;
        int w = edges[i].second;

        if(dist[a] != INF && dist[a] + w < dist[b]) {
            if(visited[b]) {    //  cycle이 도착점과 연루되어 있음
                find_path = false;
                break;
            }
            // parents[b] = a;
            dist[b] = dist[a]  + w;
        }
    }
}

void print_path() {
    int cur = END;

    do {
        path.push_back(cur);
        cur = parents[cur];
    } while(parents[cur] != cur);
    path.push_back(cur);

    while(!path.empty()) {
        cout << path.back() << " ";
        path.pop_back();
    }
    cout << '\n';
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    END = n;
    parents.assign(n + 1, INF);
    visited.assign(n + 1, false);
    graph.assign(n + 1, vector<int>());
    dist.assign(n + 1, INF);
    
    for(int i = 0; i < m; i++) {
        int a, b, w;    //  정점 a에서 b로 가는 비용이 w(w가 양수일 경우 습득, 음수일 경우 갈취)
        cin >> a >> b >> w;

        //  -w를 삽입하여 최대로 습득할 경우 최소 비용이 되도록 함
        edges.push_back(make_pair(make_pair(a, b), -w));
        graph[b].push_back(a);   //  간선 방향이 반대되는 그래프 생성
    }

    bfs();  //  역방향 그래프로 도착점에 도달할 수 있는 정점 모두 찾기
    bellman_ford();

    if(!find_path)  //  도착 지점까지 비용이 계속 relaxation되는 경우
        cout << -1 << '\n';
    else {
        if(dist[END] == INF)    //  도착 지점에 도달할 수 없는 경우
            cout << -1 << '\n';
        else print_path();
    }

    return 0;
}