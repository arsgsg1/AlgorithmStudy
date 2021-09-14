#include <string>
#include <vector>

using namespace std;
vector<vector<int>> m;
bool canMakeBlock(int r, int c)
{
	for (int i = 0; i < r; i++) {
		if (m[i][c])
			return false;
	}
	return true;
}
bool findBlocks(int r, int c, int h, int w)
{
	int emptyBlock = 0;
	int blockNum = -1;
	for (int i = r; i < r + h; i++) {
		for (int j = c; j < c + w; j++) {
			if (!m[i][j]) {
				if (!canMakeBlock(i, j)) {
					return false;
				}
				emptyBlock++;
				if (emptyBlock > 2)
					return false;
			}
			else {
				if (blockNum != -1 && blockNum != m[i][j]) {
					return false;
				}
				blockNum = m[i][j];
			}
		}
	}
	for (int i = r; i < r + h; i++) {
		for (int j = c; j < c + w; j++) {
			m[i][j] = 0;
		}
	}
	return true;
}
int solution(vector<vector<int>> board) {
	int answer = 0, cnt;
	int n = board.size();
	m = board;
	do {
		cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i <= n - 2 && j <= n - 3 && findBlocks(i, j, 2, 3)) {
					cnt++;
				}
				else if (i <= n - 3 && j <= n - 2 && findBlocks(i, j, 3, 2)) {
					cnt++;
				}
			}
		}
		answer += cnt;
	} while (cnt);
	return answer;
}