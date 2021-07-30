#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int N, M;
int result;
int board[50][50];
bool vis[13];
vector<pair<int, int> > h, ck;

int distance(pair<int, int> a, pair<int, int> b) {
  return abs(a.X - b.X) + abs(a.Y - b.Y);
}

void DFS(int n, int cnt) {
  if (cnt == M) {
    int tmp = 0;
    for (int i = 0; i < h.size(); ++i) {
      int d = 100000;
      for (int j = 0; j < ck.size(); ++j) 
        if (vis[j]) d = min(d, distance(h[i], ck[j]));
      tmp += d;
    }
    result = min(result, tmp);
    return;
  }

  if (n == ck.size()) return;

  vis[n] = true;
  DFS(n + 1, cnt + 1);
  vis[n] = false;
  DFS(n + 1, cnt);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> board[i][j];
      if (board[i][j] == 1)
        h.push_back({i, j});
      else if (board[i][j] == 2)
        ck.push_back({i, j});
    }
  }

  result = 100000;
  DFS(0, 0);
  cout << result;
}