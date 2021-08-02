#include <bits/stdc++.h>

using namespace std;

int N;
int A[1001];
int DP[1001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;
  for (int i = 1; i <= N;++i) {
    cin >> A[i];
  }

  int ans = 1;
  for (int i = 1; i <= N;++i) {
    DP[i] = 1;
    for (int j = 1; j <= i;++j) {
      if (A[j] < A[i] && DP[j] >= DP[i]) DP[i] = DP[j] + 1;
    }
    ans = max(DP[i], ans);
  }
  cout << ans;
}