#include <bits/stdc++.h>

using namespace std;

typedef struct lecture {
  int st, ed;
} lec;

struct compare {
  bool operator()(lec a, lec b) {
    if (a.st == b.st) return a.ed > b.ed;
    return a.st > b.st;
  }
};

priority_queue<lec, vector<lec>, compare> pq;
priority_queue<int, vector<int>, greater<int>> tq;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int cnt;
  cin >> cnt;

  for (int i = 0; i < cnt; ++i) {
    int s, t;
    cin >> s >> t;
    pq.push({s,t});
  }

  while (!pq.empty()) {
    lec a = pq.top();
    pq.pop();

    if (tq.empty()) {
      tq.push(a.ed);
    } else {
      if (tq.top() <= a.st) tq.pop();
      tq.push(a.ed);
    }
  }

  printf("%d", tq.size());

  return 0;
}