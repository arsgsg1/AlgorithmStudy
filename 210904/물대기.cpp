#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int n, edge, ans;
vector<int> parents;
vector<pair<int, pair<int, int> > > edges;

int find_parent(int x) {
    if(parents[x] == x)
        return x;
    else
        return parents[x] = find_parent(parents[x]);
}

void union_parents(int x, int y) {
    x = find_parent(x);
    y = find_parent(y);

    if(x == y)
        return;
    else if(x < y)
        parents[y] = x;
    else
        parents[x] = y;
}

void kruskal() {
    sort(edges.begin(), edges.end());

    for(int i = 0; i < edges.size(); i++) {
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;

        if(find_parent(a) != find_parent(b)) {
            union_parents(a, b);
            ans += cost;
            edge += 1;
        }

        if(edge >= n)
            break;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    for(int i = 0; i <= n; i++) //  0번 노드(가상 노드)
        parents.push_back(i);

    for(int i = 1; i <= n; i++) {
        int cost;
        cin >> cost;

        edges.push_back(make_pair(cost, make_pair(0, i)));
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int cost;
            cin >> cost;

            if(i < j)
                edges.push_back(make_pair(cost, make_pair(i, j)));
        }
    }

    kruskal();

    cout << ans << '\n';
    return 0;
}