#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define NONE      -1
#define MAX_A     18
using namespace std;

int n, m, root = 1;
vector<vector<int> > tree;
vector<vector<int> > parent;    //  parent[i][k] : i 노드의 2^k번째 부모
vector<int> depth;

void dfs(int cur, int val) {
    depth[cur] = val;
    for(int i = 0; i < tree[cur].size(); i++) {
        if(depth[tree[cur][i]] == NONE) {
            parent[tree[cur][i]][0] = cur;
            dfs(tree[cur][i], val + 1);
        }
    }
}

void make_parent() {
    for(int i = 1; i < MAX_A; i++) {
        for(int j = 1; j <= n; j ++) 
            parent[j][i] = parent[parent[j][i - 1]][i - 1];
    }
}

void find_ancestor(int x, int y) {
    int d1 = depth[x];
    int d2 = depth[y];
    int up = x, stay = y;
    int d = abs(d1 - d2), num = 0;

    if(d1 != d2) {
        up = (d1 > d2) ? x : y;
        stay = (d1 > d2) ? y : x;

        while(d != 0) {
            int r = d % 2;
            d /= 2;
            
            if(r == 1)
                up = parent[up][num];
            num++;
        }
    }

    if(up == stay) {
        cout << up << '\n';
        return;
    }

    int a, b;
    for(int i = MAX_A - 1; i >= 0; i--) {
        a = parent[up][i];
        b = parent[stay][i];

        if(a != b) {
            up = a;
            stay = b;
        }
    }

    cout << parent[up][0] << '\n';
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    tree.assign(n + 1, vector<int>());
    parent.assign(n + 1, vector<int>());
    depth.assign(n + 1, NONE);
    for(int i = 0; i <= n; i++)
        parent[i].assign(MAX_A, 0);

    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(root, 0);
    make_parent();

    cin >> m;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        find_ancestor(x, y);
    }

    return 0;
}