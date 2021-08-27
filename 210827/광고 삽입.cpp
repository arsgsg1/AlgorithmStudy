#include <string>
#include <vector>
using namespace std;
long long play_cnt[360001];
int timeConvert(const string& str)
{
	int total = 0;
	total += stoi(str.substr(0, 2)) * 3600;
	total += stoi(str.substr(3, 2)) * 60;
	total += stoi(str.substr(6, 2));
	return total;
}
string stringConvert(const int time)
{
	string str, hour, min, sec;
	hour = to_string(time / 3600);
	if (hour.size() == 1)
		hour.insert(hour.begin(), '0');
	min = to_string(time % 3600 / 60);
	if (min.size() == 1)
		min.insert(min.begin(), '0');
	sec = to_string(time % 60);
	if (sec.size() == 1)
		sec.insert(sec.begin(), '0');
	str = hour + ":" + min + ":" + sec;
	return str;
}
string solution(string play_time, string adv_time, vector<string> logs) {
	string answer = "";
	int start = 0, finish = timeConvert(play_time);
	int playTime = timeConvert(play_time);
	int advTime = timeConvert(adv_time);
	for (const auto& log : logs) {
		int s = timeConvert(log.substr(0, 8));
		int e = timeConvert(log.substr(9, 8));
		play_cnt[s]++;
		play_cnt[e]--;
	}
	for (int i = 1; i <= playTime; i++)
		play_cnt[i] += play_cnt[i - 1];
	for (int i = 1; i < playTime; i++)
		play_cnt[i] += play_cnt[i - 1];

	int startTime = 0;
	long long max_time = play_cnt[advTime - 1], max_startTime = 0;
	for (int i = 0; i + advTime <= playTime; i++) {
		long long tmp = play_cnt[i + advTime] - play_cnt[i];
		if (tmp > max_time) {
			max_time = tmp;
			max_startTime = i + 1;
		}
	}
	answer = stringConvert(max_startTime);
	return answer;
}