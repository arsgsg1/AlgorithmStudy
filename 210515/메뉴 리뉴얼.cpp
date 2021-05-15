#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int cnt[27]; // cnt[i]=n : ���̰� i�� ���� �� �ִ� �ֹ� Ƚ���� n��
unordered_map<string, int> um; // um[str]=n : ���� str�� �ֹ� Ƚ���� n��
vector<string> menu[27][21]; // menu[i][j] : ���̰� i�̰� j�� �ֹ��� ���յ��� ���

void comb(string s, int idx, string made) {
	if (made.size()>1) { // 2�� �̻� �ֹ��� �͸�
		um[made]++; // �ش� ���� �ֹ� Ƚ�� ����
		cnt[made.size()] = max(cnt[made.size()], um[made]); // ���� ���� �� �ִ� �ֹ� Ƚ�� ����
		menu[made.size()][um[made]].push_back(made); // �з��� ���� ��� �߰�
	}
	// ��Ʈ��ŷ
	for (int i = idx + 1; i<s.size(); i++) {
		made.push_back(s[i]);
		comb(s, i, made);
		made.pop_back();
	}
}
vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;

	// order�� ��� ���� ��ó��
	for (string& s : orders) {
		sort(s.begin(), s.end()); // ������ �ٸ��� �ߺ��� ������ ������ �ʵ��� ����
		comb(s, -1, "");
	}

	// ���� ����
	for (int i : course)
		if (cnt[i]>1) // ���̰� i�� ������ �ִ� �ֹ� Ƚ���� 1 �̻��� ��츸
			for (string s : menu[i][cnt[i]])
				answer.push_back(s);

	sort(answer.begin(), answer.end());

	return answer;
}