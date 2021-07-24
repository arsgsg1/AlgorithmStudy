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
vector<vector<bool> > visited[1 << 6];

int n, m;
int start_y, start_x;

int get_key(char key, int cur_key) {
    return cur_key | (1 <<  int(key - 'a'));
}

bool is_key(char key, int cur_key) {
    if(((1 << int(key - 'A')) & cur_key) != 0) return true;
    else return false;
}

int bfs() {
    //  value, key, y, x
    queue<pair<pair<int, int>, pair<int, int> > > q;
    q.push(make_pair(make_pair(0, 0), make_pair(start_y, start_x)));
    visited[0][start_y][start_x] = true;
    
    while(!q.empty()) {
        int cval, ckey, cy, cx;
        int nkey, ny, nx;

        cval = q.front().first.first;
        ckey = q.front().first.second;
        cy = q.front().second.first;
        cx = q.front().second.second;
        q.pop();

        if(graph[cy][cx] == '1') return cval;

        for(int i = 0; i < 4; i++) {
            ny = cy + dy[i];
            nx = cx + dx[i];

            if(ny < 0 || ny >= n || nx < 0 || nx >= m) 
                continue;
            else if(visited[ckey][ny][nx]) 
                continue;
            else if(graph[ny][nx] == '#') 
                continue;
            else {
                if(graph[ny][nx] == '.' || graph[ny][nx] == '1' || graph[ny][nx] == '0') {
                    nkey = ckey;
                    visited[nkey][ny][nx] = true;
                    q.push(make_pair(make_pair(cval + 1, nkey), make_pair(ny, nx)));
                }
                else if('a' <= graph[ny][nx] && graph[ny][nx] <= 'f') {
                    nkey = get_key(graph[ny][nx], ckey);
                    visited[nkey][ny][nx] = true;
                    q.push(make_pair(make_pair(cval + 1, nkey), make_pair(ny, nx)));
                }
                else if('A' <= graph[ny][nx] && graph[ny][nx] <= 'F') {
                    nkey = ckey;
                    if(is_key(graph[ny][nx], nkey)) {
                        visited[nkey][ny][nx] = true;
                        q.push(make_pair(make_pair(cval + 1, nkey), make_pair(ny, nx)));
                    }
                }
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

    for(int i = 0; i < (1 << 6); i++) {
        visited[i].assign(n, vector<bool>());
        for(int j = 0; j < n; j++) 
            visited[i][j].assign(n, false);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char c;
            cin >> c;
            graph[i].push_back(c);

            if(c == '0') {
                start_y = i;
                start_x = j;
            }
        }
        cin.ignore(0);
    }

    cout << bfs() << '\n';

    return 0;
}