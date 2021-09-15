#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 2e9;
const int MAX = 300000;
vector<int> tree[MAX];
int dp[MAX][2];

void go(int root, vector<int>& sales) {
    for (auto child : tree[root]) go(child, sales);
    
    if (tree[root].empty()) {
        dp[root][1] = sales[root];
        return;
    }
    
    int sum = 0;
    bool attended = false;
    for (auto child : tree[root]) {
        sum += min(dp[child][0], dp[child][1]);
        if (dp[child][0] >= dp[child][1]) attended = true;
    }
    
    dp[root][1] = sum + sales[root];
    
    if (attended) {
        dp[root][0] = sum;
    } else {
        int diff = INF;
        for (auto child : tree[root])
            diff = min(diff, dp[child][1] - dp[child][0]);
        dp[root][0] = sum + diff;
    }
}

int solution(vector<int> sales, vector<vector<int>> links) {
    for (auto& link : links)
        tree[link[0] - 1].push_back(link[1] - 1);
    go(0, sales);
    return min(dp[0][0], dp[0][1]);
}
