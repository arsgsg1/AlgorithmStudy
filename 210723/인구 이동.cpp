#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
int N, L, R;
int arr[51][51];
vector<vector<pair<int, int>>> v;
int dirRow[] = { 1, 0, -1, 0 };
int dirCol[] = { 0, 1, 0, -1 };
bool bfs(int row, int col)
{
	bool visit[51][51];
	memset(visit, false, sizeof(visit));
	vector<pair<int, int>> cord = { { row, col } };
	queue<pair<int, int>> q;
	q.push({ row, col });
	visit[row][col] = true;
	int r, c, nr, nc, sum = 0;
	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			nr = r + dirRow[i];
			nc = c + dirCol[i];
			if (nr < 0 || nc < 0 || nc >= N || nr >= N)
				continue;
			sum = abs(arr[r][c] - arr[nr][nc]);
			if (visit[nr][nc] == false && L <= sum && sum <= R) {
				q.push({ nr, nc });
				visit[nr][nc] = true;
				cord.push_back({ nr, nc });
			}
		}
	}
	if (cord.size() == 1)
		return false;
	else if (cord.size() > 1) {
		v.push_back(cord);
		return true;
	}
}
void _union()
{
	for (const auto& contry : v) {
		int sum = 0, cnt = 0;
		for (const auto& p : contry) {
			int r = p.first, c = p.second;
			sum += arr[r][c];
			cnt++;
		}
		for (const auto& p : contry) {
			int r = p.first, c = p.second;
			arr[r][c] = sum / cnt;
		}
	}
	v.clear();
}
int main()
{
	cin >> N;
	cin >> L >> R;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	int answer = 0;

	while (1) {
		bool done = true;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (bfs(i, j)) {
					done = false;
				}
			}
		}
		if (done)
			break;
		_union();
		answer++;
	}
	printf("%d\n", answer);
	return 0;
}