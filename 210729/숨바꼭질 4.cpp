#include <bits/stdc++.h>

using namespace std;

int board[100001];
bool vis[100001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, K;
  cin >> N >> K;

  for (int i = 0; i < 100001; ++i) board[i] = -1;

  queue<int> q;
  q.push(N);
  vis[N] = true;
  while (!q.empty()) {
    int tmp = q.front();
    q.pop();
    if (tmp == K) break;
    if (tmp + 1 <= 100000 && vis[tmp + 1] == false) {
      board[tmp + 1] = tmp;
      vis[tmp + 1] = true;
      q.push(tmp + 1);
    }
    if (tmp - 1 >= 0 && vis[tmp - 1] == false) {
      board[tmp - 1] = tmp;
      vis[tmp - 1] = true;
      q.push(tmp - 1);
    }
    if (tmp * 2 <= 100000 && vis[tmp * 2] == false) {
      board[tmp * 2] = tmp;
      vis[tmp * 2] = true;
      q.push(tmp * 2);
    }
  }

  vector<int> ans;
  int cnt = -1;
  int a = K;
  while (a != -1) {
    ans.push_back(a);
    a = board[a];
    ++cnt;
  }

  cout << cnt << '\n';
  while (ans.size() != 0) {
    cout << ans.back() << ' ';
    ans.pop_back();
  }
}