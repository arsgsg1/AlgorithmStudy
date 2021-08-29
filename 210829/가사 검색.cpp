/*
접근 방식
이분탐색
주어진 단어들을 길이, 문자열의 알파벳 순서로 정렬
쿼리 문자의 ?문자에 알파벳 순서가 가장 높거나 낮은 문자를 임시로 넣어 log2의 복잡도로 처리하도록 함.
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool comp(const string& a, const string& b)
{
	if (a.length() < b.length())
		return true;
	else if (a.length() == b.length()) {
		if (a < b)
			return true;
	}
	return false;
}
vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;
	vector<string> reverseWords = words;
	for (int i = 0; i < reverseWords.size(); i++)
		reverse(reverseWords[i].begin(), reverseWords[i].end());
	sort(words.begin(), words.end(), comp);
	sort(reverseWords.begin(), reverseWords.end(), comp);

	for (int i = 0; i < queries.size(); i++) {
		int l, r, idx;
		string query = queries[i];
		if (queries[i][0] == '?') {
			reverse(query.begin(), query.end());
			idx = query.find_first_of('?');

			for (int j = idx; j < query.length(); j++)
				query[j] = 'a';
			l = lower_bound(reverseWords.begin(), reverseWords.end(), query, comp) - reverseWords.begin();
			for (int j = idx; j < query.length(); j++)
				query[j] = 'z';
			r = upper_bound(reverseWords.begin(), reverseWords.end(), query, comp) - reverseWords.begin();
		}
		else {
			idx = query.find_first_of('?');
			for (int j = idx; j < query.length(); j++)
				query[j] = 'a';
			l = lower_bound(words.begin(), words.end(), query, comp) - words.begin();
			for (int j = idx; j < query.length(); j++)
				query[j] = 'z';
			r = upper_bound(words.begin(), words.end(), query, comp) - words.begin();
		}
		answer.push_back(r - l);
	}
	return answer;
}