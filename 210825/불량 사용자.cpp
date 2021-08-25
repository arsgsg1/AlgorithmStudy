#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
bool used[10];
int answer = 0;
set<string> S;

bool isBan(string a, string b) {
	if (a.length() != b.length())
		return false;
	for (int i = 0; i <a.length(); i++)
		if (a[i] != b[i] && b[i] != '*')
			return false;
	return true;
}

void dfs(int idx, vector<string> user_id, vector<string> banned_id) {
	if (idx == banned_id.size()) {
		string tmp;
		for (int i = 0; i < user_id.size(); i++) {
			if (used[i]) {
				tmp += user_id[i];
			}
		}
		if (S.find(tmp) != S.end())
			return;
		S.insert(tmp);
		answer++;
		return;
	}
	for (int i = 0; i <user_id.size(); i++)
		if (!used[i] && isBan(user_id[i], banned_id[idx])) {
			used[i] = true;
			dfs(idx + 1, user_id, banned_id);
			used[i] = false;
		}
}

int solution(vector<string> user_id, vector<string> banned_id) {
	dfs(0, user_id, banned_id);
	return answer;
}