#include <iostream>
using namespace std;
#define MAX_SIZE 15
int visit[MAX_SIZE][MAX_SIZE];
int N;
int dirRow[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
int dirCol[] = { 0, 1, 0, -1, -1, 1, -1, 1 };
int qCnt = 0;
long long answer = 0;
void setQueen(int row, int col)
{
	++qCnt;
	int nr, nc;
	visit[row][col]++;
	for (int i = 0; i < 8; i++) {
		for (int d = 1; d < N; d++) {
			nr = row + dirRow[i] * d;
			nc = col + dirCol[i] * d;
			if (nr < 0 || nc < 0 || nr >= N || nc >= N)
				break;
			visit[nr][nc]++;
		}
	}
}
void clearQueen(int row, int col)
{
	--qCnt;
	int nr, nc;
	visit[row][col]--;
	for (int i = 0; i < 8; i++) {
		for (int d = 1; d < N; d++) {
			nr = row + dirRow[i] * d;
			nc = col + dirCol[i] * d;
			if (nr < 0 || nc < 0 || nr >= N || nc >= N)
				break;
			visit[nr][nc]--;
		}
	}
}
void backtrack(int col)
{
	answer = qCnt == N ? answer + 1 : answer;
	if (col >= N)
		return;
	for (int row = 0; row < N; row++) {
		if (visit[row][col] == 0) {
			setQueen(row, col);
			backtrack(col + 1);
			clearQueen(row, col);
		}
	}
}
int main()
{
	scanf("%d", &N);
	backtrack(0);
	cout << answer << endl;
	return 0;
}