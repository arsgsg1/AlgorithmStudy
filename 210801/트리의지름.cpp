#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define NONE      -1
using namespace std;

int v, root = 1;
vector<vector<pair<int, int> > > tree;
vector<int> dist;

void reset() {
    for(int i = 0; i <= v; i++) 
        dist[i] = NONE;
}

void dfs(int cur, int val) {
    dist[cur] = val;

    for(int i = 0; i < tree[cur].size(); i++) {
        if(dist[tree[cur][i].first] == NONE) 
            dfs(tree[cur][i].first, dist[cur] + tree[cur][i].second);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> v;

    tree.assign(v + 1, vector<pair<int, int> >());
    dist.assign(v + 1, NONE);

    for(int i = 0; i < v; i++) {
        vector<int> tmp;
        int x;
        while(true) {
            cin >> x;
            if(x == -1) break;
            tmp.push_back(x);
        }

        for(int j = 1; j < tmp.size() - 1; j += 2) 
            tree[tmp[0]].push_back(make_pair(tmp[j], tmp[j + 1]));
    }

    dfs(root, 0);

    int max_dist = 0;
    for(int i = 1; i <= v; i++) {
        if(dist[i] > max_dist) {
            max_dist = dist[i];
            root = i;
        }
    }
    reset();
    dfs(root, 0);

    max_dist = 0;
    for(int i = 1; i <= v; i++) {
        if(dist[i] > max_dist)
            max_dist = dist[i];
    }
    cout << max_dist << '\n';

    return 0;
}