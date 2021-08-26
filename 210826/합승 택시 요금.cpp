#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_SIZE 201
#define INF 9876543
int graph[MAX_SIZE][MAX_SIZE];
void setting(int n, vector<vector<int>>& fares)
{
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				graph[i][j] = 0;
			else
				graph[i][j] = INF;
		}
	}
	for (const auto& fare : fares) {
		int s = fare[0], e = fare[1], d = fare[2];
		graph[s][e] = d;
		graph[e][s] = d;
	}
}
void floyd(int n)
{
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (graph[i][j] > graph[i][k] + graph[k][j]) {
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}
}
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	int answer = 0;
	setting(n, fares);
	floyd(n);
	//합승하지 않는 경우
	answer = graph[s][a] + graph[s][b];
	//합승하는 경우
	for (int i = 1; i <= n; i++) {
		if (i == s)
			continue;
		answer = min(answer, graph[s][i] + graph[i][a] + graph[i][b]);
	}
	return answer;
}