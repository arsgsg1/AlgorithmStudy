#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 1e4 + 1;
const int ROOT = 1;

int N;
int regidents[MAX];
vector<int> villages[MAX];
vector<int> tree[MAX];
int cache[MAX][2]; //우수마을일 경우, 우수마을이 아닐 경우를 저장하기 위함.
bool visited[MAX];

int func(int idx, bool isExcellent)
{
	int &result = cache[idx][isExcellent];

	if (result != -1)
	{
		return result;
	}

	result = 0;

	for (int i = 0; i < tree[idx].size(); i++)
	{
		int nextIdx = tree[idx][i];
		int firstCandidate = func(nextIdx, false);
		int secondCandidate = -1;

		if (isExcellent == false)
		{
			secondCandidate = func(nextIdx, true);
		}

		result += max(firstCandidate, secondCandidate);
	}

	if (isExcellent)
	{
		result += regidents[idx];
	}

	return result;
}

void createTree(int idx)
{
	for (int i = 0; i < villages[idx].size(); i++)
	{
		int nextIdx = villages[idx][i];

		if (visited[nextIdx] == false)
		{
			tree[idx].push_back(nextIdx);
			visited[nextIdx] = true;

			createTree(nextIdx);
		}
	}
}

int main(void)
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> regidents[i];
	}

	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;

		villages[a].push_back(b);
		villages[b].push_back(a);
	}

	visited[ROOT] = true;
	createTree(ROOT);

	memset(cache, -1, sizeof(cache));

	int result = max(func(1, false), func(1, true));

	cout << result << "\n";

	return 0;
}