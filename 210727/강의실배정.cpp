#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue<pair<int, int> > pq;
int n, result;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    for(int i = 0; i < n; i++) {
        int from, to;
        cin >> from >> to;
        pq.push(make_pair((-1) * from, (-1) * to));
    }

    int maxs = -1;
    int mine = -1;
    int tmp = 0;
    while(!pq.empty()) {
        int s = -pq.top().first;
        int e = -pq.top().second;
        pq.pop();

        // cout << "(" << s << ", " << e << ")\n";
        if(mine <= s) {
            maxs = s;
            mine = e;
            result = max(result, tmp);
            tmp = 1;
        }
        else {
            maxs = max(maxs, s);
            mine = min(mine, e);
            tmp += 1;
        }
        // cout << "(" << maxs << ", " << mine << ")\n";
        // cout << "cnt : " << tmp << '\n';
    }
    cout << result << '\n';

    return 0;
}