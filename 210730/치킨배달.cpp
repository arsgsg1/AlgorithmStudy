#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <algorithm>
#define MAXNUM      1e9
using namespace std;

int n, m, result = MAXNUM;
int nh, nc;
vector<vector<int> > city;
vector<pair<int, int> > house;
vector<pair<int, int> > chicken;
vector<int> selected_idx;

int dist(int y1, int x1, int y2, int x2) {
    return abs(y2 - y1) + abs(x2 - x1);
}

void dfs(int idx, int depth) {
    if(nc - idx < m - depth)
        return;
    else {
        selected_idx.push_back(idx);
        if(depth == m - 1) {
            int tmp1 = 0;
            for(int i = 0; i < house.size(); i++) {
                int hy = house[i].first;
                int hx = house[i].second;
                int tmp2 = MAXNUM;
                for(int j = 0; j < selected_idx.size(); j++) {
                    int cy = chicken[selected_idx[j]].first;
                    int cx = chicken[selected_idx[j]].second;
                    tmp2 = min(tmp2, dist(hy, hx, cy, cx));
                }
                tmp1 += tmp2;
            }
            result = min(result, tmp1);

            selected_idx.pop_back();
            return;
        }

        for(int i = idx + 1; i < nc; i++)
            dfs(i, depth + 1);
        selected_idx.pop_back();
    }  
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int d;
            cin >> d;

            if(d == 1) {
                nh += 1;
                house.push_back(make_pair(i, j));
            }
            else if(d == 2) {
                nc += 1;
                chicken.push_back(make_pair(i, j));
            }
        }
    }
    
    for(int i = 0; i < nc; i++) {
        vector<int>().swap(selected_idx);
        dfs(i, 0);
    }

    cout << result << '\n';

    return 0;
}