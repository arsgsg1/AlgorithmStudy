#include <string>
#include <vector>
#include <map>
using namespace std;
map<string, int> m = {
	{ "one", 1 },
	{ "two", 2 },
	{ "three", 3 },
	{ "four", 4 },
	{ "five", 5 },
	{ "six", 6 },
	{ "seven", 7 },
	{ "eight", 8 },
	{ "nine", 9 },
	{ "zero", 0 }
};
int solution(string s) {
	int answer = 0;
	string buf = "";
	for (const auto& c : s) {
		if ('0' <= c && c <= '9')
			answer = answer * 10 + (c - '0');
		else {
			buf += c;
			if (m.find(buf) != m.end()) {
				answer = answer * 10 + m[buf];
				buf.clear();
			}
		}
	}
	return answer;
}