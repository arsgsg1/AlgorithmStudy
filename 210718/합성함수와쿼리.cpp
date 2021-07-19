#include <iostream>
#include <vector>
using namespace std;

int m, q, n, x;
vector<vector<int> > func;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m;

    func.assign(20, vector<int>());
    for(int i = 0; i <= 19; i++) 
        func[i].assign(m + 1, 0);

    for(int i = 1; i <= m; i++)
        cin >> func[0][i];

    for(int i = 1; i <= 19; i++) {
        for(int j = 1; j <= m; j++) 
            func[i][j] = func[i - 1][func[i - 1][j]];
    }

    cin >> q;

    for(int i = 0; i < q; i++) {
        cin >> n >> x;

        int Q, R, result;
        for(int j = 0; j <= 19; j++) {
            Q = n / 2;
            R = n % 2;

            if(R == 1) {
                result = func[j][x];
                x = result;
            }
            n = Q;
            if(Q == 0) break;
        }
        cout << result << '\n';
    }

    return 0;
}