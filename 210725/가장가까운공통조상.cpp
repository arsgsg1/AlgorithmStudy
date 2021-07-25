#include <iostream>
#include <vector>
#define NONE    -1
using namespace std;

vector<vector<int> > tree;
vector<int> parents;
vector<int> depth;
int tc, n, a, b;

void dfs(int root, int val) {
    depth[root] = val + 1;
    for(int i = 0; i < tree[root].size(); i++) {
        if(depth[tree[root][i]] == NONE)
            dfs(tree[root][i], depth[root]);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    for(int i = 0; i < tc; i++) {
        cin >> n;
        tree.assign(n + 1, vector<int>());
        parents.assign(n + 1, NONE);
        depth.assign(n + 1, NONE);

        for(int j = 0; j < n - 1; j++) {
            int p, c;
            cin >> p >> c;
            tree[p].push_back(c);
            parents[c] = p;
        }

        for(int i = 1; i <= n; i++) {
            if(parents[i] == NONE) {
                parents[i] = i;
                dfs(i, depth[i]);
                break;
            }
        }

        cin >> a >> b;

        while(depth[a] != depth[b]) {
            if(depth[a] > depth[b]) 
                a = parents[a];
            else
                b = parents[b];
        }
        while(a != b) {
            a = parents[a];
            b = parents[b];
        }
        cout << a << '\n';
    }

    return 0;
}