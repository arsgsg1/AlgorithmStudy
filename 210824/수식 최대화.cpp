#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(string expression) {
    long long answer = 0;
    vector<char> prior_op = {'*', '+', '-'};
    vector<long long> temp_num;
    vector<char> temp_op;
    string s;
    for (int i = 0; i < expression.size(); i++) {
        if (isdigit(expression[i])) {
            s += expression[i];
        } else {
            temp_num.push_back(stoi(s));
            temp_op.push_back(expression[i]);
            s = "";
        }
    }
    temp_num.push_back(stoi(s));

    do {
        vector<long long> num = temp_num;
        vector<char> op = temp_op;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < op.size(); j++) {
                if (op[j] == prior_op[i]) {
                    if (op[j] == '*') {
                        num[j] *= num[j + 1];
                    } else if (op[j] == '+') {
                        num[j] += num[j + 1];
                    } else if (op[j] == '-') {
                        num[j] -= num[j + 1];
                    }
                    num.erase(num.begin() + j + 1);
                    op.erase(op.begin() + j);
                    j--;
                }
            }
        }
        answer = max(answer, abs(num[0]));
    } while (next_permutation(prior_op.begin(), prior_op.end()));

    return answer;
}