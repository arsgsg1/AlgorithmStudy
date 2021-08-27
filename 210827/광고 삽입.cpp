#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 360000;
long long psum[MAX];

int toInt(string s) {
    int hh, mm, ss;
    sscanf(s.c_str(), "%d:%d:%d", &hh, &mm, &ss);
    return hh * 3600 + mm * 60 + ss;
}

string toString(int s) {
    string hh = to_string(s / 3600);
    string mm = to_string((s % 3600) / 60);
    string ss = to_string(s % 60);
    if (hh.size() < 2) hh = '0' + hh;
    if (mm.size() < 2) mm = '0' + mm;
    if (ss.size() < 2) ss = '0' + ss;
    return hh + ':' + mm + ':' + ss;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    int play = toInt(play_time);
    int adv = toInt(adv_time);

    for (auto& log : logs) {
        int s = toInt(log.substr(0, 8));
        int e = toInt(log.substr(9));
        psum[s]++;
        psum[e]--;
    }

    for (int i = 1; i < play; i++) psum[i] += psum[i - 1];

    for (int i = 1; i < play; i++) psum[i] += psum[i - 1];

    int start = 0;
    long long mx = 0;
    for (int i = adv - 1; i < play; i++) {
        if (mx < psum[i] - psum[i - adv]) {
            mx = psum[i] - psum[i - adv];
            start = i - adv + 1;
        }
    }

    return toString(start);
}