// https://programmers.co.kr/learn/courses/30/lessons/72413
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define INF       1e9

using namespace std;

vector<int> dist1, dist2, dist3;    //  시작점 s에서 모든 점으로의 거리, 도착점 a에서 모든 점으로의 거리, 도착점 b에서 모든 점으로의 거리
vector<vector<pair<int, int> > > graph;

void dijkstra(vector<int>& dist, int n, int start) {
    priority_queue<pair<int, int> > pq;
    dist[start] = 0;
    pq.push(make_pair(-dist[start], start));

    while(!pq.empty()) {    
        int d = -pq.top().first;
        int now = pq.top().second; 
        pq.pop();
        if(dist[now] < d) continue;
        for(int i = 0; i < graph[now].size(); i++) {
            int cost = d + graph[now][i].second;
            if(cost < dist[graph[now][i].first]) {
                dist[graph[now][i].first] = cost;
                pq.push(make_pair(-cost, graph[now][i].first));
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int> > fares) {
    int answer = 0;

    graph.assign(n + 1, vector<pair<int, int> >());
    
    dist1.assign(n + 1, INF);
    dist2.assign(n + 1, INF);
    dist3.assign(n + 1, INF);
    
    for(int i = 0; i < fares.size(); i++) {
        int a, b, cost;
        a = fares[i][0];
        b = fares[i][1];
        cost = fares[i][2];
        graph[a].push_back(make_pair(b, cost));
        graph[b].push_back(make_pair(a, cost));
    }

    // // int d1 = dijkstra(n, s, a) + dijkstra(n, s, b); //  따로 따로 가는 경우
    // // int d2 = INF, tmp;  //  특정 지점까지 같이 간 후 따로 가는 경우
    // // for(int i = 1; i <= n; i++) { 
    // //     if(i != s) {    //  i 지점까지 같이 감
    // //         tmp = dijkstra(n, s, i);
    // //         if(tmp == INF) continue;    //  i 지점에 갈 수 없는 경우 skip
    // //         tmp += dijkstra(n, i, a) + dijkstra(n, i, b);
    // //         d2 = min(d2, tmp);
    // //     }
    // // }

    // answer = min(d1, d2);

    dijkstra(dist1, n, s);
    // for(int i = 1; i <= n; i++)
    //     cout << dist1[i] << ' ';
    // cout << '\n';

    int individual = dist1[a] + dist1[b];   //  s에서 a, b 각각 따로 간 비용 합
    int together = INF;

    dijkstra(dist2, n, a);  //  a에서 다른 점으로의 최단거리(다른 점에서 a로의 최단거리도 됨)
    dijkstra(dist3, n, b);  //  b에서 다른 점으로의 최단거리(다른 점에서 b로의 최단거리도 됨)
    //  for(int i = 1; i <= n; i++)
    //     cout << dist2[i] << ' ';
    // cout << '\n';
    //  for(int i = 1; i <= n; i++)
    //     cout << dist3[i] << ' ';
    // cout << '\n';
    
    for(int i = 1; i <= n; i++) {
        if(i != s) {    //  시작점 제외
            if(dist1[i] == INF || dist2[i] == INF || dist3[i] == INF)  //  i에서 s, a, b로 도달할 수 없는 경우 skip
                continue;

            // cout << '\n';
            // cout << "i = " << i << '\n';
            // cout << "s -> i : " << dist1[i] << '\n';
            // cout << "i -> a : " << dist2[i] << '\n'; 
            // cout << "i -> b : " << dist3[i] << '\n'; 
            // cout << "합 : " << dist1[i] + dist2[i] + dist3[i] << '\n';
            together = min(together, dist1[i] + dist2[i] + dist3[i]);
        }
    }

    answer = min(individual, together);

    return answer;
}