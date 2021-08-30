#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool pass(vector<int>& stones, int k, int x) {
    int cnt = 0;
    for (auto stone : stones) {
        if (stone < x) {
            cnt++;
            if (cnt >= k) return false;
        } else cnt = 0;
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    const auto [mn, mx] = minmax_element(stones.begin(), stones.end());
    int lo = *mn, hi = *mx;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (pass(stones, k, mid)) {
            lo = mid + 1;
            answer = max(answer, mid);
        } else {
            hi = mid - 1;
        }
    }
    return answer;
}
