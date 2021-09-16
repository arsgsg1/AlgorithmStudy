#include <vector>
#include <algorithm>

using namespace std;

int key_size, lock_size, map_size;

void rotate(vector<vector<int>> &key) {
    vector<vector<int>> temp(key_size, vector<int>(key_size, 0));
    for (int i = 0; i < key_size; ++i) {
        for (int j = 0; j < key_size; ++j) {
            temp[i][j] = key[key_size - 1 - j][i];
        }
    }
    key = temp;
}

bool check(int row, int col, vector<vector<int>> &key,
           vector<vector<int>> map) {
    for (int i = 0; i < key_size; ++i)
        for (int j = 0; j < key_size; ++j) map[row + i][col + j] += key[i][j];
    for (int i = key_size - 1; i <= map_size - key_size; ++i)
        for (int j = key_size - 1; j <= map_size - key_size; ++j)
            if (map[i][j] != 1) return false;
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    key_size = key.size();
    lock_size = lock.size();
    map_size = lock_size + (key_size - 1) * 2;
    vector<vector<int>> map(map_size, vector<int>(map_size, 0));
    for (int i = 0; i < lock_size; ++i)
        for (int j = 0; j < lock_size; ++j)
            map[key_size - 1 + i][key_size - 1 + j] = lock[i][j];
    for (int k = 0; k < 4; ++k) {
        for (int i = 0; i <= map_size - key_size; ++i) {
            for (int j = 0; j <= map_size - key_size; ++j) {
                if (check(i, j, key, map)) return true;
            }
        }
        rotate(key);
    }
    return false;
}