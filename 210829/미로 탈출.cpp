#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;
#define MAX_SIZE 1010
#define INF 2e9
vector<int> graph[MAX_SIZE];
map<int, int> tnum;
map<pair<int, int>, int> edge;
map<pair<int, int>, int> rev_edge;
int d[MAX_SIZE][1 << 11];
void setting(int n, vector<vector<int>>& roads, vector<int>& traps)
{
	for (int i = 1; i <= n; i++)
		tnum[i] = 0;
	for (int i = 0; i < traps.size(); i++)
		tnum[traps[i]] = i + 1;
	for (const auto& road : roads) {
		int s = road[0], e = road[1], d = road[2];
		graph[s].push_back(e);
		graph[e].push_back(s);
		if (edge.find({ s, e }) == edge.end())
			edge[{s, e}] = d;
		else
			edge[{s, e}] = min(edge[{s, e}], d);

		if (rev_edge.find({ e, s }) == rev_edge.end())
			rev_edge[{e, s}] = d;
		else
			rev_edge[{e, s}] = min(rev_edge[{e, s}], d);
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < (1 << 11); j++) {
			d[i][j] = INF;
		}
	}
}
void dijkstra(int start)
{
	//가중치, 정점, 트랩 상태
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ 0,{ start, 0 } });
	d[start][0] = 0;
	while (!pq.empty()) {
		int curV = pq.top().second.first;
		int curDist = -pq.top().first;
		int curTrap = pq.top().second.second;
		pq.pop();
		for (int i = 0; i < graph[curV].size(); i++) {
			int nextV = graph[curV][i];
			int nextTrap = tnum[nextV] > 0 ? curTrap ^ (1 << tnum[nextV]) : curTrap;
			bool f1 = curTrap & (1 << tnum[curV]);
			bool f2 = curTrap & (1 << tnum[nextV]);
			if ((f1 && f2) || (!f1 && !f2)) {
				if (edge.find({ curV, nextV }) != edge.end() &&
					d[nextV][nextTrap] > curDist + edge[{curV, nextV}]) {
					d[nextV][nextTrap] = curDist + edge[{curV, nextV}];
					pq.push({ -d[nextV][nextTrap],{ nextV, nextTrap } });
				}
			}
			else {
				if (rev_edge.find({ curV, nextV }) != rev_edge.end() &&
					d[nextV][nextTrap] > curDist + rev_edge[{curV, nextV}]) {
					d[nextV][nextTrap] = curDist + rev_edge[{curV, nextV}];
					pq.push({ -d[nextV][nextTrap],{ nextV, nextTrap } });
				}
			}
		}
	}
}
int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
	int answer = INF;
	setting(n, roads, traps);
	dijkstra(start);
	for (int i = 0; i < (1 << 11); i++)
		answer = min(answer, d[end][i]);
	return answer;
}

void main()
{
	//solution(3, 1, 3, { {1, 2, 2}, {3, 2, 3} }, { 2 });
	solution(4, 1, 4, { { 1, 2, 1 },{ 3, 2, 1 },{ 2, 4, 1 } }, { 2, 3 });
}