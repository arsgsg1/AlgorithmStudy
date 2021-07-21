//  https://programmers.co.kr/learn/courses/30/lessons/81304

// #include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1000000000

using namespace std;

vector<vector<int> > graph;
vector<bool> is_trap;
vector<int> dist;

// void print_graph(int n) {
//     for(int i = 1; i <= n; i++) {
//         for(int j = 1; j <= n; j++) {
//             if(graph[i][j] == INF)
//                 cout << -1 << ' ';
//             else
//                 cout << graph[i][j] << ' ';
//         }
//         cout << '\n';
//     }
// }

void change_directions(int n, int trap) {
    for(int i = 1; i <= n; i++)
        swap(graph[trap][i], graph[i][trap]);
}

void bfs(int n, int start, int end) {
    queue<int> q;
    vector<bool> visit(n + 1, false);

    q.push(start);
    visit[start] = true;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        if(is_trap[cur])
            change_directions(n, cur);

        for(int i = 1; i <= n; i++) {
            if(graph[cur][i] != 0 && graph[cur][i] != INF && !visit[i]) {
                if(i == end) {
                    dist[end] = dist[cur] + graph[cur][i];
                    return; 
                }
                
                if(!is_trap[i])
                    visit[i] = true;
                q.push(i);
                dist[i] = dist[cur] + graph[cur][i];
            }
        }
    }

    return;
}

int solution(int n, int start, int end, vector<vector<int> > roads, vector<int> traps) {
    // int answer;

    graph.resize(n + 1);
    is_trap.assign(n + 1, false);
    dist.assign(n + 1, INF);
    dist[start] = 0;

    for(int i = 0; i <= n; i++) {
        graph[i].assign(n + 1, INF);
        graph[i][i] = 0;
    }

    for(int i = 0; i < roads.size(); i++) {
        int a, b, c;
        a = roads[i][0];
        b = roads[i][1];
        c = roads[i][2];

        graph[a][b] = min(graph[a][b], c);
    }

    for(int i = 0; i < traps.size(); i++)
        is_trap[traps[i]] = true;

    // change_directions(n, 2);    
    // change_directions(n, 3);
    // change_directions(n, 2);

    // print_graph(n);
    
    bfs(n, start, end);
    return dist[end];
}