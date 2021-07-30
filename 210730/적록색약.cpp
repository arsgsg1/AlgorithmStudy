#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int N;
char board[101][101];
bool vis[101][101];
int delX[] = {1, 0, -1, 0};
int delY[] = {0, 1, 0, -1};

void BFS(int i, int j) {
  queue<pair<int, int> > q;
  q.push({i, j});
  vis[i][j] = true;
  while (!q.empty()) {
    pair<int, int> t = q.front();
    q.pop();
    for (int k = 0; k < 4; ++k) {
      int a = t.X + delX[k];
      int b = t.Y + delY[k];
      if (a < 0 || a >= N || b < 0 || b >= N) continue;
      if (vis[a][b]) continue;
      if (board[t.X][t.Y] != board[a][b]) continue;
      q.push({a, b});
      vis[a][b] = true;
    }
  }
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
      cin >> board[i][j];


  int cnt = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
        if (vis[i][j]) continue;
        BFS(i, j);
        ++cnt;
    }
  }
  cout << cnt << ' ';


  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
      vis[i][j] = false;

  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
      if (board[i][j] == 'R') board[i][j] = 'G';

  cnt = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
        if (vis[i][j]) continue;
        BFS(i, j);
        ++cnt;
    }
  }
  cout << cnt;
}