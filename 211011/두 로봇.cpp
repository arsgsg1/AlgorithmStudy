/*
BFS: 두 정점의 주변 정점을 탐색하기 때문에 최솟값이 자명함.
종료 조건으로 같은 통로에 있는지를 확인하기 위해, 주변 정점이 다른 쪽에서 방문됐는지를 확인.
틀린 이유: 최단 경로 사이에 있는 두 정점 합만 구하는게 아니었기 때문에 틀림.

답을 구하는 과정
1. 최단 경로의 가중치 합 - 가장 긴 가중치인걸 파악.
2. 탐색 방법 선택: dfs, bfs, 다익스트라 셋 중 하나 선택
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_V 100001
#define INF 1e9
vector<pair<int, int>> graph[MAX_V];
int dist[MAX_V];
bool visited[MAX_V];
int N, Start, End, answer = INF;
void dfs(int cur, int sum, int max_w)
{
	if (cur == End) {
		answer = sum - max_w;
		return;
	}
	visited[cur] = true;
	for (int i = 0; i < graph[cur].size(); i++) {
		int next = graph[cur][i].first;
		int nextCost = sum + graph[cur][i].second;
		if (visited[next] == false) {
			dfs(next, nextCost, max(max_w, graph[cur][i].second));
		}
	}
}
int main()
{
	cin >> N >> Start >> End;
	int s, e, d;
	for (int i = 0; i < N - 1; i++) {
		scanf("%d %d %d", &s, &e, &d);
		graph[s].push_back({ e, d });
		graph[e].push_back({ s, d });
	}
	dfs(Start, 0, 0);
	printf("%d\n", answer);
	return 0;
}