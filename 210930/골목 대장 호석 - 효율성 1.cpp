#include <bits/stdc++.h>
#define pii pair<int,int>
#define INF 987654321
using namespace std;

int n, m, a, b, c;
vector<vector<pii>> g;

bool dijkstra(int k) {
	vector<int> dist(n + 1, INF);
	vector<bool> visit(n + 1, false);

	visit[a] = true;
	dist[a] = 0;

	priority_queue<pii> pq;
	pq.push(make_pair(0, a));

	while (!pq.empty()) {
		int cur = pq.top().second; pq.pop();

		visit[cur] = true;
		if (cur == b) return dist[b] <= c;
		for (auto x : g[cur]) {
			if (visit[x.second] || (x.first>k))continue;
			if (dist[x.second] > dist[cur] + x.first) {
				dist[x.second] = dist[cur] + x.first;
				pq.push(make_pair(-dist[x.second], x.second));
			}
		}
	}
	return false;
}

int main() {
	scanf("%d%d%d%d%d", &n, &m, &a, &b, &c);
	g = vector<vector<pii>>(n + 1, vector<pii>());

	for (int i = 0, u, v, w; i < m; i++) {
		scanf("%d%d%d", &u, &v, &w);
		g[u].push_back(make_pair(w, v));
		g[v].push_back(make_pair(w, u));
	}

	int left = -1, right = 21;
	while (left + 1 < right) {
		int mid = (left + right) / 2;
		if (dijkstra(mid))
			right = mid;
		else left = mid;
	}
	printf("%d", right == 21 ? -1 : right);
	return 0;
}