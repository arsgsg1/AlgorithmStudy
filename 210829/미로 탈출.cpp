#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX_SIZE 1001
#define INF 987654321
int d[MAX_SIZE][1 << 11];
//도착지, 가중치
vector<pair<int, int>> graph[MAX_SIZE];
vector<pair<int, int>> rev_graph[MAX_SIZE];
void setting(int n)
{
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= (1 << 10); j++) {
			d[i][j] = INF;
		}
	}
}
void dijkstra(const int start, const vector<int>& traps)
{
	//정점, 가중치, 트랩
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ start,{ 0, 0 } });
	while (!pq.empty()) {
		int cur = pq.top().first;
		int dist = -pq.top().second.first;
		int trap = pq.top().second.second;
		pq.pop();
		if (d[cur][trap] < dist) //더 짧은 경로를 알고 있음.
			continue;
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].first;
			int nextDist, trapState;
			bool isCurTrap = find(traps.begin(), traps.end(), cur) == traps.end() ? false : true;
			bool isNextTrap = find(traps.begin(), traps.end(), next) == traps.end() ? false : true;
			if (traps.end() != find(traps.begin(), traps.end(), next)) {
				trapState = trap ^ (1 << next);
			}
			if ((isCurTrap && isNextTrap) || (!isCurTrap && !isNextTrap)) {
				nextDist = dist + graph[cur][i].first;
				pq.push({ next,{ -nextDist, trapState } });
			}
			else {
				nextDist = dist + rev_graph[cur][i].first;
				pq.push({ next,{ -nextDist, trapState } });
			}
		}
	}
}
int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
	int answer = INF;
	setting(n);
	for (int i = 0; i < roads.size(); i++) {
		int s = roads[i][0], e = roads[i][1], d = roads[i][2];
		graph[s].push_back({ e, d });
		rev_graph[e].push_back({ s, d });
	}
	dijkstra(start, traps);
	for (int j = 0; j <= (1 << 10); j++) {
		answer = min(answer, d[end][j]);
	}
	return answer;
}