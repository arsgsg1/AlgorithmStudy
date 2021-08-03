#include <bits/stdc++.h>

using namespace std;

int K;
bool turn[5];
int rotation[5];
vector<deque<int>> gear(5);

void rec(int g, int d)
{
    rotation[g] = d;
    turn[g] = true;
    if (g - 1 > 0 && !turn[g - 1]) {
        if (d == 0) rec(g - 1, 0);
        else if (gear[g][6] == gear[g - 1][2]) rec(g - 1, 0);
        else rec(g - 1, -d);
    }
    if (g + 1 <= 4 && !turn[g + 1]) {
        if (d == 0) rec(g + 1, 0);
        else if (gear[g][2] == gear[g + 1][6]) rec(g + 1, 0);
        else rec(g + 1, -d);
    }
}

void rotate()
{
    for (int i = 1; i <= 4; i++) {
        if (rotation[i] == 0) continue;
        if (rotation[i] == 1) {
            int temp = gear[i].back();
            gear[i].pop_back();
            gear[i].push_front(temp);
        }
        else {
            int temp = gear[i].front();
            gear[i].pop_front();
            gear[i].push_back(temp);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char n;
    for (int i = 1; i <= 4; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> n;
            gear[i].push_back(n - '0');
        }
    }

    cin >> K;
    int g, d;

    for (int i = 0; i < K; ++i) {
        cin >> g >> d;
        memset(turn, false, sizeof(turn));
        rec(g, d);
        rotate();
    }

    int ans = 0;
    for (int i = 1; i <= 4; i++)
        if (gear[i][0] == 1) ans += pow(2, i - 1);

    cout << ans;
}