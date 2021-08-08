#include <iostream>
#include <vector>
#include <algorithm>
#define      NONE       0
using namespace std;

int G, P, ans;
vector<int> parent;

void print_parent() {
    cout << "parent\n";
    for(int i = 0; i <= G; i++)
        cout << parent[i] << ' ';
    cout << '\n';
}

int find_parent(int x) {
    if(x == parent[x])
        return parent[x];
    else 
        return parent[x] = find_parent(parent[x]);
}

void union_parent(int x, int y) {
    x = find_parent(x);
    y = find_parent(y);

    if(x < y)
        parent[y] = x;
    else if(x == y)
        return;
    else
        parent[x] = y;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> G;
    cin >> P;
    for(int i = 0; i <= G; i++)
        parent.push_back(i);
    for(int i = 1; i <= P; i++) {
        int gi, a, b;
        cin >> gi;

        // cout << "\nfor - " << i << '\n';

        // print_parent();

        a = find_parent(gi);
        b = find_parent(max(a - 1, 0));
        // cout << "a : " << a << '\n';
        // cout << "b : " << b << '\n';

        if(a != NONE) {
            ans += 1;
            union_parent(a, b);
        }
        else break;
    }

    // cout << "\nans\n"; 
    cout << ans << '\n';

    return 0;
}