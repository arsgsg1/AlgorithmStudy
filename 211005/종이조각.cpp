/*
N의 범위가 작고, 가로 세로와 같이 단순한 방향으로 합계를 구하기 때문에
완전 탐색으로도 풀리는 문제이다.
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int N, M, answer, sum;
int board[5][5];
bool visit[5][5];
int main()
{
	string str;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			board[i][j] = str[j] - '0';
		}
	}
	//2차원 배열을 1차원 배열로 늘려서 생각해보자.
	//각 인덱스의 가로, 세로의 합을 구하는 경우의 수는 총 2^(N*M) 이다.
	for (int i = 0; i < 1 << (N * M); i++) {
		int cur = i, check = 0, total = 0;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				check = j * M + k;
				if (cur & (1 << check)) {
					sum = sum * 10 + board[j][k];
				}
				else {
					total += sum;
					sum = 0;
				}
			}
			total += sum;
			sum = 0;
		}

		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				check = j + k *M;
				if ((cur & (1 << check)) == 0) {
					sum = sum * 10 + board[k][j];
				}
				else {
					total += sum;
					sum = 0;
				}
			}
			total += sum;
			sum = 0;
		}
		answer = max(total, answer);
	}
	printf("%d\n", answer);
	return 0;
}