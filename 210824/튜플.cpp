#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
bool cmp(pair<int, int>& p1, pair<int, int>& p2)
{
	return p1.second > p2.second;
}
vector<int> solution(string s) {
	vector<int> answer;
	vector<pair<int, int >> v;
	map<int, int> m;
	string buf = "";
	for (int i = 2; i < s.size() - 1; i++) {
		int num = 0;
		buf += s[i];
		if (s[i] == '{' || s[i] == ',' || s[i] == '}') {
			buf.pop_back();
			if (buf.size()) {
				num = stoi(buf);
				m[num]++;
				buf.clear();
			}
			continue;
		}
	}
	for (const auto& it : m)
		v.push_back({ it.first, it.second });
	sort(v.begin(), v.end(), cmp);
	for (const auto& it : v)
		answer.push_back(it.first);
	return answer;
}
void main()
{
	//solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
	solution("{{4,2,3},{3},{2,3,4,1},{2,3}}");
}