#include <map>
#include <vector>

using namespace std;

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    long long sum = 0;
    map<int, int> m;
    for (auto food_time : food_times) {
        sum += food_time;
        m[food_time]++;
    }
    
    if (sum <= k) return -1;
    
    long long total_round = 0;
    long long rest = food_times.size();
    for (auto it = m.begin(); it != m.end(); it++) {
        long long round = it->first - total_round;
        if (round * rest <= k) k -= round * rest;
        else {
            k %= rest;
            for (int i = 0; i < food_times.size(); i++) {
                if (food_times[i] <= total_round) continue;
                if (k-- == 0) return i + 1;
            }
        }
        total_round = it->first;
        rest -= it->second;
    }
    
    return answer;
}
