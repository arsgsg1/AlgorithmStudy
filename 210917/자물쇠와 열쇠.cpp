#include <string>
#include <vector>

using namespace std;
int keySize, lockSize;
vector<vector<bool>> board;
bool check(vector<vector<int>>& key, int row, int col)
{
	int size = key.size();
	bool IsPossible = true;
	auto prev = board;
	for (int i = row; i < row + size; i++)
		for (int j = col; j < col + size; j++)
			board[i][j] = (board[i][j] ^ key[i - row][j - col]);

	for (int i = size; i < size + lockSize; i++) {
		for (int j = size; j < size + lockSize; j++) {
			if (board[i][j] != 1)
				IsPossible = false;
		}
	}

	board = prev;
	return IsPossible;
}
void rotate(vector<vector<int>>& key)
{
	int size = key.size();
	vector<vector<int>> temp(size, vector<int>(size, 0));
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			temp[i][j] = key[j][size - i - 1];

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			key[i][j] = temp[i][j];
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = false;
	keySize = key.size(), lockSize = lock.size();
	board = vector<vector<bool>>(keySize * 2 + lockSize,
		vector<bool>(keySize * 2 + lockSize, false));

	//board setting
	for (int i = keySize; i < keySize + lockSize; i++) {
		for (int j = keySize; j < keySize + lockSize; j++) {
			board[i][j] = lock[i - keySize][j - keySize];
		}
	}
	//check board
	for (int i = 0; i < keySize + lockSize; i++) {
		for (int j = 0; j < keySize + lockSize; j++) {
			for (int k = 0; k < 4; k++) {
				rotate(key);
				if (check(key, i, j))
					return true;
			}
		}
	}
	return answer;
}