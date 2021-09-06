#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct TrieNode {
    map<string, TrieNode *> dict;
    TrieNode *insert(string s) {
        if (dict.find(s) == dict.end()) {
            dict[s] = new TrieNode();
        }
        return dict[s];
    }
    void find(int floor) {
        for (auto &d : dict) {
            for (int i = 0; i < floor; i++) cout << "--";
            cout << d.first << '\n';
            d.second->find(floor + 1);
        }
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k;
    string s;
    cin >> n;
    TrieNode *head = new TrieNode();
    for (int i = 0; i < n; i++) {
        TrieNode *tail = head;
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> s;
            tail = tail->insert(s);
        }
    }

    head->find(0);

    return 0;
}