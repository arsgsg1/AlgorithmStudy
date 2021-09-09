#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#define EMPTY 0
#define WALL 1

using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int INF = 2e9;
const int MAX = 1000;

int map[MAX][MAX];
int dp[MAX][MAX][11][2]; // [x][y][w][d] w : 부순 벽의 수, d : 0이면 낮, 1이면 밤
int n, m, k;

int main() {
    int answer = INF;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%1d", &map[i][j]);
    
    queue<tuple<int, int, int, int>> q;
    q.push(make_tuple(0, 0, 0, 0));
    dp[0][0][0][0] = 1;
    while (!q.empty()) {
        int x, y, w, d;
        tie(x, y, w, d) = q.front();
        int cur = dp[x][y][w][d];
        q.pop();
        
        if (!dp[x][y][w][1 - d]) {
            dp[x][y][w][1 - d] = cur + 1;
            q.push(make_tuple(x, y, w, 1 - d));
        }
        
        if (x == n - 1 && y == m - 1) {
            answer = min(answer, cur);
            continue;
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            
            if (map[nx][ny] == EMPTY && !dp[nx][ny][w][1 - d]) {
                dp[nx][ny][w][1 - d] = cur + 1;
                q.push(make_tuple(nx, ny, w, 1 - d));
            } else if (map[nx][ny] == WALL && !dp[nx][ny][w + 1][1 - d] && d == 0 && w < k) {
                dp[nx][ny][w + 1][1 - d] = cur + 1;
                q.push(make_tuple(nx, ny, w + 1, 1 - d));
            }
        }
    }
    printf("%d\n", answer == INF ? -1 : answer);
    return 0;
}
