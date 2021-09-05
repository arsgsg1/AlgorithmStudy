#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int board[20][20];
int cnt;
int candi_cnt;
int gijoon_y, gijoon_x;
bool visited[20][20];
bool visited2[20][20];
int dir[4][2] = { { -1,0 },{ 0,1 },{ 1,0 },{ 0,-1 } };
int N, M;
int cur_block;
int candi_rainbow;
int rainbow;


bool is_boundry(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= N) return false;
	return true;
}

void dfs(int y, int x) {
	if (board[y][x] != 0) {
		visited2[y][x] = true;
	}
	candi_cnt++;
	if (board[y][x] == 0) {
		candi_rainbow++;
	}
	for (int i = 0; i < 4; i++) {
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];
		if (!is_boundry(ny, nx) || visited[ny][nx]) continue;
		if (board[ny][nx] == -2 || board[ny][nx] == -1) continue;
		if (!(board[ny][nx] == 0 || board[ny][nx] == cur_block)) continue;

		visited[ny][nx] = true;
		dfs(ny, nx);
	}
}

void erase(int y, int x) {
	board[y][x] = -2;
	for (int i = 0; i < 4; i++) {
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];
		if (!is_boundry(ny, nx) || visited[ny][nx]) continue;
		if (board[ny][nx] == -2 || board[ny][nx] == -1 || !(board[ny][nx] == 0 || board[ny][nx] == cur_block)) continue;
		visited[ny][nx] = true;
		erase(ny, nx);
	}
}

void down() {
	for (int i = N - 1; i > 0; i--) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == -2) {
				int y = i - 1;
				while (y >= 0 && board[y][j] == -2) {
					y--;
				}
				if (y >= 0 && board[y][j] != -1) {
					board[i][j] = board[y][j];
					board[y][j] = -2;
				}
			}
		}
	}
}

void rotate() {
	int copy[20][20];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			copy[i][j] = board[j][N - i - 1];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board[i][j] = copy[i][j];
		}
	}
}

int main() {
	int ans = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	gijoon_y = -1;
	gijoon_x = -1;
	bool loop = true;
	while (loop) {
		loop = false;
		cnt = 0;
		rainbow = 0;
		memset(visited, false, sizeof(visited));
		memset(visited2, false, sizeof(visited2));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited2[i][j] || board[i][j] == -2) continue;
				if (board[i][j] != -1 && board[i][j] != 0) {
					candi_rainbow = 0;
					candi_cnt = 0;
					cur_block = board[i][j];
					memset(visited, false, sizeof(visited));
					visited[i][j] = true;
					dfs(i, j);

					if (candi_cnt < 2) continue;
					loop = true;

					if (candi_cnt > cnt) {
						rainbow = candi_rainbow;
						gijoon_y = i;
						gijoon_x = j;
						cnt = candi_cnt;
					}
					else if (candi_cnt == cnt) {
						if (candi_rainbow >= rainbow) {
							rainbow = candi_rainbow;
							gijoon_y = i;
							gijoon_x = j;
						}
					}

				}
			}
		}
		memset(visited, false, sizeof(visited));
		if (loop) {
			visited[gijoon_y][gijoon_x] = true;
			cur_block = board[gijoon_y][gijoon_x];
			erase(gijoon_y, gijoon_x);
			ans += cnt * cnt;
			down();
			rotate();
			down();
		}
	}
	cout << ans;

}