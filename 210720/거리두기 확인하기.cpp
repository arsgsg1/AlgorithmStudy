#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
struct info {
	int y, x;
};
int check[5][5];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;
	for (int k = 0; k<5; k++) {
		queue<info> q;
		int avail = 1;
		int idx = 1;
		for (int i = 0; i<5; i++) {
			for (int j = 0; j<5; j++) {
				check[i][j] = 0;
				char c = places[k][i][j];
				if (c == 'P') {
					q.push({ i,j });
					places[k][i][j] = 'O';
					check[i][j] = idx++;
				}
			}
		}
		while (!q.empty()) {
			int cy = q.front().y;
			int cx = q.front().x;
			int cv = check[cy][cx];
			q.pop();
			for (int i = 0; i<4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (nx >= 0 && ny >= 0 && nx<5 && ny<5) {
					if (places[k][ny][nx] == 'X') continue;
					if (check[ny][nx] == cv) {    

					}
					else if (check[ny][nx] == 0) {
						check[ny][nx] = cv;
					}
					else {      
						avail = 0;
						break;
					}
				}
			}
			if (avail != 1) break;
		}
		answer.push_back(avail);
	}
	return answer;
}