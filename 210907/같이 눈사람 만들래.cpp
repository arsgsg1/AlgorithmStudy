/*
완전탐색 : 600C4의 경우의 수로 시간초과
두 개의 눈덩이로 눈사람을 만드는 경우 -> 이중 포문
2가지 방법 (정렬이 핵심)
1. 하나의 눈사람을 만드는 경우를 모두 구하고, 정렬한 뒤 인덱스가 겹치지 않으면서, 바로 다음 값을 고름 (차이가 가장 작기 때문)
2. 눈덩이를 고르기 위해 3칸의 padding을 두고, 이중 포문 + 투포인터로 최솟값 탐색
*/
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define MAX_SIZE 600
int N, answer = 2e9 + 1;
int arr[MAX_SIZE];
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + N);
	int elsa, anna;
	for (int i = 0; i < N - 3; i++) {
		for (int j = i + 3; j < N; j++) {
			anna = arr[i] + arr[j];
			int s = i + 1, e = j - 1;
			while (s < e) {
				elsa = arr[s] + arr[e];
				int result = anna - elsa;
				answer = min(abs(result), answer);
				if (result > 0)
					s++;
				else
					e--;
			}
		}
	}
	printf("%d\n", answer);
	return 0;
}