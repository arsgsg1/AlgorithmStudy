#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int mx1 = 0, mx2 = 0;
    for (auto& size : sizes) {
        mx1 = max(mx1, min(size[0], size[1]));
        mx2 = max(mx2, max(size[0], size[1]));
    }
    return mx1 * mx2;
}