#include<bits/stdc++.h>

using namespace std;
using ll = long long;

struct info {
	ll to, weight;
	bool operator<(const info& cur) const {
		return weight > cur.weight;
	}
};

ll n, m, A, B, C;
ll dist[100001];
vector<info> v[100001];

const ll inf = (ll)1e15;
bool dijk(ll x, ll cost);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll x, y, c;
	cin >> n >> m >> A >> B >> C;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> c;
		v[x].push_back({ y,c });
		v[y].push_back({ x,c });
	}
	ll ans = -1;
	ll l = 0, r = inf;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (!dijk(A, mid))
			l = mid + 1;
		else {
			ans = mid;
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
}
bool dijk(ll x, ll cost)
{
	for (int i = 1; i <= n; i++)
		dist[i] = inf;

	priority_queue<info> pq;
	pq.push({ x,0 });
	dist[x] = 0;
	while (!pq.empty())
	{
		info cur = pq.top();
		pq.pop();

		if (dist[cur.to]<cur.weight)continue;

		for (int i = 0; i < v[cur.to].size(); i++) {
			ll next = v[cur.to][i].to;
			ll next_weight = v[cur.to][i].weight;
			if (cost >= next_weight && dist[next] > dist[cur.to] + next_weight) {
				dist[next] = dist[cur.to] + next_weight;
				pq.push({ next,dist[next] });
			}
		}
	}
	if (dist[B] <= C)return true;
	return false;
}