#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    unordered_map<string, priority_queue<int>> m;
    int Q;
    long long answer = 0;
    cin >> Q;
    while (Q--) {
        int op, n, c;
        string name;
        cin >> op >> name >> n;
        if (op == 1) {
            for (int i = 0; i < n; i++) {
                cin >> c;
                m[name].push(c);
            }
        } else if (op == 2) {
            while (n-- && !m[name].empty()) {
                answer += m[name].top();
                m[name].pop();
            }
        }
    }
    cout << answer << endl;
    return 0;
}
