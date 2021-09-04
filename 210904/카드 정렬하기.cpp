#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, answer = 0;
    cin >> n;
    priority_queue<int, vector<int>, greater<>> pq;

    for (int i = 0, x; i < n; i++) {
        cin >> x;
        pq.push(x);
    }
    
    if (pq.size() == 1) {
        cout << 0 << endl;
        return 0;
    }
    
    while (!pq.empty()) {
        int x = pq.top(), y = 0;
        pq.pop();
        if (!pq.empty()) {
            y = pq.top();
            pq.pop();
        }
        answer += x + y;
        if (!pq.empty()) pq.push(x + y);
    }
    
    cout << answer << endl;
    
    return 0;
}
