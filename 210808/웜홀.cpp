#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define INF     1e9
using namespace std;

int tc, n, m, w;
vector<pair<int, pair<int, int> > > edges;
vector<int> dist;

bool bellman_ford(int start) {
    bool ret = false;    //  음수 사이클이 존재하지 않을 경우 false
    dist.assign(n + 1, INF);
    dist[start] = 0;

    for(int i = 1; i <= n - 1; i++) {
        for(int j = 0; j < edges.size(); j++) {
            int t = edges[j].first; //  s -> e로 이동 시간  
            int s = edges[j].second.first;  
            int e = edges[j].second.second;

            if(dist[s] + t < dist[e])   //  s까지 이동 후 s에서 t로 이동하는 게 더 짧을 경우
                dist[e] = dist[s] + t;  //  relaxation
        }
    }

    for(int j = 0; j < edges.size(); j++) { 
        //  또 relaxation이 가능할 경우 음수 cycle이 존재함
        int t = edges[j].first; //  s -> e로 이동 시간  
        int s = edges[j].second.first;  
        int e = edges[j].second.second;

        if(dist[s] + t < dist[e]) { //  relaxation이 또 가능한지 확인
            ret = true;
            break;
        }
    }

    return ret;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> tc;
    for(int k = 0; k < tc; k++) {
        int s, e, t;
        vector<pair<int, pair<int, int> > >().swap(edges);
        vector<int>().swap(dist);
        cin >> n >> m >> w;

        for(int i = 0; i < m; i++) {
            cin >> s >> e >> t;
            edges.push_back(make_pair(t, make_pair(s, e)));
            edges.push_back(make_pair(t, make_pair(e, s)));
        }
        for(int i = 0; i < w; i++) {
            cin >> s >> e >> t;
            edges.push_back(make_pair(-t, make_pair(s, e)));
        }

        if(bellman_ford(1))
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }

    return 0;
}