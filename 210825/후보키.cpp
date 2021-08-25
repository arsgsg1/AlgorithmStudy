#include <string>
#include <vector>
#include <set>

using namespace std;

bool included(int k, vector<int>& keys) {
    for (auto key : keys)
        if ((key & k) == key) return true;
    return false;
}

int solution(vector<vector<string>> relation) {
    int n = relation.size();
    int m = relation[0].size();
    vector<int> keys;
    
    for (int k = 1; k < (1 << m); k++) {
        if (included(k, keys)) continue;
        
        set<string> rows;
        for (int i = 0; i < n; i++) {
            string s;
            for (int j = 0; j < m; j++)
                if (k & (1 << j)) s += relation[i][j] + ';';
            rows.insert(s);
        }
        
        if (rows.size() == n) keys.push_back(k);
    }
    return keys.size();
}
