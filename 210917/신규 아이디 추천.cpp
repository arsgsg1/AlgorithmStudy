#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string new_id) {
	string answer = "";
	string tmp = "";

	//1�ܰ�
	transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);

	//2�ܰ�
	for (int i = 0; i < new_id.size(); i++) {
		if ((new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9') || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.') {
			answer += new_id[i];
		}
	}

	//3�ܰ�
	for (int i = 0; i < answer.size(); i++) {
		if (answer[i] == '.') {
			int cnt = 0;

			for (int j = i + 1; j < answer.size(); j++) {
				if (answer[j] == '.') {
					cnt++;
				}
				else {
					break;
				}
			}

			if (cnt > 0) {
				tmp += '.';
				i += cnt;
			}
			else {
				tmp += answer[i];
			}
		}
		else {
			tmp += answer[i];
		}
	}

	//4�ܰ�
	if (tmp.front() == '.') {
		tmp.erase(tmp.begin());
	}
	if (tmp.back() == '.') {
		tmp.pop_back();
	}

	//5�ܰ�
	if (tmp.empty()) {
		tmp = "a";
	}

	//6�ܰ�
	if (tmp.size() >= 16) {
		tmp = tmp.substr(0, 15);
	}
	if (tmp.back() == '.') {
		tmp.pop_back();
	}

	//7�ܰ�
	while (tmp.size() <= 2) {
		tmp.push_back(tmp.back());
	}

	return tmp;
}