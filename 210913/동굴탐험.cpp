#include <string>
#include <vector>
#include <queue>

using namespace std;

bool answer = true;
int counter = 0;

void dfs(vector<vector<int>> &before, vector<int> &discover, vector<bool> &finish, int here) {
	discover[here] = counter++;

	for (int there : before[here]) {
		if (discover[there] == -1) {
			dfs(before, discover, finish, there);
		}
		else if (discover[there] > discover[here]) {
			continue;
		}
		else if (discover[there] < discover[here]) {
			if (!finish[there]) {
				answer = false;
				return;
			}
			else {
				continue;
			}
		}
	}

	finish[here] = true;

	return;
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
	vector<vector<int>> cave(n);

	for (int i = 0; i < n - 1; i++) {
		int a = path[i][0];
		int b = path[i][1];

		cave[a].push_back(b);
		cave[b].push_back(a);
	}

	vector<vector<int>> before(n);

	vector<bool> visited(n, false);
	queue<int> q;

	visited[0] = true;
	q.push(0);
	while (!q.empty()) {
		int here = q.front(); q.pop();

		for (int there : cave[here]) {
			if (visited[there]) continue;

			before[there].push_back(here);

			visited[there] = true;
			q.push(there);
		}
	}

	for (int i = 0; i < order.size(); i++) {
		int a = order[i][0];
		int b = order[i][1];

		before[b].push_back(a);
	}

	if (before[0].size() != 0) return false;

	vector<int> discover(n, -1);
	vector<bool> finish(n, false);

	for (int i = n - 1; i >= 0; i--) {
		if (!answer) break;
		if (finish[i]) continue;

		dfs(before, discover, finish, i);
	}


	return answer;
}