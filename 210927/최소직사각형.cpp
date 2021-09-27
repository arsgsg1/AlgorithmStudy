#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
	int answer = 0;
	int min_w = sizes[0][0], min_h = sizes[0][1];
	for (int i = 1; i < sizes.size(); i++) {
		int a1, a2;
		a1 = max(min_w, sizes[i][0]) * max(min_h, sizes[i][1]);
		a2 = max(min_w, sizes[i][1]) * max(min_h, sizes[i][0]);
		if (a1 < a2) {
			min_w = max(min_w, sizes[i][0]);
			min_h = max(min_h, sizes[i][1]);
		}
		else {
			min_w = max(min_w, sizes[i][1]);
			min_h = max(min_h, sizes[i][0]);
		}
	}
	answer = min_w * min_h;
	return answer;
}