#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//�׸����� ���
//���� ū ������ ���� ū ���� �̰ܾ� ������
//�׷��� ������ ����
int solution(vector<int> A, vector<int> B) {
	int answer = 0;
	int size = A.size();
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	int Aidx = A.size() - 1;
	int Bidx = B.size() - 1;
	while (size != 0) {
		if (B[Bidx] > A[Aidx]) {
			answer++;
			Bidx--;
			Aidx--;
		}
		else {
			Aidx--;
		}
		size--;
	}
	return answer;
}