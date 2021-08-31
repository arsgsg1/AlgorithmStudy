#include <vector>
using namespace std;
#define MAX_SIZE 501
#define DOWN 0
#define RIGHT 1
const int MOD = 20170805;
long long dp[MAX_SIZE][MAX_SIZE][2];
vector<vector<int>> _city_map;
int M, N;
//방향 : 0 위 -> 아래, 1 왼->오
long long recur(int row, int col, int dir)
{
	if (row < 0 || col < 0 || row >= M || col >= N)
		return 0;
	else if (row == M - 1 && col == N - 1)
		return 1;
	if (dp[row][col][dir] == -1) {
		dp[row][col][dir] = 0;
		switch (_city_map[row][col]) {
		case 0:
			dp[row][col][dir] += recur(row + 1, col, DOWN);
			dp[row][col][dir] += recur(row, col + 1, RIGHT);
			break;
		case 1:
			break;
		case 2:
			if (dir == DOWN)
				dp[row][col][dir] += recur(row + 1, col, DOWN);
			else
				dp[row][col][dir] += recur(row, col + 1, RIGHT);
			break;
		}
	}
	return dp[row][col][dir] % MOD;
}
int solution(int m, int n, vector<vector<int>> city_map) {
	int answer = 0;
	M = m, N = n;
	_city_map = city_map;
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = 0; k < 2; k++) {
				dp[i][j][k] = -1;
			}
		}
	}
	answer = recur(0, 0, 0);
	return answer;
}