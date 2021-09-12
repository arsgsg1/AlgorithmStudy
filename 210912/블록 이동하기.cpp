#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

struct Robot {
    int x[2], y[2];
    int d[2];
    int cnt;
};

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int chk[102][102][4];

int solution(vector<vector<int>> board) {
    int n = board.size();
    memset(chk, 0, sizeof(chk));
    vector<vector<int>> map(n + 2, vector<int>(n + 2, 1));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) map[i + 1][j + 1] = board[i][j];

    queue<Robot> q;
    q.push({1, 1, 1, 2, 0, 2, 0});
    chk[1][1][0] = chk[1][2][2] = 1;

    while (!q.empty()) {
        Robot t = q.front();
        q.pop();
        if ((t.x[0] == n && t.y[0] == n) || (t.x[1] == n && t.y[1] == n))
            return t.cnt;
        for (int i = 0; i < 4; ++i) {
            int nx1 = t.x[0] + dx[i], ny1 = t.y[0] + dy[i];
            int nx2 = t.x[1] + dx[i], ny2 = t.y[1] + dy[i];
            int d1 = t.d[0], d2 = t.d[1];
            if (map[nx1][ny1] || map[nx2][ny2]) continue;
            if (chk[nx1][ny1][d1] || chk[nx2][ny2][d2]) continue;
            chk[nx1][ny1][d1] = chk[nx2][ny2][d2] = 1;
            q.push({nx1, nx2, ny1, ny2, d1, d2, t.cnt + 1});
        }
        for (int i = -1; i <= 1; ++i) {
            if (i == 0) continue;
            for (int j = 0; j < 2; ++j) {
                int x = t.x[j], y = t.y[j];
                int prev_d = t.d[j];
                int d = (prev_d + i + 4) % 4;
                int oppo_d = (d + 2) % 4;

                int nx = x + dx[d], ny = y + dy[d];
                int rx = nx + dx[prev_d], ry = ny + dy[prev_d];
                if (map[nx][ny] || map[rx][ry]) continue;
                if (chk[x][y][d] || chk[nx][ny][oppo_d]) continue;
                chk[x][y][d] = chk[nx][ny][oppo_d] = 1;
                q.push({x, nx, y, ny, d, oppo_d, t.cnt + 1});
            }
        }
    }

    return -1;
}