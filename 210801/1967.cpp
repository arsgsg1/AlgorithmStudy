#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int ans = 0;
bool eList[10001];
bool vis[10001];
vector<pair<int, int> > graph[10001];

int start;

void DFS(int idx, int d) {
  if (idx != start && eList[idx]) {
    ans = max(d, ans);
    return;
  }
  for (int i = 0; i < graph[idx].size(); ++i) {
    int a = graph[idx][i].X;
    int b = graph[idx][i].Y;
    if (vis[a]) continue;
    vis[a] = true;
    DFS(a, d + b);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n - 1; ++i) {
    int a, b, l;
    cin >> a >> b >> l;
    eList[a] = false;
    eList[b] = true;
    graph[a].push_back({b, l});
    graph[b].push_back({a, l});
  }

  if (graph[1].size() == 1) eList[1] = true;

  for (int i = 1; i <= 10000; ++i) {
    if (!eList[i]) continue;
      memset(vis, false, sizeof(bool) * 10001);
      start = i;
      vis[i] = true;
      DFS(i, 0);
  }

  cout << ans;
}