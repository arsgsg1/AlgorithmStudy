#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
string make_string(const string& str, int num)
{
	if (num == 1)
		return str;
	string temp;
	temp = to_string(num) + str;
	return temp;
}
int solution(string s) {
	int answer = 987654321;
	int ParsingSize = s.size() / 2;
	queue<string> q;
	string str, result = "";
	if (s.length() == 1)
		return 1;
	for (int c = 1; c <= ParsingSize; c++) {
		int idx = 0;
		while (1) {
			if (idx + c > s.size()) {
				str = s.substr(idx);
				if (str.length() != 0)
					q.push(str);
				break;
			}
			str = s.substr(idx, c);
			q.push(str);
			idx += c;
		}

		string prev = q.front();
		q.pop();
		int num = 1;
		while (1) {
			if (q.front() == prev)
				num++;
			else {
				result += (make_string(prev, num));
				prev = q.front();
				num = 1;
			}
			q.pop();
			if (q.empty()) {
				result += (make_string(prev, num));
				break;
			}
		}
		answer = min((int)result.length(), answer);
		result.clear();
	}
	return answer;
}