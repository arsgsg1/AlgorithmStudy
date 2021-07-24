#include <iostream>
#include <algorithm>

using namespace std;

int a[10001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;

  for (int i = 0; i < N; ++i) cin >> a[i];
  sort(a, a + N);

  long long ans = 0;

  for (int i = 0; i < N; ++i) {
    int left = i + 1;
    int right = N - 1;
    while (left < right) {
      int sum = a[left] + a[right] + a[i];
      if (sum > 0) {
        --right;
      } else if (sum < 0) {
        ++left;
      } else {
        if (a[left] == a[right]) {
          ans += (right - left + 1) * (right - left) / 2;
          break;
        } else {
          int cntL = 0;
          int cntR = 0;
          int idxL = left;
          int idxR = right;
          while (a[idxL] == a[left]) {
            ++idxL;
            ++cntL;
          }
          while (a[idxR] == a[right]) {
            --idxR;
            ++cntR;
          }
          ans += cntL * cntR;
          left = idxL;
          right = idxR;
        }
      }
    }
  }

  cout << ans;
  return 0;
}