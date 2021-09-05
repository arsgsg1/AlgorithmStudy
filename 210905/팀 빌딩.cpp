/*
�� ������ ���� ������� � �������� ������ ��ҽ��Ѿ� �ϴ����� Ʋ��
�ð� ���� 1��, �޸����� 1G
���� Ž�� -> N�� 10���̱� ������ �ð��ʰ�
- ���� ã�� ���� ������ �ٿ����鼭 Ž���ؾ� ��.
- ������ ���̸�, ��� ����� �پ��� ������ �ɷ�ġ�� ���̸� ���̴� ������ �� ū ���� ����.
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