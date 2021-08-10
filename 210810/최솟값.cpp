#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define MAX_SIZE 100001
int N, M;
vector<int> arr;
vector<int> segment;
vector<pair<int, int>> cmd;
int make_segment(int node, int start, int end)
{
	if (start == end) {
		segment[node] = arr[start];
		return segment[node];
	}

	int mid = (start + end) / 2;
	int left = make_segment(node * 2, start, mid);
	int right = make_segment(node * 2 + 1, mid + 1, end);
	segment[node] = min(left, right);
	return segment[node];
}
int query(int node, int start, int end, int left, int right)
{
	if (right < start || left > end) return 2e9;
	if (left <= start && end <= right) return segment[node];

	int mid = (start + end) / 2;
	int left_result = query(node * 2, start, mid, left, right);
	int right_result = query(node * 2 + 1, mid + 1, end, left, right);
	return min(left_result, right_result);
}
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		arr.emplace_back(temp);
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		cmd.emplace_back(make_pair(a, b));
	}
	int tree_height = ceil(log2(N));
	int tree_size = (1 << (tree_height + 1));
	segment.resize(tree_size);
	make_segment(1, 0, N - 1);
	for (int i = 0; i < cmd.size(); i++) {
		int a = cmd[i].first - 1;
		int b = cmd[i].second - 1;
		printf("%d\n", query(1, 0, N - 1, a, b));
	}
	return 0;
}