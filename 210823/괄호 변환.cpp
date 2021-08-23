#include <string>
#include <vector>

using namespace std;

bool check_right(string w) {
    int br = 0;
    for (auto c : w) {
        if (c == '(')
            br++;
        else
            br--;
        if (br < 0) return false;
    }
    return br == 0;
}

int check_balance(string w) {
    int i = 0, br = 0;
    for (; i < w.size(); i++) {
        if (w[i] == '(')
            br++;
        else
            br--;
        if (br == 0) break;
    }
    return i;
}

string solution(string w) {
    string answer = "";
    if (w == "") return w;
    if (check_right(w)) return w;

    int idx = check_balance(w);
    string u = w.substr(0, idx + 1);
    string v = w.substr(idx + 1);

    if (check_right(u)) return u + solution(v);

    for (auto& c : u) c = c == '(' ? ')' : '(';
    return '(' + solution(v) + ')' + u.substr(1, u.size() - 2);
}