#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int N, ans = (int)1e9;
vector<int> snow;
vector<pair<int, pair<int, int> > > snowmen;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        snow.push_back(x);
    }

    for(int i = 0; i < N - 1; i++) {
        for(int j = i + 1; j < N; j++) {
            int x = snow[i] + snow[j];
            snowmen.push_back(make_pair(x, make_pair(i, j)));
        }
    }

    sort(snowmen.begin(), snowmen.end());

    for(int i = 0; i < snowmen.size() - 1; i++) {
        int h1 = snowmen[i].first;
        int x1 = snowmen[i].second.first;
        int y1 = snowmen[i].second.second;
        int h2 = snowmen[i + 1].first;
        int x2 = snowmen[i + 1].second.first;
        int y2 = snowmen[i + 1].second.second;

        if(x1 == x2 || x1 == y2 || y1 == x2 || y1 == y2)
            continue;
        
        ans = min(ans, h2 - h1);
    }

    cout << ans << '\n';

    return 0;
}
