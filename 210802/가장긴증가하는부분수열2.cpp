#include <iostream>
#include <vector>
#include <algorithm>
#define MIN         -1e9
using namespace std;

int n, ans;
vector<int> arr;
vector<int>::iterator iter;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    arr.push_back(MIN);
    cin >> n;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if(x > arr.back()) {
            arr.push_back(x);
            ans++;
        }
        else {
            iter = lower_bound(arr.begin(), arr.end(), x);
            *iter = x;
        }
    }

    cout << ans << '\n';
    return 0;
}