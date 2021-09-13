#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int digits(int x) {
    int ret = 0;
    while (x) {
        ret++;
        x /= 10;
    }
    return ret;
}

int solution(string s) {
    int n = s.length();
    int answer = n;
    for (int i = 1; i <= n / 2; ++i) {
        int cnt = 1, len = n;
        for (int j = 0; j + i < n; j += i) {
            if (s.substr(j, i) == s.substr(j + i, i)) {
                cnt++;
                len -= i;
            } else {
                if (cnt > 1) len += digits(cnt);
                cnt = 1;
            }
        }
        if (cnt > 1) len += digits(cnt);
        answer = min(answer, len);
    }
    return answer;
}