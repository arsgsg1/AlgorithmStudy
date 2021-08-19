/*
1. bfs로 가장 넓은 크기와 방의 개수를 구함
2. 50 x 50의 방의 4방향마다 BFS를 수행
*/
#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
#define MAX_SIZE 50
int Width, Height;
int arr[MAX_SIZE][MAX_SIZE];
bool visit[MAX_SIZE][MAX_SIZE];
//서, 북, 동, 남의 방향
int dirRow[] = { 0, -1, 0, 1 };
int dirCol[] = { -1, 0, 1, 0 };
int bfs(int row, int col)
{
	visit[row][col] = true;
	queue<pair<int, int>> q;
	q.push({ row, col });
	int r, c, nr, nc, cnt = 1;
	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			nr = r + dirRow[i];
			nc = c + dirCol[i];
			int dir = 1 << i;
			if (nr < 0 || nc < 0 || nr >= Height || nc >= Width)
				continue;
			if (!visit[nr][nc] && (arr[r][c] & dir) == 0) {
				q.push({ nr, nc });
				visit[nr][nc] = true;
				cnt++;
			}
		}
	}
	return cnt;
}
int main()
{
	scanf("%d %d", &Width, &Height);
	for (int i = 0; i < Height; i++) {
		for (int j = 0; j < Width; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	int room_cnt = 0, room_area = 0;
	for (int r = 0; r < Height; r++) {
		for (int c = 0; c < Width; c++) {
			if (!visit[r][c]) {
				room_area = max(room_area, bfs(r, c));
				room_cnt++;
			}
		}
	}

	int removal_area = 0;
	for (int r = 0; r < Height; r++) {
		for (int c = 0; c < Width; c++) {
			for (int b = 1; b <= 8; b <<= 1) {
				if (arr[r][c] & b) {
					arr[r][c] -= b;
					removal_area = max(removal_area, bfs(r, c));
					arr[r][c] += b;
					memset(visit, false, sizeof(visit));
				}
			}
		}
	}
	printf("%d\n%d\n%d\n", room_cnt, room_area, removal_area);
	return 0;
}