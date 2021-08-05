#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define MAX_LEN 8

int ROW, COL, answer = 0;
int dirRow[] = { 1, -1, 0, 0 };
int dirCol[] = { 0, 0, 1, -1 };
int field[MAX_LEN][MAX_LEN];
int cpField[MAX_LEN][MAX_LEN];
int afterField[MAX_LEN][MAX_LEN];
queue<pair<int, int>> virus;

int bfs()
{
	int nr, nc, cnt = 0;
	memcpy(afterField, cpField, sizeof(field));
	queue<pair<int, int>> cpVirus = virus;
	while (!cpVirus.empty()) {
		for (int i = 0; i < 4; i++) {
			nr = cpVirus.front().first + dirRow[i];
			nc = cpVirus.front().second + dirCol[i];

			if (nr < 0 || nc < 0 || nr >= ROW || nc >= COL)
				continue;

			if (afterField[nr][nc] == 0) {
				afterField[nr][nc] = 2;
				cpVirus.push(make_pair(nr, nc));
			}
		}
		cpVirus.pop();
	}

	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			if (afterField[i][j] == 0) {
				cnt++;
			}
		}
	}
	return cnt;
}

void dfs(int wall)
{
	if (wall == 3) {
		answer = max(bfs(), answer);
		return;
	}

	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			if (cpField[i][j] == 0) {
				cpField[i][j] = 1;
				dfs(wall + 1);
				cpField[i][j] = 0;
			}
		}
	}
	return;
}

int main()
{
	cin >> ROW >> COL;
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			cin >> field[i][j];
			if (field[i][j] == 2) {
				virus.push(make_pair(i, j));
			}
		}
	}
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			if (field[i][j] == 0) {
				memcpy(cpField, field, sizeof(field));
				cpField[i][j] = 1;
				dfs(1);
				cpField[i][j] = 0;
			}
		}
	}
	cout << answer << "\n";
	return 0;
}