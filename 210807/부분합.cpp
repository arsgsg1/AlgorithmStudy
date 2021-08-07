#include <bits/stdc++.h>
 
using namespace std;
 
int arr[100000];
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) cin >> arr[i];

  int ans = INT_MAX;
  int len = 0;
  
  int left = 0; 
  int right = 0;
  int sum = arr[0];

  while (left <= right && right < n) {
    if (sum < m) {
      if (right < n) {
        right += 1;
        sum += arr[right];
      }
    }
    else {
      len = right - left + 1;
      if (ans > len) ans = len;
      if (left <= right) {
        sum -= arr[left];
        left++;
      }
    }
  }

  if (ans == INT_MAX) cout << 0;
  else cout << ans;
}