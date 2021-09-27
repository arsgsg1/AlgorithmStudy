#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
bool check[500][500][4];

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 4; k++) {
                if (check[i][j][k]) continue;
                int x = i, y = j, d = k, cnt = 0;
                while (!check[x][y][d]) {
                    check[x][y][d] = true;
                    cnt++;
                    char ch = grid[x][y];
                    if (ch == 'L')
                        d = (d + 3) % 4;
                    else if (ch == 'R')
                        d = (d + 1) % 4;
                    x = (x + dx[d] + n) % n;
                    y = (y + dy[d] + m) % m;
                }
                answer.push_back(cnt);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}