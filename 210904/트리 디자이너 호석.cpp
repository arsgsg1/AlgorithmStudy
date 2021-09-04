#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 100001;
vector<int> graph[MAX];
int num[MAX];
int n;

vector<int> dfs(int root, int prev) {
    vector<int> ret(10, 0);
    ret[num[root]]++;
    
    for (auto child : graph[root]) {
        if (child == prev) continue;
        vector<int> branch = dfs(child, root);
        for (int i = 0; i < 10; i++) {
            ret[i] = (ret[i] + branch[i]) % MOD;
            if (i >= num[root])
                ret[num[root]] = (ret[num[root]] + branch[i]) % MOD;
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> num[i];
    
    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    int answer = 0;
    for (auto a : dfs(1, 0)) answer = (answer + a) % MOD;
    
    cout << answer << endl;
    
    return 0;
}
