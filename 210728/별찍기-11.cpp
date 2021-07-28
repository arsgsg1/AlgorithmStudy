#include <iostream>
#include <vector>
using namespace std;

vector<vector<char> > star;

void draw(int n, int y, int x) {
    if(n == 3) {
        star[y][x] = '*';
        star[y + 1][x - 1] = '*';   star[y + 1][x + 1] = '*';
        for(int i = 0; i < 5; i++) {
            star[y + 2][x - 2 + i] = '*';
        }
    }
    else {
        draw(n / 2, y, x);
        draw(n / 2, y + (n / 2), x - (n / 2));
        draw(n / 2, y + (n / 2), x + (n / 2));
    }
}

int main(void) {
    int n;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    star.assign(n + 1, vector<char>());
    for(int i = 0; i <= n; i++)
        star[i].assign(2 * n + 1, ' ');

    draw(n, 1, n);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 2 * n - 1; j++)
            cout << star[i][j];
        cout << '\n';
    }

    return 0;
}