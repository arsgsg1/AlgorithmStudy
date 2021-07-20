#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <stack>
using namespace std;
set<int> s;

string solution(int n, int k, vector<string> cmd) {
	string answer = "";
	for (int i = 0; i<n; i++)
		s.insert(i);
	set<int> ::iterator it, temp;
	it = s.begin();
	while (k--) {
		it++;
	}
	stack<int> st;
	for (int i = 0; i<cmd.size(); i++) {
		string str = cmd[i];
		char c = str[0];
		if (c == 'C' || c == 'Z') {
			if (c == 'C') {
				st.push(*it);
				temp = it;
				temp++;
				if (temp == s.end()) {
					temp = it;
					--temp;
				}
				s.erase(it);
				it = temp;
			}
			else {
				s.insert(st.top());
				st.pop();
			}
		}
		else {
			string ss = str.substr(2);
			int val = stoi(ss);
			while (val--) {
				if (c == 'D')  ++it;
				else    --it;
			}
		}
	}

	int idx = 0;
	for (it = s.begin(); it != s.end(); it++) {
		int val = *it;
		if (val == idx) {
			answer += 'O';
		}
		else {
			while (idx<val) {
				answer += 'X';
				idx++;
			}
			answer += 'O';
		}
		idx++;
	}
	while (idx<n) {
		answer += 'X';
		idx++;
	}
	return answer;
}