//  https://programmers.co.kr/learn/courses/30/lessons/81302?language=cpp

#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>
#include <iostream>
#define INF 1e9

using namespace std;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

vector<vector<char> > graph;
vector<pair<int, int> > pos;    //  사람 위치

bool m_distance(int y1, int x1, int y2, int x2) {
    //  맨하턴 거리가 2 이하면 true, 초과면 false
    return (((abs(y2 - y1) + abs(x2 - x1))) <= 2);
}

bool bfs(int y, int x) {
    bool ret = true;    //  거리 두기 지켜짐
    queue<pair<int, int> > q;
    vector<vector<int> > dist(5, vector<int>());  //  (y, x) 사람으로부터의 거리 테이블
    for(int i = 0; i < 5; i++)
        dist[i].assign(5, INF);
    dist[y][x] = 0;
    q.push(make_pair(y, x));

    while(!q.empty()) {
        int ny, nx, cy, cx;
        cy = q.front().first;
        cx = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            ny = cy + dy[i];
            nx = cx + dx[i];

            if(ny < 0 || ny >= 5 || nx < 0 || nx >= 5 || graph[ny][nx] == 'X' || dist[ny][nx] != INF)
                continue;
            else {
                dist[ny][nx] = dist[cy][cx] + 1;
                q.push(make_pair(ny, nx));
                if(graph[ny][nx] == 'P') {
                    if(m_distance(y, x, ny, nx)) {
                        ret = false;
                        break;
                    }
                }
            }
        }   //  for-end

        if(!ret) break;

    }   //  while-end

    // cout << '\n';
    // for(int i = 0; i < 5; i++) {
    //     for(int j = 0; j < 5; j++) {
    //         if (dist[i][j] == INF)
    //             cout << -1 << ' ';
    //         else
    //             cout << dist[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    return ret;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    // cout << places.size() << '\n';
    for(int tc = 0; tc < 5; tc++) {
        graph.resize(5);
        for(int i = 0; i < 5; i++)
            graph[i].assign(5, '0');

        cout << '\n';
        // for(int i = 0; i < 5; i++) {
        //     for(int j = 0; j < 5; j++) 
        //         cout << graph[i][j] << ' ';
        //     cout << "\n";
        // }

        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                graph[i][j] = places[tc][i][j];
                if(graph[i][j] == 'P') 
                    pos.push_back(make_pair(i, j));
            }
        }

        // for(int i = 0; i < 5; i++) {
        //     for(int j = 0; j < 5; j++) 
        //         cout << graph[i][j] << ' ';
        //     cout << "\n";
        // }

        // for(int i = 0; i < pos.size(); i++) 
        //     cout << "P" << i + 1 << ": (" << pos[i].first << ", " << pos[i].second <<"), ";
        // cout << '\n';

        bool ok = true;
        for(int j = 0; j < pos.size(); j++) {
            if(!bfs(pos[j].first, pos[j].second)) {
                answer.push_back(0);
                ok = false;
                break;
            }
        }
        if(ok) answer.push_back(1);
        

        for(int i = 0; i < 5; i++)
            while(!graph[i].empty())
                graph[i].pop_back();
        while(!graph.empty())
            graph.pop_back();
        while(!pos.empty())
            pos.pop_back();
    }
    
    return answer;
}