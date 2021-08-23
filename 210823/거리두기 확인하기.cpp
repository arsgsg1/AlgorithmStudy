#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 987654321
char arr[5][5];
bool visit[5][5];
const int dirRow[] = { 1, 0, -1, 0 };
const int dirCol[] = { 0, 1, 0, -1 };
void parser(const vector<string>& place)
{
	int row = 0;
	for (const auto& str : place) {
		for (int i = 0; i < str.length(); i++) {
			arr[row][i] = str[i];
		}
		row++;
	}
}
//'P' 문자 사이의 거리가 2 이하인 경우 거리 반환, 그렇지 않으면 INF 반환
int dfs(int row, int col, int dist)
{
	int nr, nc, result = INF;
	if (arr[row][col] == 'X' || dist > 2) //base case
		return INF;
	if (visit[row][col] == false) {
		visit[row][col] = true;
		for (int i = 0; i < 4; i++) {
			nr = row + dirRow[i];
			nc = col + dirCol[i];
			if (nr < 0 || nc < 0 || nr >= 5 || nc >= 5)
				continue;
			if (visit[nr][nc] == false && arr[nr][nc] == 'P') //새로운 사람이 있으면 맨해튼 거리를 반환하고 종료
				return dist + 1;
			result = min(result, dfs(nr, nc, dist + 1)); //경우의 수 중에서 조건에 맞는 케이스가 있다면 저장
		}
	}
	return result;
}
vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;
	for (const auto& place : places) {
		parser(place);
		int dist = INF;
		for (int r = 0; r < 5; r++) {
			for (int c = 0; c < 5; c++) {
				if (arr[r][c] == 'P') {
					memset(visit, false, sizeof(visit));
					dist = min(dist, dfs(r, c, 0));
				}
			}
		}
		answer.push_back(dist > 2);
	}
	return answer;
}

void main()
{
	//solution({ {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},{"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},{"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},{"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},{"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"} });
	solution({ { "OOPOO", "OPOOO", "OOOOO", "OOOOO", "OOOOO" } });
}