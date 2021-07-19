#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, c, result;
vector<int> home;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> c;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        home.push_back(x);
    }

    sort(home.begin(), home.end());
    
    int start = 1;
    int end = home[n - 1] - home[0];
    int mid = (start + end) / 2;

    while(start <= end) {
        int start_pos = 0;
        int num = 1;

        for(int i = 1; i < n; i++) {
            if(home[start_pos] + mid <= home[i]) {
                start_pos = i;
                num++;
            }
        }

        if(num >= c) {
            result = mid;
            start = mid + 1;
        }
        else end = mid - 1;

        mid = (start + end) / 2;
    }

    cout << result << '\n';

    return 0;
}