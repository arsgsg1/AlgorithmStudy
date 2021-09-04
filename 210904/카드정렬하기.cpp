#include <iostream>
#include <queue>

using namespace std;

int n, ans;
priority_queue<int> pq;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        pq.push(-1 * num);
    }

    while(pq.size() > 1) {
        // cout << "pq-size : " << pq.size() << '\n';
        int num1, num2;
        num1 = pq.top() * (-1);
        pq.pop();
        num2 = pq.top() * (-1);
        pq.pop();
        // cout << "num1 : " << num1 << ", num2 : " << num2 << '\n'; 

        ans += (num1 + num2);
        // cout << "ans : " << ans << '\n';
        pq.push((num1 + num2) * (-1));
    }

    cout << ans << '\n';
    return 0;
}
