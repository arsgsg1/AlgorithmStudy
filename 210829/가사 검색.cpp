#include <string>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct TrieNode {
    TrieNode* next[26];
    unordered_map<int, int> count;

    TrieNode() { memset(next, 0, sizeof(next)); }

    void insert(const char* ch, int len) {
        if (*ch == 0) return;
        int cur = *ch - 'a';
        if (next[cur] == NULL) next[cur] = new TrieNode();
        count[len]++;
        next[cur]->insert(ch + 1, len);
    }

    int search(const char* ch, int len) {
        if (*ch == '?') return count[len];
        int cur = *ch - 'a';
        if (next[cur] == NULL) return 0;
        return next[cur]->search(ch + 1, len);
    }
};

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    TrieNode trie = TrieNode();
    TrieNode reverse_trie = TrieNode();
    for (auto& word : words) {
        trie.insert(word.c_str(), word.size());
        reverse(word.begin(), word.end());
        reverse_trie.insert(word.c_str(), word.size());
    }
    for (auto& query : queries) {
        if (query[query.size() - 1] == '?') {
            answer.push_back(trie.search(query.c_str(), query.size()));
        } else {
            reverse(query.begin(), query.end());
            answer.push_back(reverse_trie.search(query.c_str(), query.size()));
        }
    }
    return answer;
}