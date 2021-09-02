// https://programmers.co.kr/learn/courses/30/lessons/72412
#include <string> 
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//  열 0 : 언어, 1 : 직군, 2 : 경력, 3 : 소울푸드, 4: 점수
vector<vector<string> > table; 
vector<vector<string> > qtable;
int qnum = 0;

bool comp(vector<string>& t1, vector<string>& t2) {
    int num1 = 0, num2 = 0;
    for(int i = 0; i < 4; i++) {
        if(qtable[qnum][i] != "-") {
            if(t1[i] == qtable[qnum][i])
                num1 += 1;
            if(t2[i] == qtable[qnum][i])
                num2 += 1;
        }
        else {
            num1 += 1;
            num2 += 1;
        }
    }

    if(stoi(t1[4]) >= stoi(qtable[qnum][4]))
        num1 += 1;
     if(stoi(t2[4]) >= stoi(qtable[qnum][4]))
        num2 += 1;

    t1[5] = to_string(num1);
    t2[5] = to_string(num2);

    // cout << "t1[5] : " << t1[5] << '\n';
    // cout << "t2[5] : " << t2[5] << '\n';

    return num1 >= num2;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    int n = info.size();
    int m = query.size();
    int tmp;

    table.assign(n, vector<string>());
    qtable.assign(m, vector<string>());
    for(int i = 0; i < n; i++) 
        table[i].assign(6, "");
    for(int i = 0; i < m; i++) 
        qtable[i].assign(5, "");

    for(int i = 0; i < n; i++) {
        string str = "";
        int idx = 0;

        for(int j = 0; j < info[i].length(); j++) {
            if(info[i][j] == ' ') {
                table[i][idx++] = str;
                str = "";
            }
            else if(j == info[i].length() - 1) {
                str += info[i][j];
                table[i][idx] = str;
            }
            else 
                str += info[i][j];
        }
    }

    for(qnum = 0; qnum < m; qnum++) {
        int start = 0;

        for(int j = 0; j < 5; j++) {
            for(int k = start; k < query[qnum].length(); k++) {
                if(query[qnum][k] == ' ') {
                    if(j < 3) {
                        start = k + 5;
                        break;
                    }
                    else {
                        start = k + 1;
                        break;
                    }
                }
                qtable[qnum][j] += query[qnum][k];
            }
        }
        
        sort(table.begin(), table.end(), comp);


        // for(int j = 0; j < 5; j++)
        //     cout << qtable[qnum][j] << "\n";
        // cout << "\n";

        // for(int j = 0; j < n; j++) {
        //     for(int k = 0; k < 6; k++)
        //         cout << table[j][k] << " ";
        //     cout << '\n';
        // }   
        // cout << '\n';

        tmp = 0;
        for(int j = 0; j < n; j++) {
            if(table[j][5] != "5") break;
            tmp += 1;
        }
        answer.push_back(tmp);
    }

    return answer;
}