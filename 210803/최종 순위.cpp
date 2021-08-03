#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
#define MAX_SIZE 501
int N, M;
int order[MAX_SIZE];
int graph[MAX_SIZE][MAX_SIZE];
int inDegree[MAX_SIZE];
int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		memset(graph, 0, sizeof(graph));
		memset(inDegree, 0, sizeof(inDegree));
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) {
			scanf("%d", &order[i]);
		}
		for (int i = 1; i <= N; i++) {
			for (int j = i + 1; j <= N; j++) {
				graph[order[i]][order[j]] = 1;
				inDegree[order[j]]++;
			}
		}
		scanf("%d", &M);
		int s, e;
		for (int i = 0; i < M; i++) {
			scanf("%d %d", &s, &e);
			if (graph[s][e]) {
				graph[s][e] = 0;
				graph[e][s] = 1;
				inDegree[e]--;
				inDegree[s]++;
			}
			else {
				graph[s][e] = 1;
				graph[e][s] = 0;
				inDegree[e]++;
				inDegree[s]--;
			}
		}
		queue<int> q;
		for (int i = 1; i <= N; i++) {
			if (!inDegree[i])
				q.push(i);
		}
		bool isDoubt = false;
		vector<int> answer;
		while (!q.empty()) {
			if (q.size() > 1) {
				isDoubt = true;
				break;
			}
			int cur = q.front();
			q.pop();
			answer.push_back(cur);

			for (int next = 1; next <= N; next++) {
				if (graph[cur][next]) {
					inDegree[next]--;
					if (!inDegree[next])
						q.push(next);
				}
			}
		}
		if (isDoubt)
			printf("?\n");
		else if (answer.size() == N) {
			for (int i = 0; i < N; i++)
				printf("%d ", answer[i]);
			printf("\n");
		}
		else
			printf("IMPOSSIBLE\n");
	}
	return 0;
}