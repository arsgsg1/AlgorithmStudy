#include <iostream>
#include <deque>
#include <string>
#include <string.h>
#include <cmath>
using namespace std;
deque<int> wheel[4];
bool visit[4];
int N;
void rotate(int cur, int dir)
{
	if (visit[cur])
		return;
	visit[cur] = true;
	if (0 <= cur - 1) {
		if (wheel[cur][6] != wheel[cur - 1][2]) {
			rotate(cur - 1, -dir);
		}
	}
	if (cur + 1 < 4) {
		if (wheel[cur][2] != wheel[cur + 1][6]) {
			rotate(cur + 1, -dir);
		}
	}

	if (dir == -1) {
		auto temp = wheel[cur].front();
		wheel[cur].pop_front();
		wheel[cur].push_back(temp);
	}
	else {
		auto temp = wheel[cur].back();
		wheel[cur].pop_back();
		wheel[cur].push_front(temp);
	}
}
int main()
{
	string str;
	for (int i = 0; i < 4; i++) {
		cin >> str;
		for (const auto& c : str)
			wheel[i].push_back(c - '0');
	}
	cin >> N;
	int dir, num;
	for (int i = 0; i < N; i++) {
		memset(visit, false, sizeof(visit));
		cin >> num >> dir;
		rotate(num - 1, dir);
	}
	int answer = 0;
	for (int i = 0; i < 4; i++) {
		if (wheel[i][0] == 1)
			answer += pow(2, i);
	}
	printf("%d\n", answer);
	return 0;
}