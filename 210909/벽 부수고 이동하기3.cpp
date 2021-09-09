#include <iostream>
#include <string>
#include <queue>
#include <string.h>
using namespace std;
#define MAX_SIZE 1000
#define INF 987654321
int dirRow[] = { 1, 0, -1, 0 };
int dirCol[] = { 0, 1, 0, -1 };
int dist[MAX_SIZE][MAX_SIZE][11][2];
char arr[MAX_SIZE][MAX_SIZE];
int N, M, K, answer = INF;
struct Info {
	int r, c;
	int wall;
	int d;
	Info(int r, int c, int wall, int d) {
		this->r = r; this->c = c; this->wall = wall; this->d = d;
	}
};
void Input()
{
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < temp.size(); j++) {
			arr[i][j] = temp[j];
		}
	}
}
void bfs(int row, int col)
{
	int r, c, nr, nc, w, d, nd;
	queue<Info> q;
	q.push(Info(0, 0, 0, 0));
	dist[0][0][0][0] = 1;
	while (!q.empty()) {
		r = q.front().r;
		c = q.front().c;
		w = q.front().wall;
		d = q.front().d;
		nd = (d + 1) % 2;
		q.pop();
		if (dist[r][c][w][nd] == 0) {
			dist[r][c][w][nd] = dist[r][c][w][d] + 1;
			q.push(Info(r, c, w, nd));
		}
		if (r == N - 1 && c == M - 1) {
			answer = min(answer, dist[r][c][w][d]);
			continue;
		}
		for (int i = 0; i < 4; i++) {
			nr = r + dirRow[i];
			nc = c + dirCol[i];
			if (nr < 0 || nc < 0 || nr >= N || nc >= M)
				continue;
			if (arr[nr][nc] == '1' && w < K && d == 0
				&& dist[nr][nc][w + 1][nd] == 0) {
				q.push(Info(nr, nc, w + 1, nd));
				dist[nr][nc][w + 1][nd] = dist[r][c][w][d] + 1;
			}
			else if (arr[nr][nc] == '0' && dist[nr][nc][w][nd] == 0) {
				q.push(Info(nr, nc, w, nd));
				dist[nr][nc][w][nd] = dist[r][c][w][d] + 1;
			}
		}
	}
}
int main()
{
	Input();
	bfs(0, 0);
	if (answer == INF)
		printf("-1\n");
	else
		printf("%d\n", answer);
	return 0;
}