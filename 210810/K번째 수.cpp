#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, K;
int main()
{
	scanf("%d %d", &N, &K);
	int low = 1, high = K;
	int answer = -1;
	while (low <= high) {
		int cnt = 0;
		int mid = (low + high) / 2;
		for (int i = 1; i <= N; i++)
			cnt += min(mid / i, N);
		if (cnt < K) {
			low = mid + 1;
		}
		else {
			answer = mid;
			high = mid - 1;
		}
	}
	printf("%d\n", answer);
	return 0;
}