#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
#define HIT 1
#define MISS 5
deque<string> cache;
void _transform(string& str)
{
	for (auto& c : str) {
		if ('A' <= c && c <= 'Z')
			c += 32;
	}
}
int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	for (auto city : cities) {
		_transform(city);
		auto it = find(cache.begin(), cache.end(), city);
		if (cacheSize == 0)
			answer += MISS;
		else if (cache.end() == it) {
			if (!cache.empty() && cache.size() >= cacheSize)
				cache.pop_front();
			cache.push_back(city);
			answer += MISS;
		}
		else {
			cache.erase(it);
			cache.push_back(city);
			answer += HIT;
		}
	}
	return answer;
}