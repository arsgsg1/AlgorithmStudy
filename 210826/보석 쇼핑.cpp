#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    unordered_map<string, int> m;
    
    for (auto& gem : gems) m[gem]++;
    int gem_num = (int) m.size();
    m.clear();
    
    int l = 0, r = 0, mn = 1e5;
    while (l <= r && r < gems.size()) {
        m[gems[r++]]++;
        while (m.size() == gem_num) {
            if (r - l < mn) {
                mn = r - l;
                answer[0] = l + 1;
                answer[1] = r;
            }
            if (!--m[gems[l]]) m.erase(gems[l]);
            l++;
        }
    }
    return answer;
}
