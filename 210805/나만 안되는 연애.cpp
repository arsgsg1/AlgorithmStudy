#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <string.h>

using namespace std;

typedef long long ll;

int n, m, p[1001];
char school_types[1001];
vector<pair<pair<int, int>, int>> edges;

int find_parent(int x)
{
	if (p[x] == x)
		return x;

	return p[x] = find_parent(p[x]);
}

void union_parent(int a, int b)
{
	a = find_parent(a);
	b = find_parent(b);

	if (a < b)
		p[a] = b;
	else
		p[b] = a;
}

bool cmp(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2)
{
	return p1.second < p2.second;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		p[i] = i;
		cin >> school_types[i];
	}

	for (int i = 0; i < m; i++)
	{
		int u, v, d;
		cin >> u >> v >> d;

		if (school_types[u] != school_types[v])
			edges.push_back({ { u, v }, d });
	}

	sort(edges.begin(), edges.end(), cmp);

	int ans = 0, cnt = 0;
	for (auto edge : edges)
	{
		int u = edge.first.first;
		int v = edge.first.second;
		int d = edge.second;

		if (find_parent(u) != find_parent(v))
		{
			union_parent(u, v);
			ans += d;
			if (++cnt == n - 1)
			{
				cout << ans << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;

	return 0;
}