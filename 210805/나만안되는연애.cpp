#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define NONE    -1
using namespace std;

int n, m, num, ans;
vector<int> parent;
vector<char> sex;
vector<pair<int, pair<int, int> > > edges;

int find_parent(int x) {
    if(parent[x] == x)
        return parent[x];
    else
        return parent[x] = find_parent(parent[x]);
}

void union_sets(int x, int y) {
    x = find_parent(x);
    y = find_parent(y);

    if(x == y) return;
    else if(x > y)
        parent[x] = y;
    else 
        parent[y] = x;
}

void kruskal() {
    sort(edges.begin(), edges.end());

    for(int i = 0; i < edges.size(); i++) {
        if(num == n - 1) break;

        int cost = edges[i].first;
        int v1 = edges[i].second.first, v2 = edges[i].second.second;

        if(sex[v1] == sex[v2]) continue;
        else {
            if(find_parent(v1) == find_parent(v2))
                continue;
            else {
                union_sets(v1, v2);
                num += 1;
                ans += cost;
            }     
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    cin.ignore();

    // parent.assign(n + 1, NONE);
    for(int i = 0; i <= n; i++)
        parent.push_back(i);
    sex.assign(n + 1, 0);

    for(int i = 1; i <= n; i++)
        cin >> sex[i];
    cin.ignore();

    for(int i = 0; i < m; i++) {
        int cost, v1, v2;
        cin >> v1 >> v2 >> cost;

        edges.push_back(make_pair(cost, make_pair(v1, v2)));
    }

    kruskal();

    if(num != n - 1)
        cout << NONE << '\n';
    else
        cout << ans << '\n';
    
    return 0;
}