#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

vector<int> solution(vector<string> gems) {
	vector<int> answer;
	gems.insert(gems.begin(), ""); //1부터 시작하는 인덱스로 맞춰줌
	unordered_map<string, int> um;
	unordered_set<string> us;
	for (int i = 1; i < gems.size(); i++)
		us.insert(gems[i]);
	int kind = us.size(); //보석 종류
	int s = 1, e = 1, len = 987654321;
	int answer_start, answer_end;
	while (e < gems.size()) {
		if (um.find(gems[e]) == um.end())
			um[gems[e++]]++;
		else {
			um[gems[e++]]++;
			//왼쪽 포인터와 같은 종류의 보석이면, -1하고 오른쪽으로 이동
			while (um[gems[s]] >= 2) {
				um[gems[s]]--;
				s++;
			}
		}
		//최소 길이, 길이가 같다면, 시작 번호가 낮은걸 저장하기 위함.
		//모든 종류를 저장하고, 더 짧은 길이를 발견했다면 해당 길이와 s, e 저장
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