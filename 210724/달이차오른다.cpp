#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

vector<vector<char> > graph;
vector<vector<bool> > visited;
stack<pair<int, int> > visit_path;
vector<bool> keys;

int n, m;
int start_y, start_x;

void print_graph(const char* str) {
    cout << str << '\n';
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cout << graph[i][j] << " ";
        cout << '\n';
    }
    cout << '\n';
}

int bfs() {
    queue<pair<int, pair<int, int> > > q;
    q.push(make_pair(0, make_pair(start_y, start_x)));
    visited[start_y][start_x] = true;

    while(!q.empty()) {
        int val, cy, cx;
        int ny, nx;

        val = q.front().first;
        cy = q.front().second.first;
        cx = q.front().second.second;
        q.pop();

        if(graph[cy][cx] == '1') return val;

        for(int i = 0; i < 4; i++) {
            ny = cy + dy[i];
            nx = cx + dx[i];

            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            else if(visited[ny][nx]) continue;
            else if('a' <= graph[ny][nx] && graph[ny][nx] <= 'z') {
                keys[int(graph[ny][nx] - 'a')] = true;
                visited[ny][nx] = true;
                q.push(make_pair(val + 1, make_pair(ny, nx)));
            }
            else if('A' <= graph[ny][nx] && graph[ny][nx] <= 'Z') {
                if(keys[int(graph[ny][nx] - 'A')]) {
                    visited[ny][nx] = true;
                    q.push(make_pair(val + 1, make_pair(ny, nx)));
                }
            }
            else if(graph[ny][nx] == '.' || graph[ny][nx] == '1') {
                visited[ny][nx] = true;
                q.push(make_pair(val + 1, make_pair(ny, nx)));
            }
        }
    }

    return -1;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    cin.ignore(0);

    graph.resize(n);
    visited.resize(n);
    keys.assign(6, false);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char c;
            cin >> c;
            graph[i].push_back(c);
            visited[i].push_back(false);

            if(c == '0') {
                start_y = i;
                start_x = j;
            }
        }
        cin.ignore(0);
    }

    // print_graph("after input");

    cout << bfs() << '\n';

    return 0;
}