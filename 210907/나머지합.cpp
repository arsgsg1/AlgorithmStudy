#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

typedef long long LL;
int N, M;

LL ans;

vector<int> arr;
vector<LL> sum;
vector<int> sum_mod;
unordered_map<int, LL> hashmap;

LL n_combination_2(LL n) {
    return n * (n - 1) / 2;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    arr.assign(N + 1, 0);
    sum.assign(N + 1, 0);
    sum_mod.assign(N + 1, 0);

    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i];
        sum_mod[i] = sum[i] % M;
    }

    for(int i = 0; i <= N; i++) {
        if(hashmap.find(sum_mod[i]) == hashmap.end())
            hashmap[sum_mod[i]] = 1;
        else hashmap[sum_mod[i]] += 1;
    }

    for(int i = 0; i < M; i++) {
        LL n = hashmap[i];
        if(n >= 2)
            ans += n_combination_2(n);
    }

    cout << ans << '\n';

    return 0;
}