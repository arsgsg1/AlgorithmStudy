#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

const int MAX = 100001;
int cnt[MAX];

vector<int> solution(string s) {
    vector<int> answer;
    istringstream iss(s);
    string token;
    while (getline(iss, token, ',')) {
        int num = 0;
        for (auto c : token)
            if (isdigit(c)) num = num * 10 + c - '0';
        cnt[num]++;
    }

    vector<pair<int, int>> v;
    for (int i = 0; i < MAX; i++)
        if (cnt[i]) v.push_back({cnt[i], i});

    sort(v.begin(), v.end(), greater<>());

    for (auto p : v) answer.push_back(p.second);

    return answer;
}