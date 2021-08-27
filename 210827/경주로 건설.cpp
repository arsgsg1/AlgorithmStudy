/*
BFS 접근 방식
기록해놓은 cost보다 더 작은 값이 계산되면, 해당 칸의 cost를 저장하고 다음 칸 탐색.
그렇지 않으면 큐에 넣지 않음.
*/
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX_SIZE 25
#define COST 100
#define CORNER_COST 500
queue<pair<int, pair<int, int>>> q;
int dist[MAX_SIZE][MAX_SIZE][4]; //방향에 따른 코너 cost를 더할지 판단하기 위함.
int dirRow[] = { 0, 1, 0, -1 };
int dirCol[] = { -1, 0, 1, 0 };
int N;
int getCostByDir(int curDir, int nextDir)
{
	if ((curDir + 1) % 4 == nextDir || //다음 방향이 수직 방향이면, 코너 cost를 더함.
		(curDir + 3) % 4 == nextDir)
		return COST + CORNER_COST;
	return COST;
}
void bfs(int row, int col, vector<vector<int>>& board)
{
	for (int i = 0; i < 4; i++)
		q.push({ i,{ row, col } });
	int r, c, d, nr, nc;
	while (!q.empty()) {
		r = q.front().second.first;
		c = q.front().second.second;
		d = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++) {
			nr = r + dirRow[i];
			nc = c + dirCol[i];
			int cost = getCostByDir(d, i);
			if (nr < 0 || nc < 0 || nr >= N || nc >= N)
				continue;
			if (board[nr][nc] == 0 && dist[nr][nc][i] > dist[r][c][d] + cost) {
				dist[nr][nc][i] = dist[r][c][d] + cost;
				q.push({ i,{ nr, nc } });
			}
		}
	}
}
int solution(vector<vector<int>> board) {
	N = board.size();
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < 4; k++)
				dist[i][j][k] = 987654321;
	for (int i = 0; i < 4; i++)
		dist[0][0][i] = 0;
	bfs(0, 0, board);
	int answer = 987654321;
	for (int i = 0; i < 4; i++)
		answer = min(answer, dist[N - 1][N - 1][i]);
	return answer;
}