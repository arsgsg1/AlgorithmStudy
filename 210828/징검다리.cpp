#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
bool check(vector<int>& stones, int target, int k)
{
	int cnt = 0, result = 0;
	for (const auto& ston : stones) {
		if (ston <= target) {
			cnt++;
		}
		else {
			result = max(result, cnt);
			cnt = 0;
		}
	}
	result = max(result, cnt);
	if (result <= k)
		return true;
	else
		return false;
}
int solution(vector<int> stones, int k) {
	int answer = 0;
	int Max = *max_element(stones.begin(), stones.end());
	int s = 0, e = Max, mid = 0;
	while (s <= e) {
		mid = (s + e) / 2;
		if (check(stones, mid, k)) {
			answer = max(mid, answer);
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
	return answer;
}