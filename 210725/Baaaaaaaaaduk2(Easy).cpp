#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

int n, m, result;
int ncomp2;
vector<vector<int> > field;
vector<vector<bool> > visited;
vector<vector<pair<int, int> > > comp2;

void bfs(int y, int x) {
    queue<pair<int, int> > q;
    visited[y][x] = true;
    q.push(make_pair(y, x));

    comp2.push_back(vector<pair<int, int> >());
    comp2[ncomp2].push_back(make_pair(y, x));

    while(!q.empty()) {
        int cy, cx, ny, nx;
        cy = q.front().first;
        cx = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            ny = cy + dy[i];
            nx = cx + dx[i];
            
            if(0 <= ny && ny < n && 0 <= nx && nx < m) {
                if(field[ny][nx] == 2 && !visited[ny][nx]) {
                    visited[ny][nx] = true;
                    q.push(make_pair(ny, nx));
                    comp2[ncomp2].push_back(make_pair(ny, nx));
                }
            }
        }
    }
}

int isolated(int fy, int fx, int sy, int sx) {
    int ret = 0;
    for(int i = 0; i < comp2.size(); i++) {
        bool isol = true;
        for(int j = 0; j < comp2[i].size(); j++) {
            int cy = comp2[i][j].first;
            int cx = comp2[i][j].second;
            int ny, nx;

            for(int d = 0; d < 4; d++) {
                ny = cy + dy[d];
                nx = cx + dx[d];

                if(ny < 0 || ny >= n || nx < 0 || nx >= m)
                    continue;
                else if(ny == fy && nx == fx)
                    continue;
                else if(ny == sy && nx == sx)
                    continue;
                else if(field[ny][nx] == 2 || field[ny][nx] == 1)
                    continue;
                else if(field[ny][nx] == 0) {
                    isol = false;
                    break;
                }
            }
            if(!isol) break;
        }
        if(isol) ret += comp2[i].size();
    }
    return ret;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    field.assign(n, vector<int>());
    visited.assign(n, vector<bool>());

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int x;
            cin >> x;
            field[i].push_back(x);
            visited[i].push_back(false);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(field[i][j] == 2 && !visited[i][j]) {
                bfs(i, j);
                ncomp2 += 1;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(field[i][j] != 0) continue;
            for(int k = i; k < n; k++) {
                if(k == i) {
                    for(int l = j + 1; l < m; l++) {
                        if(field[k][l] != 0) continue;
                        result = max(result, isolated(i, j, k, l));
                    }
                }
                else {
                    for(int l = 0; l < m; l++) {
                        if(field[k][l] != 0) continue;
                        result = max(result, isolated(i, j, k, l));
                    }
                }
            }
        }
    }

    cout << result << '\n';
    return 0;
}