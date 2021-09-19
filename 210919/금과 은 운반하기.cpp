#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    int n = g.size();
    long long lo = 0, hi = 1e15;
    long long answer = hi;
    while (lo <= hi) {
        long long mid = (lo + hi) >> 1;
        long long total = 0, gold = 0, silver = 0;
        for (int i = 0; i < n; i++) {
            long long cnt = (mid + t[i]) / (t[i] * 2);
            long long weight = min(w[i] * cnt, (long long) g[i] + s[i]);
            total += weight;
            gold += min((long long) g[i], weight);
            silver += min((long long) s[i], weight);
        }
        if (a <= gold && b <= silver && a + b <= total) {
            answer = min(answer, mid);
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return answer;
}
