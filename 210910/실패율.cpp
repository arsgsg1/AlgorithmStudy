#include <vector>
#include <algorithm>

using namespace std;

long long sum[502], psum[503];

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    for (int i = 1; i <= N; i++) answer.push_back(i);
    for (auto stage : stages) sum[stage]++;
    for (int i = N + 1; i > 0; i--) psum[i] += psum[i + 1] + sum[i];

    sort(answer.begin(), answer.end(), [](const int a, const int b) {
        if (sum[a] * psum[b] != sum[b] * psum[a]) {
            return sum[a] * psum[b] > sum[b] * psum[a];
        }
        return a < b;
    });
    return answer;
}
