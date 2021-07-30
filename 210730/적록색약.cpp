#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

int n, ans1, ans2;
vector<vector<char> > grid;
vector<vector<bool> > visited;

void reset_visited() {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            visited[i][j] = false;
}

void bfs(int y, int x, char c, bool norm) {
    queue<pair<int, int> > q;
    visited[y][x] = true;
    q.push(make_pair(y, x));

    while(!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny < 0 || ny >= n || nx < 0 || nx >= n)
                continue;
            
            if(norm || c == 'B') {
                if(!visited[ny][nx] && grid[ny][nx] == c) {
                    visited[ny][nx] = true;
                    q.push(make_pair(ny, nx));
                }
                else continue;
            }
            else {
                if(!visited[ny][nx] && grid[ny][nx] != 'B') {
                    visited[ny][nx] = true;
                    q.push(make_pair(ny, nx));
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
    cin.ignore();

    grid.assign(n, vector<char>());
    for(int i = 0; i < n; i++)
        grid[i].assign(n, ' ');
    visited.assign(n, vector<bool>());
    for(int i = 0; i < n; i++)
        visited[i].assign(n, false);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            char c;
            cin >> c;
            grid[i][j] = c;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!visited[i][j]) {
                bfs(i, j, grid[i][j], true);
                ans1 += 1;
            }
        }
    }
    reset_visited();

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!visited[i][j]) {
                bfs(i, j, grid[i][j], false);
                ans2 += 1;
            }
        }
    }

    cout << ans1 << " " << ans2 << '\n';
    return 0;
}