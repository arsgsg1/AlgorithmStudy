#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
typedef pair<int, int> P;
int N;
bool cmp(P& p1, P& p2)
{
	if (p1.first == p2.first)
		return p1.second > p2.second;
	return p1.first < p2.first;
}

int main()
{
	cin >> N;
	int s, t;
	vector<P> v;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &s, &t);
		v.push_back({ s, t });
	}
	sort(v.begin(), v.end(), cmp);
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < N; i++) {
		int start = v[i].first;
		int end = v[i].second;
		if (!pq.empty() && pq.top() <= start) {
			pq.pop();
		}
		pq.push(end);
	}
	printf("%d\n", pq.size());
	return 0;
}