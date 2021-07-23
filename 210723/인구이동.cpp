#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <utility>
#include <algorithm>
using namespace std;

int n, l, r;
int num_union = 0;
int days = 0;
vector<vector<int> > land;
vector<vector<int> > visit;
vector<vector<pair<int, int> > > union_land;
vector<int> union_sum;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

void reset() {
    for(int i = 0; i < union_land.size(); i++) {
        while(!union_land[i].empty())
            union_land[i].pop_back();
    }
    while(!union_land.empty())
        union_land.pop_back();
    while(!union_sum.empty())
        union_sum.pop_back();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            visit[i][j] = false;
    }
    union_land.resize(n * n);
    union_sum.assign(n * n, 0);
    num_union = 0;
}

bool is_open(int y1, int x1, int y2, int x2) {
    int diff = abs(land[y2][x2] - land[y1][x1]);
    return ((l <= diff) && (diff <= r));
}

void bfs(int y, int x) {
    queue<pair<int, int> > q;
    union_land[num_union].push_back(make_pair(y, x));
    union_sum[num_union] += land[y][x];
    q.push(make_pair(y, x));
    visit[y][x] = true;

    while(!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        int ny, nx;
        for(int i = 0; i < 4; i++) {
            ny = cy + dy[i];
            nx = cx + dx[i];

            if(ny < 0 || ny >= n || nx < 0 || nx >= n) 
                continue;
            else if(!is_open(cy, cx, ny, nx)) 
                continue;
            else {
                if(visit[ny][nx]) continue;
                visit[ny][nx] = true;
                union_land[num_union].push_back(make_pair(ny, nx));
                union_sum[num_union] += land[ny][nx];
                q.push(make_pair(ny, nx));
            }
        }
    }

    int mean = union_sum[num_union];
    mean = (int)(mean / union_land[num_union].size());

    for(int i = 0; i < union_land[num_union].size(); i++) {
        int py = union_land[num_union][i].first;
        int px = union_land[num_union][i].second;
        land[py][px] = mean;
    }

    num_union++;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> l >> r;

    land.resize(n);
    visit.resize(n);

    for(int i = 0; i < n; i++) {
        visit[i].resize(n);
        for(int j = 0; j < n; j++) {
            int x;
            cin >> x;
            land[i].push_back(x);
        }
    }

    while(true) {
        reset();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!visit[i][j])
                    bfs(i, j);   
            }
        }

        if(num_union == n * n) break;
        days++;
    }
    
    cout << days << '\n';
    return 0;
}