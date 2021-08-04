#include <bits/stdc++.h>
using namespace std;

vector <pair<int, int>> flower;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int stMonth, stDay, edMonth, edDay;
        cin >> stMonth >> stDay >> edMonth >> edDay;
        flower.push_back({ stMonth * 100 + stDay, edMonth * 100 + edDay });
    }

    sort(flower.begin(), flower.end());

    int curDate = 301;
    int idx = 0;
    int maxDate = 0;
    int ans = 0;
    while (curDate <= 1130) {
        for (int i = idx; i < N; i++) {
            if (flower[i].first > curDate) break;
            if (flower[i].second > maxDate) {
                maxDate = flower[i].second;
                idx = i;
            }
        }

        if (maxDate == curDate) {
            cout << 0;
            return 0;
        } else {
            curDate = maxDate;
            ans++;
        }
    }
    cout << ans;
}