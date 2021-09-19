/*
110�� ã�� ��� : ���� �ڷᱸ�� ���� ����Ͽ� ������ ����
������ ���ڿ����� �����ʺ��� ���ӵǴ� 1�� ã�´�.
���ڿ� ������ 1�� �ʰ� ���� ���� ���������� ���� ���� ��ġ�Ǳ� �����̴�.
*/
#include <string>
#include <vector>
using namespace std;

vector<string> solution(vector<string> s) {
	vector<string> answer;
	for (const auto& str : s) {
		string temp = "";
		int cnt = 0, size = 0;
		for (const auto& ch : str) {
			temp += ch;
			size++;
			if (size >= 3 && temp[size - 3] == '1' &&
				temp[size - 2] == '1' && temp[size - 1] == '0') {
				cnt++;
				size -= 3;
				for (int i = 0; i < 3; i++)
					temp.pop_back();
			}
		}
		int idx = size - 1;
		string new_str = "";
		for (; idx >= 0; idx--) {
			if (temp[idx] == '0') {
				idx++;
				break;
			}
		}
		if (idx == -1) {
			for (int i = 0; i < cnt; i++)
				new_str += "110";
			new_str += temp;
		}
		else {
			new_str = temp.substr(0, idx);
			for (int i = 0; i < cnt; i++)
				new_str += "110";
			new_str += temp.substr(idx);
		}
		answer.push_back(new_str);
	}
	return answer;
}

void main()
{
	solution({ "101101111010",
		//"1100111011101001",
		"1110",
		"100111100",
		"0111111010" });
}