#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int components;
int years;
vector<vector<int> > glacier;
vector<vector<int> > melted;
vector<vector<bool> > visit;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

void reset() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            melted[i][j] = 0;
            visit[i][j] = false;
        }
    }
}

void melt() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
         glacier[i][j] = max(0, glacier[i][j] - melted[i][j]);
    }
}

void bfs(int y, int x) {
    queue<pair<int, int> > q;
    visit[y][x] = true;
    q.push(make_pair(y, x));

    while(!q.empty()) {
        int cy, cx, ny, nx;
        cy = q.front().first;
        cx = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            ny = cy + dy[i];
            nx = cx + dx[i];

            if(glacier[ny][nx] == 0) {
                melted[cy][cx] += 1;
                continue;
            }
            else if(visit[ny][nx] == false) {
                visit[ny][nx] = true;
                q.push(make_pair(ny, nx));
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    glacier.resize(n);
    melted.resize(n);
    visit.resize(n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int x;
            cin >> x;
            glacier[i].push_back(x);
            melted[i].push_back(0);
            visit[i].push_back(false);
        }
    }

    while(true) {
        reset();
        components = 0;

        bool is_bfs = false;
        for(int i = 1; i < n - 1; i++) {
            for(int j = 1; j < m - 1; j++) {
                if(glacier[i][j] != 0 && !visit[i][j]) {
                    bfs(i, j);
                    components++;
                }
            }
        }

        if(components == 0) {
            years = 0;
            break;
        }
        else if(components == 1) {
            melt();
            years++;
            continue;
        }
        else break;
    }

    cout << years << '\n';
    return 0;
}