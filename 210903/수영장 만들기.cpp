#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int map[50][50];
bool visited[50][50];
int n, m, answer;

void bfs(int sx, int sy, int k) {
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = true;
    int cnt = 1;
    bool flag = true;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                flag = false;
                continue;
            }
            if (!visited[nx][ny] && map[nx][ny] <= k) {
                visited[nx][ny] = true;
                q.push({nx, ny});
                cnt++;
            }
        }
    }
    if (flag) answer += cnt;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%1d", &map[i][j]);
    
    for (int k = 1; k <= 9; k++) {
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (map[i][j] <= k && !visited[i][j])
                    bfs(i, j, k);
    }
    printf("%d\n", answer);
    return 0;
}
