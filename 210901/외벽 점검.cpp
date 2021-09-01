#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 10;
    deque<int> weak_points;

    for (auto weak_point : weak) weak_points.push_back(weak_point);

    sort(dist.begin(), dist.end());

    for (int i = 0; i < weak.size(); i++) {
        do {
            int w = 0, j = 0;
            for (; j < dist.size() && w < weak_points.size(); j++) {
                int end = weak_points[w] + dist[j];
                while (w < weak_points.size() && weak_points[w] <= end) w++;
            }
            if (w == weak_points.size()) answer = min(answer, j);
        } while (next_permutation(dist.begin(), dist.end()));
        weak_points.push_back(weak_points.front() + n);
        weak_points.pop_front();
    }

    if (answer == 10) return -1;
    return answer;
}