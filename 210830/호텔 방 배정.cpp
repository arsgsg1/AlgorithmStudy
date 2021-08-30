#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<long long, long long> m;

long long find(long long number) {
    if (!m[number]) return number;
    return m[number] = find(m[number]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    for (auto number : room_number) {
        long long next = find(number);
        answer.push_back(next);
        m[next] = find(next + 1);
    }
    return answer;
}
