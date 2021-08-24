#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
#define ll long long
const char pritority_op[3] = { '*', '+', '-' };
vector<ll> number;
vector<char> op;
vector<char> priority;
bool visit[3];
ll result = 0;
void parser(const string& expression)
{
	string buf = "";
	for (const auto& c : expression) {
		buf += c;
		if (c == '-' || c == '*' || c == '+') {
			buf.pop_back();
			op.push_back(c);
			number.push_back(stoi(buf));
			buf.clear();
		}
	}
	number.push_back(stoi(buf));
}

void permutation_calc()
{
	if (priority.size() == 3) {
		vector<char> temp_op = op;
		vector<ll> temp_num = number;
		for (int i = 0; i < priority.size(); i++) {
			for (int j = 0; j < temp_op.size(); j++) {
				if (priority[i] == temp_op[j]) {
					if (temp_op[j] == '+')
						temp_num[j] = temp_num[j] + temp_num[j + 1];
					else if (temp_op[j] == '-')
						temp_num[j] = temp_num[j] - temp_num[j + 1];
					else if (temp_op[j] == '*')
						temp_num[j] = temp_num[j] * temp_num[j + 1];

					temp_num.erase(temp_num.begin() + j + 1);
					temp_op.erase(temp_op.begin() + j);
					j--;
				}
			}
		}
		result = max(result, abs(temp_num[0]));
	}
	for (int i = 0; i < 3; i++) {
		if (visit[i] == false) {
			visit[i] = true;
			priority.push_back(pritority_op[i]);
			permutation_calc();
			visit[i] = false;
			priority.pop_back();
		}
	}
}
long long solution(string expression) {
	parser(expression);
	permutation_calc();
	return result;
}
void main()
{
	//solution("100-200*300-500+20");
	solution("50*6-3*2");
}