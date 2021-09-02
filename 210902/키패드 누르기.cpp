#include <string>
#include <vector>
#include<cmath>
using namespace std;

pair<int, int> get_index(int number) {
	switch (number) {
	case 1:
		return { 0,0 };
	case 2:
		return { 0,1 };
	case 3:
		return { 0,2 };
	case 4:
		return { 1,0 };
	case 5:
		return { 1,1 };
	case 6:
		return { 1,2 };
	case 7:
		return { 2,0 };
	case 8:
		return { 2,1 };
	case 9:
		return { 2,2 };
	case 0:
		return { 3,1 };
	case 10:
		return { 3,0 };
	case 11:
		return { 3,2 };
	}
}

int get_distance(int now, int goal) {
	pair<int, int> cur, to;
	cur = get_index(now);
	to = get_index(goal);
	return abs(cur.first - to.first) + abs(cur.second - to.second);
}

string solution(vector<int> numbers, string hand) {
	string answer = "";
	int lnow, rnow;
	lnow = 10;//현재위치 *
	rnow = 11;//현재위치 #


	for (int i = 0; i<numbers.size(); i++) {
		int next = numbers[i];
		if (next == 1 || next == 4 || next == 7) {
			answer += "L";
			lnow = next;
		}
		else if (next == 3 || next == 6 || next == 9) {
			answer += "R";
			rnow = next;
		}
		else {
			int lgap = get_distance(lnow, next);
			int rgap = get_distance(rnow, next);
			if (lgap<rgap) {
				answer += "L";
				lnow = next;
			}
			else if (lgap>rgap) {
				answer += "R";
				rnow = next;
			}
			else {
				if (hand == "left") {
					answer += "L";
					lnow = next;
				}
				else {
					answer += "R";
					rnow = next;
				}
			}
		}
	}
	return answer;
}