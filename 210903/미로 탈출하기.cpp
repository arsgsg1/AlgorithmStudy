#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int MAX = 500;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

unordered_map<char, int> dir;
char map[MAX][MAX];
bool visited[MAX][MAX];
int check[MAX][MAX];
int n, m, answer;

void bfs(int sx, int sy) {
    queue<pair<int, int>> q;
    int x = sx, y = sy;
    bool pass = false;
    while (1) {
        if (x < 0 || x >= n || y < 0 || y >= m || check[x][y] == 1) {
            pass = true;
            break;
        }
        if (visited[x][y] || check[x][y] == 0) {
            pass = false;
            break;
        }
        q.push({x, y});
        visited[x][y] = true;
        int nx = x + dx[dir[map[x][y]]];
        int ny = y + dy[dir[map[x][y]]];
        x = nx;
        y = ny;
    }
    
    if (pass) answer += q.size();
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        visited[x][y] = false;
        check[x][y] = pass;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    dir['R'] = 0;
    dir['D'] = 1;
    dir['L'] = 2;
    dir['U'] = 3;
    
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];
    
    memset(check, -1, sizeof(check));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (check[i][j] == -1) bfs(i, j);
        }
    }
    
    cout << answer << endl;
    return 0;
}
