#include <string>
#include <vector>
#include <deque>
#include <iostream>
using namespace std;
deque<int> map[100];
deque<int> collect;
int canGetPoint(int doll)
{
	if (!collect.empty() && collect.back() == doll) {
		collect.pop_back();
		return 2;
	}
	collect.push_back(doll);
	return 0;
}
int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	for (const auto& b : board) {
		for (int i = 0; i < b.size(); i++) {
			//�� ĭ�� ���� ���� ����.
			//�Ʒ� -> ���� �����ϱ� ���� �պ��� �ִ´�.
			if (b[i] != 0)
				map[i].push_front(b[i]);
		}
	}
	for (const auto& m : moves) {
		//�ڿ������� ����. ���� ���� ����.
		auto& d = map[m - 1];
		if (!d.empty()) {
			int doll = d.back();
			cout << doll << endl;
			d.pop_back();
			answer += canGetPoint(doll);
		}
	}
	return answer;
}