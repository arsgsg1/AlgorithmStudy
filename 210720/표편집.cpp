//  https://programmers.co.kr/learn/courses/30/lessons/81303
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <list>

using namespace std;

list<int> before;
list<int> after;
list<int>::iterator b_iter; //  원본
list<int>::iterator a_iter; //  편집 후
list<int>::iterator d_iter; //  

stack<pair<int, list<int>::iterator> > del_stack;

void move(int mov, int d) {
    if(d == -1) {
        for(int i = 0; i < mov; i++)
            a_iter--;
    }
    else if(d == 1) {
        for(int i = 0; i < mov; i++)
            a_iter++;
    }
}

void compare_lists(string& result) {
    b_iter = before.begin();
    a_iter = after.begin();
    
    for(; b_iter != before.end(); b_iter++) {
        if(*b_iter == *a_iter) {
            result.append("O");
            a_iter++;
        }
        else 
            result.append("X");
    }
}

void restore() {
    int data = del_stack.top().first;
    list<int>::iterator pos = del_stack.top().second;
    del_stack.pop();

    if(pos == after.end())
        after.push_back(data);
    else
        after.insert(pos, data);
}

string solution(int n, int k, vector<string> cmd) {
    string answer = "";

    for(int i = 0; i < n; i++) {
        before.push_back(i);
        after.push_back(i);
    }

    a_iter = after.begin();
    
    for(int i = 0; i < k; i++) 
        a_iter++;

    for(int i = 0; i < cmd.size(); i++) {
        int mov;

        if(cmd[i].at(0) == 'U') {
            mov = stoi(cmd[i].substr(2));
            move(mov, -1);
        }
        else if(cmd[i][0] == 'D') {
            mov = stoi(cmd[i].substr(2));
            move(mov, +1);
        }
        else if(cmd[i][0] == 'C') {
           int del = *a_iter;
           a_iter = after.erase(a_iter);
           del_stack.push(make_pair(del, a_iter));
           
           if(a_iter == after.end())
              a_iter--;
        }
        else if(cmd[i][0] == 'Z') {
           restore();
        }
    }

    compare_lists(answer);
    return answer;
}