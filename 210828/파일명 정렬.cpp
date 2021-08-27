#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;
typedef struct Node {
	string head;
	string number;
	int order;
};
bool comp(const Node& n1, const Node& n2)
{
	if (n1.head == n2.head) {
		if (stoi(n1.number) == stoi(n2.number)) {
			return n1.order < n2.order;
		}
		else {
			return stoi(n1.number) < stoi(n2.number);
		}
	}
	else {
		return n1.head < n2.head;
	}
}
vector<string> solution(vector<string> files) {
	vector<string> answer;
	string head, number = "", tail;
	int num_start = -1, order = 0;
	vector<Node> v;
	for (const auto& file : files) {
		string cp_name = file;
		Node n;
		int cnt = 0;
		num_start = -1;
		transform(cp_name.begin(), cp_name.end(), cp_name.begin(), ::tolower);
		for (int i = 0; i<file.length(); i++) {
			if (num_start != -1 && (file[i] < '0' || file[i] > '9'))
				break;
			if (num_start == -1 && file[i] >= '0' && file[i] <= '9')
				num_start = i;
			if (file[i] >= '0' && file[i] <= '9' && cnt < 5) {
				n.number += file[i];
				cnt++;
			}
		}
		number.clear();
		n.head = cp_name.substr(0, num_start);
		n.order = order++;
		v.push_back(n);
	}
	stable_sort(v.begin(), v.end(), comp);
	for (const auto& item : v) {
		answer.push_back(files[item.order]);
	}
	return answer;
}