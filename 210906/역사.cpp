#include <iostream>

using namespace std;

int mat[401][401];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k, s, a, b;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        mat[a][b] = -1;
        mat[b][a] = 1;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (mat[i][j] == 0) {
                    if (mat[i][k] == 1 && mat[k][j] == 1) {
                        mat[i][j] = 1;
                    } else if (mat[i][k] == -1 && mat[k][j] == -1) {
                        mat[i][j] = -1;
                    }
                }
            }
        }
    }
    cin >> s;
    for (int i = 0; i < s; i++) {
        cin >> a >> b;
        cout << mat[a][b] << '\n';
    }
    return 0;
}