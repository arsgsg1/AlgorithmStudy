#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 10001;
vector<int> graph[MAX];
int dp[MAX][2], num[MAX];
int n;

void dfs(int root, int prev) {
    int sum = 0;
    for (auto child : graph[root]) {
        if (child == prev) continue;
        dfs(child, root);
        dp[root][1] += dp[child][0];
        sum += max(dp[child][0], dp[child][1]);
    }
    dp[root][0] = sum;
    dp[root][1] += num[root];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> num[i];
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, 0);
    cout << max(dp[1][0], dp[1][1]) << endl;
    return 0;
}
