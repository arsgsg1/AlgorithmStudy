#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

vector<int> solution(vector<string> gems) {
	vector<int> answer;
	gems.insert(gems.begin(), ""); //1���� �����ϴ� �ε����� ������
	unordered_map<string, int> um;
	unordered_set<string> us;
	for (int i = 1; i < gems.size(); i++)
		us.insert(gems[i]);
	int kind = us.size(); //���� ����
	int s = 1, e = 1, len = 987654321;
	int answer_start, answer_end;
	while (e < gems.size()) {
		if (um.find(gems[e]) == um.end())
			um[gems[e++]]++;
		else {
			um[gems[e++]]++;
			//���� �����Ϳ� ���� ������ �����̸�, -1�ϰ� ���������� �̵�
			while (um[gems[s]] >= 2) {
				um[gems[s]]--;
				s++;
			}
		}
		//�ּ� ����, ���̰� ���ٸ�, ���� ��ȣ�� ������ �����ϱ� ����.
		//��� ������ �����ϰ�, �� ª�� ���̸� �߰��ߴٸ� �ش� ���̿� s, e ����
		if (um.size() == us.size() && len > e - s - 1) {
			answer_start = s;
			answer_end = e - 1;
			len = e - s - 1;
		}
	}
	answer.push_back(answer_start);
	answer.push_back(answer_end);
	return answer;
}