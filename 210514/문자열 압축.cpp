#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
//���ڿ� ���ڿ��� ����� ���ڿ� ����
string make_string(const string& str, int num)
{
	if (num == 1)
		return str;
	string temp;
	temp = to_string(num) + str;
	return temp;
}
int solution(string s) {
	int answer = 987654321;
	int ParsingSize = s.size() / 2;
	queue<string> q;
	string str, result = "";
	if (s.length() == 1)
		return 1;
	for (int c = 1; c <= ParsingSize; c++) {
		int idx = 0;
		while (1) {
			//������ ���ڿ��̶��, ť�� ���� �߰�
			if (idx + c > s.size()) {
				str = s.substr(idx);
				if (str.length() != 0)
					q.push(str);
				break;
			}
			//���ڿ��� Ư�� ���̸�ŭ �߶� ť�� �߰�
			str = s.substr(idx, c);
			q.push(str);
			idx += c;
		}

		string prev = q.front();
		q.pop();
		int num = 1;
		while (1) {
			//������ ���� ���ڿ��̶�� +1
			if (q.front() == prev)	
				num++;
			//������ �ٸ��ٸ�, ���ڿ� �����ϰ� 1�� �ʱ�ȭ
			else {
				result += (make_string(prev, num)); 
				prev = q.front();
				num = 1;
			}
			q.pop();
			//ť�� ����ٸ�, �信 �߰��ϰ� ����
			if (q.empty()) {
				result += (make_string(prev, num));
				break;
			}
		}
		//�ּڰ� ����
		answer = min((int)result.length(), answer);
		result.clear();
	}
	return answer;
}