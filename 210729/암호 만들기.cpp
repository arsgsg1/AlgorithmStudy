#include <bits/stdc++.h>

using namespace std;

int L, C;
char alpha[20];

void bt(int idx, int cnt, int con, int vow, string s) {
  if (L == cnt) {
    if (con >= 2 && vow >= 1) cout << s << '\n';
    return;
  }
  if (idx == C) return;
  char ch = alpha[idx];
  if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
    bt(idx + 1, cnt + 1, con, vow + 1, s + ch);
  else bt(idx + 1, cnt + 1, con + 1, vow, s + ch);
  bt(idx + 1, cnt, con, vow, s);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> L >> C;
  for (int i = 0; i < C; ++i) cin >> alpha[i];
  sort(alpha, alpha + C);
  bt(0, 0, 0, 0, "");
}