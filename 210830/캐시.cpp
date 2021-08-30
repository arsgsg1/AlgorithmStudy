#include <string>
#include <vector>
#include <list>
#include <algorithm>
#define HIT 1
#define MISS 5

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    list<string> cache;
    if (cacheSize == 0) return cities.size() * MISS;
    for (auto& city : cities) {
        transform(city.begin(), city.end(), city.begin(), ::toupper);
        auto it = find(cache.begin(), cache.end(), city);
        if (it != cache.end()) {
            cache.erase(it);
            cache.push_front(*it);
            answer += HIT;
        } else {
            if (cache.size() == cacheSize) cache.pop_back();
            cache.push_front(city);
            answer += MISS;
        }
    }
    return answer;
}
