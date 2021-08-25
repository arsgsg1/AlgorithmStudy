#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

unordered_set<int> cands;

bool check(int user_idx, int banned_idx, vector<string>& user_id, vector<string>& banned_id) {
    string user = user_id[user_idx];
    string banned = banned_id[banned_idx];
    
    if (user.size() != banned.size()) return false;
    
    for (int i = 0; i < user.size(); i++) {
        if (banned[i] == '*') continue;
        if (user[i] != banned[i]) return false;
    }
    
    return true;
}

void dfs(int user_idx, int banned_idx, int mask, vector<string>& user_id, vector<string>& banned_id) {
    if (banned_idx == banned_id.size()) {
        cands.insert(mask);
        return;
    }
    
    for (int i = 0; i < user_id.size(); i++) {
        if (mask & (1 << i)) continue;
        if (check(i, banned_idx, user_id, banned_id))
            dfs(i, banned_idx + 1, mask | (1 << i), user_id, banned_id);
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    dfs(0, 0, 0, user_id, banned_id);
    return cands.size();
}
