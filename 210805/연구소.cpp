#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define NONE      -1
using namespace std;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

int n, m;
vector<vector<int> > lab, original;
vector<pair<int, int> > init_virus;

void reset_lab() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            lab[i][j] = original[i][j];
    }
}

void print_lab() {
    cout << '\n';
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cout << lab[i][j] << ' ';
        cout << '\n';
    }
}

int safe_zone() {
    int ret = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(lab[i][j] == 0) ret += 1;
        }
    }

    return ret;
}

void bfs() {
    queue<pair<int, int> > q;
    int num = 0;
    for(int i = 0; i < init_virus.size(); i++) {
        q.push(make_pair(init_virus[i].first, init_virus[i].second));
        num++;
    }

    while(!q.empty()) {
        int tmp = 0;
        for(int i = 0; i < num; i++) {
            int cy = q.front().first;
            int cx = q.front().second;
            int ny;
            int nx;
            q.pop();

            for(int j = 0; j < 4; j++) {
                ny = cy + dy[j];
                nx = cx + dx[j];

                if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                else if(lab[ny][nx] != 0) continue;
                else {
                    lab[ny][nx] = 2;
                    q.push(make_pair(ny, nx));
                    tmp += 1;
                }
            }
        }
        num = tmp;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;

    lab.assign(n, vector<int>());
    original.assign(n, vector<int>());

    for(int i = 0; i < n; i++) {
        lab[i].assign(m, 0);
        original[i].assign(m, 0);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> lab[i][j];
            original[i][j] = lab[i][j];

            if(lab[i][j] == 2)
                init_virus.push_back(make_pair(i, j));
        }
    }

    int ans = 0;
    int i1, j1, i2, j2, i3, j3;

    for(i1 = 0; i1 < n; i1++) {
        for(j1 = 0; j1 < m; j1++) { //  첫 번째 벽
            if(lab[i1][j1] != 0) continue;
            lab[i1][j1] = 1;

            for(i2 = i1; i2 < n; i2++) {
                if(i2 == i1) j2 = j1 + 1;
                else j2 = 0;

                for(; j2 < m; j2++) {   //  두 번째 벽
                    if(lab[i2][j2] != 0) continue;
                    lab[i2][j2] = 1;
                
                    for(i3 = i2; i3 < n; i3++) {
                        if(i3 == i2) j3 = j2 + 1;
                        else j3 = 0;

                        for(; j3 < m; j3++) {   //  세 번째 벽
                            if(lab[i3][j3] != 0) continue;
                            lab[i3][j3] = 1;
                        
                            bfs();
                            ans = max(ans, safe_zone());
                            reset_lab();    //  다음 경우(세 번째 벽 위치 변경)를 위해 연구소 초기화
                            lab[i1][j1] = 1;
                            lab[i2][j2] = 1;
                        }
                    }
                    lab[i2][j2] = 0;    //  다음 경우(두 번째 벽 위치 변경)를 위해 연구소 초기화
                }
            }
            lab[i1][j1] = 0;    //  다음 경우(첫 번째 벽 위치 변경)를 위해 연구소 초기화
        }
    }  

    cout << ans << '\n';
    return 0; 
}