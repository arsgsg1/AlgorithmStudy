#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
bool IsBalance(const string& str)
{
	int l = 0, r = 0;
	for (const auto& c : str) {
		if (c == '(')
			l++;
		else
			r++;
	}
	return l == r;
}
bool IsCorrect(const string& str)
{
	stack<char> s;
	for (const auto& c : str) {
		if (c == '(')
			s.push(c);
		else {
			if (!s.empty() && s.top() == '(')
				s.pop();
			else
				s.push(c);
		}
	}
	return !s.size();
}
string reform(const string & str)
{
	string result = "";
	int size = str.size();
	for (int i = 1; i < size - 1; i++) {
		if (str[i] == '(')
			result += ")";
		else
			result += "(";
	}
	return result;
}
void rule2_split(const string& str, string& u, string& v)
{
	int len = 2, size = str.length();
	while (len <= size) {
		u = str.substr(0, len);
		v = str.substr(len);
		if (IsBalance(u))
			break;
		len += 2;
	}
}
string solution(string p) {
	if (!p.size()) return p;
	string u, v;
	rule2_split(p, u, v);
	if (IsCorrect(u))
		return u + solution(v);
	return "(" + solution(v) + ")" + reform(u);
}

void main()
{
	cout << solution("(()())()") << endl;
	cout << solution(")(") << endl;
	cout << solution("()))((()") << endl;
}