#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Car {
    int x, y, c, d;
    Car(int x, int y, int c, int d) : x(x), y(y), c(c), d(d) {}
};

const int INF = 2e9;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int solution(vector<vector<int>> board) {
    int answer = INF;
    int n = (int)board.size();
    vector<vector<int>> costs(n, vector<int>(n, INF));
    queue<Car> q;
    q.push(Car(0, 0, 0, 0));
    q.push(Car(0, 0, 0, 1));
    costs[0][0] = 0;
    while (!q.empty()) {
        Car now = q.front();
        q.pop();

        if (now.x == n - 1 && now.y == n - 1) {
            answer = min(answer, now.c);
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];
            int nc = now.c + (now.d == i ? 100 : 600);
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (board[nx][ny] != 1 && nc <= costs[nx][ny]) {
                costs[nx][ny] = nc;
                q.push(Car(nx, ny, nc, i));
            }
        }
    }
    return answer;
}