#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#define INF      1e9
using namespace std;

int n, m, START, END;
int shortest_time, delayed_time;
vector<int> parents;
vector<int> dist;
vector<vector<pair<int, int> > > graph;
vector<pair<int, int> > shortest_path;

void reset() {
    for(int i = 0; i <= n; i++) {
        parents[i] = INF;
        dist[i] = INF;
    }
}

void dijkstra(int start, int end) { //  검문할 간선의 시작 정점과 끝 정점 번호
    priority_queue<pair<int, int> > pq;
    dist[START] = 0;
    parents[START] = START;
    pq.push(make_pair(dist[START], START));

    while(!pq.empty()) {
        int cost = -pq.top().first;  //  현재 노드 cur까지의 비용
        int cur = pq.top().second;  //  현재 노드
        pq.pop();

        if(cost > dist[cur])    //  현재 노드가 큐에서 이미 처리된 적 있을 경우
            continue;

        for(int i = 0; i < graph[cur].size(); i++) {
            if((cur == start && graph[cur][i].first == end) || 
                (cur == end && graph[cur][i].first == start))   //  검문 중인 간선일 경우
                continue;

            if(cost + graph[cur][i].second < dist[graph[cur][i].first]) {
                dist[graph[cur][i].first] = cost + graph[cur][i].second;
                parents[graph[cur][i].first] = cur;
                pq.push(make_pair(-dist[graph[cur][i].first], graph[cur][i].first));
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    START = 1;
    END = n;
    graph.assign(n + 1, vector<pair<int, int> >());
    parents.assign(n + 1, INF);
    dist.assign(n + 1, INF);

    for(int i = 0; i < m; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        graph[a].push_back(make_pair(b, t));
        graph[b].push_back(make_pair(a, t));
    }

    dijkstra(INF, INF); //  처음엔 검문이 없으므로 검문할 간선의 두 정점을 INF, INF로 함
    shortest_time = dist[END];

    if(shortest_time == INF) {  //  검문 없이도 탈출할 수 없는 경우
        cout << 0 << '\n';  //  검문 하나 마나 차이가 없으므로 효과 0
        return 0;
    }

    int cur = END;
    while(parents[cur] != cur) {
        shortest_path.push_back(make_pair(cur, parents[cur]));
        cur = parents[cur];
    }

    for(int i = shortest_path.size() - 1; i >= 0; i--) {    //  최단 경로에 포함된 간선 중 하나를 골라서 검문함
        int a = shortest_path[i].second;
        int b = shortest_path[i].first;
        //  간선 (a, b)를 검문함

        reset();
        dijkstra(a, b); //  간선 (a, b)를 제외하고 dijkstra 실행

        delayed_time = max(delayed_time, dist[END]);
        if(delayed_time == INF) {   //  도달할 수 없는 경우
            cout << -1 << '\n';
            return 0;
        } 
    }

    cout << delayed_time - shortest_time << '\n';

    return 0;
}