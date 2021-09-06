#include <iostream>
#include <regex>
#include <unordered_map>
#include <algorithm>

using namespace std;

const regex pattern(R"([A-Za-z]|\d+)");
unordered_map<char, int> alpha;

struct Word {
    string s;
    vector<string> v;
    Word(string& s) : s(s) {
        auto it = sregex_iterator(s.begin(), s.end(), pattern);
        const sregex_iterator end;
        for (; it != end; it++) v.push_back(it->str());
    }
    bool operator<(const Word& rhs) const {
        for (int i = 0; i < min(v.size(), rhs.v.size()); i++) {
            string a = v[i];
            string b = rhs.v[i];
            if (a == b) continue;
            if (isdigit(a[0]) && isdigit(b[0])) {
                int za = 0, zb = 0;
                while (za < a.size() && a[za] == '0') za++;
                while (zb < b.size() && b[zb] == '0') zb++;
                if (a.size() - za != b.size() - zb)
                    return a.size() - za < b.size() - zb;
                for (int j = 0; j < a.size() - za; j++) {
                    if (a[za + j] != b[zb + j]) return a[za + j] < b[zb + j];
                }
                return za < zb;
            } else if (isdigit(a[0]) || isdigit(b[0])) {
                return isdigit(a[0]);
            } else {
                return alpha[a[0]] < alpha[b[0]];
            }
        }
        return v.size() < rhs.v.size();
    }
};

void init() {
    int i = 1;
    for (char ch = 'a'; ch <= 'z'; ch++) {
        alpha[toupper(ch)] = i++;
        alpha[ch] = i++;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    init();

    vector<Word> v;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v.push_back(Word(s));
    }

    sort(v.begin(), v.end());

    for (auto& word : v) cout << word.s << '\n';

    return 0;
}