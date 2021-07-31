#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#define OFF         0   //  불 꺼진 방
#define ON          1   //  불은 켜졌지만 스위치를 확인하지 않은 방
#define END         2   //  불 켜지고 스위치를 확인한 방(존재하면 누르고, 아니면 pass)
using namespace std;

int n, m, ans = 1;
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
int sy, sx;

vector<vector<int> > rooms; // n * n 방
vector<vector<bool> > visited;  //  n * n 방 방문 여부
vector<vector<vector<pair<int, int> > > > light;    //  (y, x) 방에서 불을 켤수 있는 방들 

void reset_visited(int y, int x) {  
    //  새로 불이 켜진 방이 있을 경우, 불을 켠 방을 제외하고 다시 방문할 수 있음
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i != y || j != x)    //  현재 방을 제외하고 모두 방문하지 않은 걸로 함
                visited[i][j] = false;
        }
    }
}

bool light_on(int y, int x) {   //  해당 방에서 누를 수 있는 모든 스위치를 누름
    int ret = false;    //  불이 새로 켜진 방이 없음
    for(int i = 0; i < light[y][x].size(); i++) {
        if(rooms[light[y][x][i].first][light[y][x][i].second] == OFF) {
            //  아직 불이 안켜진 방의 스위치를 눌러 불을 새로 킴.
            ret = true; //  불이 새로 켜진 방이 있음
            rooms[light[y][x][i].first][light[y][x][i].second] = ON;
            ans += 1;   //  정답(불 켜진 방의 수) 1 증가
        }
    }
    rooms[y][x] = END;  //  이 방의 스위치를 확인함(존재하건 아니건)

    return ret;
}

void bfs() {
    queue<pair<int, int> > q;
    visited[0][0] = true;   //  (0, 0) 방을 방문
    q.push(make_pair(0, 0));    //  큐에 삽입

    while(!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;  //  새로 방문한 방
        q.pop();

        if(rooms[cy][cx] != OFF) {   //  아직 스위치를 확인하지 않은 방의 경우
            if(light_on(cy, cx)) {  //  이 방에서 새로 불 켤 수 있는 방이 있을 경우
                reset_visited(cy, cx);  //  현재 방을 제외하고 다시 방문할 수 있게 방문 기록을 제거함
                while(!q.empty()) q.pop();  //  현재까지 방문하여 큐에 삽입된 방들을 모두 제거 후 현재 방부터 다시 시작
            }
            //  light_on이 false일 경우 방문 기록 초기화없이 현재 방 확인 후 큐에 남아 있는 다음 방들을 확인함
        }  

        for(int i = 0; i < 4; i++) {    //  현재 방의 주변 방들을 확인함
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            //  범위를 벗어나거나 불꺼진 방의 경우 skip
            if(ny < 0 || ny >= n || nx < 0 || nx >= n || rooms[ny][nx] == OFF) continue;

            if(!visited[ny][nx]) {  //  방문하지 않았거나 방문 기록이 초기화된 방의 경우
                visited[ny][nx] = true; //  방문
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

    rooms.assign(n, vector<int>());
    visited.assign(n, vector<bool>());
    light.assign(n, vector<vector<pair<int, int> > >());
    for(int i = 0; i < n; i++) 
        light[i].assign(n, vector<pair<int, int> >());

    for(int i = 0; i < n; i++) {
        rooms[i].assign(n, OFF);
        visited[i].assign(n, false);
    }
    rooms[0][0] = ON;

    for(int i = 0; i < m; i++) {
        int y, x, a, b;
        cin >> y >> x >> a >> b;

        // cout << "in input\n";
        light[y - 1][x - 1].push_back(make_pair(a - 1, b - 1));
    }

    bfs();

    cout << ans << '\n';

    return 0;
}