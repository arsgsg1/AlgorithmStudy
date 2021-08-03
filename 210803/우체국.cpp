#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define MAXIMUM    1000000001
using namespace std;

typedef long long LL;
int n;
LL ans;
vector<pair<LL, LL> > town;   //  (마을 위치, 사람 수)
vector<LL> sum;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    sum.assign(n, 0);

    for(int i = 0; i < n; i++) {
        int pos, pop;
        cin >> pos >> pop;
        town.push_back(make_pair(pos, pop)); 
    }
    sort(town.begin(), town.end());
    sum[0] = town[0].second;
    for(int i = 1; i < n; i++)
        sum[i] = sum[i - 1] +  town[i].second;
    for(int i = 0; i < n; i++) {
        if(sum[i] >= (sum[n - 1] + 1) / 2) {
            ans = town[i].first;
            break;
        }
    }

    cout << ans << '\n';
    return 0;
}