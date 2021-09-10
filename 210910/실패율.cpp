#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct stage {
	double failedRatio;
	int idx;
};
bool cmp(stage& s1, stage& s2)
{
	if (s1.failedRatio == s2.failedRatio)
		return s1.idx < s2.idx;
	return s1.failedRatio > s2.failedRatio;
}
vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<stage> v;
	stage s;
	double ratio;
	sort(stages.begin(), stages.end());
	for (int i = 1; i <= N; i++) {
		int l = lower_bound(stages.begin(), stages.end(), i) - stages.begin();
		int h = upper_bound(stages.begin(), stages.end(), i) - stages.begin();
		s.idx = i;
		if (stages.size() - l == 0)
			s.failedRatio = 0;
		else {
			ratio = (double)(h - l) / (stages.size() - l);
			s.failedRatio = ratio;
		}
		v.push_back(s);
	}
	sort(v.begin(), v.end(), cmp);
	for (const auto& st : v)
		answer.push_back(st.idx);
	return answer;
}