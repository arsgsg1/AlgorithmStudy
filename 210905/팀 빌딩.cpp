/*
투 포인터 감은 잡았지만 어떤 방향으로 범위를 축소시켜야 하는지는 틀림
시간 제한 1초, 메모리제한 1G
완전 탐색 -> N이 10만이기 때문에 시간초과
- 답을 찾기 위해 범위를 줄여가면서 탐색해야 함.
- 범위를 줄이면, 계산 결과가 줄어들기 때문에 능력치의 차이를 줄이는 방향이 더 큰 값을 얻음.
*/
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_SIZE 100001
int N;
int arr[MAX_SIZE];
int calc(int startIdx, int endIdx)
{
	int tmp1 = endIdx - startIdx - 1;
	int tmp2 = min(arr[startIdx], arr[endIdx]);
	return tmp1 * tmp2;
}
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);
	int s = 1, e = N, answer = 0;
	while (s < e - 1) {
		answer = max(answer, calc(s, e));
		if (arr[s] < arr[e])
			s++;
		else
			e--;
	}
	printf("%d\n", answer);
	return 0;
}