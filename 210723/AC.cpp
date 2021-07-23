#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;
void numParser(deque<int>& v, string& buf)
{
	int size = buf.size();
	string num;
	for (int i = 1; i < size; i++) {
		if ('0' <= buf[i] && buf[i] <= '9') {
			num += buf[i];
		}
		else {
			v.push_back(stoi(num));
			num.clear();
		}
	}
}
bool op(string& func, deque<int>& v)
{
	bool isReverse = false;
	for (const auto& c : func) {
		switch (c) {
		case 'R':
			isReverse = !isReverse;
			//reverse(v.begin(), v.end());
			break;
		case 'D':
			if (v.size()) {
				if (isReverse) {
					v.pop_back();
				}
				else {
					v.pop_front();
				}
			}
			else
				return false;
			break;
		}
	}
	if (isReverse)
		reverse(v.begin(), v.end());
	return true;
}
int main()
{
	int tc, number_size;
	cin >> tc;
	string func, buf, str_num;
	for (int t = 0; t < tc; t++) {
		cin >> func;
		cin >> number_size;
		cin >> buf;
		deque<int> numbers;
		if (number_size)
			numParser(numbers, buf);
		if (op(func, numbers)) {
			int size = numbers.size();
			printf("[");
			for (int i = 0; i < size - 1; i++) {
				printf("%d,", numbers[i]);
			}
			if (size)
				printf("%d", numbers[size - 1]);
			printf("]\n");
		}
		else {
			printf("error\n");
		}
	}
	return 0;
}