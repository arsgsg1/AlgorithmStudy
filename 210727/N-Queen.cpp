#include <bits/stdc++.h>

using namespace std;

int N;
int cnt = 0;
bool vis1[40];
bool vis2[40];
bool vis3[40];

void bt(int k) {
  if (k == N) {
    ++cnt;
    return;
  }

  for (int i = 0; i < N; ++i) {
    if (vis1[i] || vis2[i + k] || vis3[k - i + N - 1]) continue;
    vis1[i] = true;
    vis2[i + k] = true;
    vis3[k - i + N - 1] = true;
    bt(k + 1);
    vis1[i] = false;
    vis2[i + k] = false;
    vis3[k - i + N - 1] = false;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  bt(0);
  cout << cnt;
}