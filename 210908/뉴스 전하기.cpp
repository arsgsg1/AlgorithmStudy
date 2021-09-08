#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[51];

int dfs(int root) {
    int ret = 0;
    vector<int> time;
    for (auto child : graph[root])
        time.push_back(dfs(child));
    
    sort(time.begin(), time.end(), greater<>());
    
    for (int i = 0; i < time.size(); i++)
        ret = max(ret, time[i] + i + 1);
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    cin >> n;
    for (int i = 0, parent; i < n; i++) {
        cin >> parent;
        if (parent == -1) continue;
        graph[parent].push_back(i);
    }
    
    cout << dfs(0) << endl;
    
    return 0;
}
