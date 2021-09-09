#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX_SIZE 1001
int inDegree[MAX_SIZE];
int result[MAX_SIZE];
vector<int> graph[MAX_SIZE];
int N, M;
bool topology_sort()
{
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0)
			q.push(i);
	}
	for (int i = 1; i <= N; i++) {
		if (q.empty()) {
			printf("0\n");
			return false;
		}
		int cur = q.front();
		q.pop();
		result[i] = cur;
		for (int j = 0; j < graph[cur].size(); j++) {
			int next = graph[cur][j];
			if (--inDegree[next] == 0)
				q.push(next);
		}
	}
	return true;
}
int main()
{
	cin >> N >> M;
	int pd, s, e;
	for (int i = 0; i < M; i++) {
		cin >> pd;
		cin >> s;
		for (int j = 1; j < pd; j++) {
			cin >> e;
			graph[s].push_back(e);
			inDegree[e]++;
			s = e;
		}
	}
	if (topology_sort()) {
		for (int i = 1; i <= N; i++) {
			printf("%d\n", result[i]);
		}
	}
	return 0;
}