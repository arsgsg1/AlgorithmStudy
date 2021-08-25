#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;
vector<vector<string>> v;
vector<string> result;
bool IsUniqueKey(vector<int>& picked)
{
	vector<string> temp(v.size(), "");
	set<string> candidates;
	for (const auto& pick : picked)
		for (int i = 0; i < v.size(); i++)
			temp[i] += v[i][pick];

	for (const auto& str : temp) {
		//유일성이 만족되지 않으면 후보키가 아님
		if (candidates.find(str) != candidates.end())
			return false;
		else
			candidates.insert(str);
	}
	return true;
}
void UpdateMinimal(vector<int>& picked)
{
	string str = "";
	for (const auto& pick : picked)
		str += to_string(pick);
	for (const auto& key : result) {
		int cnt = key.length(), idx = 0;
		for (const auto& c : str)
			if (c == key[idx])
				idx++;
		//최소성이 만족되지 않으면 후보키가 아님
		if (idx == cnt)
			return;
	}
	result.push_back(str);
}
void bf(int n, vector<int>& picked, int toPick, int idx)
{
	if (toPick == 0 && IsUniqueKey(picked)) {
		UpdateMinimal(picked);
		return;
	}
	int smallest = picked.empty() ? 0 : idx + 1;
	for (int next = smallest; next < n; ++next) {
		picked.push_back(next);
		bf(n, picked, toPick - 1, next);
		picked.pop_back();
	}
}
int solution(vector<vector<string>> relation) {
	int answer = 0;
	vector<int> picked;
	v = relation;
	for (int toPick = 1; toPick <= relation[0].size(); toPick++)
		bf(relation[0].size(), picked, toPick, 0);
	answer = result.size();
	return answer;
}