#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define MASK 0x3ffffff //전체 알파벳 마스크
int cur_mask = MASK; //처음 알고 있는 알파벳
int N, M;
vector<int> v;
void convertAlpha2Bit()
{
	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		int word = 0;
		for (const auto& c : str) {
			word |= 1 << c - 'a'; //알파벳을 비트로 변환
		}
		v.push_back(word);
	}
}
int main()
{
	scanf("%d %d", &N, &M);
	convertAlpha2Bit();
	int op = 0;
	char ch = 0;
	for (int i = 0; i < M; i++) {
		scanf("%d %c", &op, &ch);
		if (op == 1) { //<<, &로 특정 비트 지우기
			cur_mask &= MASK - (1 << ch - 'a');
		}
		else {
			cur_mask |= 1 << ch - 'a';
		}
		int cnt = 0;
		for (const auto& word : v) {
			if ((cur_mask & word) == word) {
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}

	return 0;
}