//  https://programmers.co.kr/learn/courses/30/lessons/43164
#include <string>
#include <deque>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;

deque<pair<int, string> > graph[10001];
unordered_map<string, int> airport; //  공항 이름 -> 공항 번호
int num = 0;    //  공항 번호(0부터 시작)

bool dfs(string a_name, vector<string>& answer) {
    int a_num = airport[a_name];
    bool ret = false;
    answer.push_back(a_name);

    while(!graph[a_num].empty()) {
        ret = true;
        string next_name = graph[a_num][0].second;
        graph[a_num].pop_front();
        if(!dfs(next_name, answer)) return false;
    }
    
    return ret;
}

vector<string> solution(vector<vector<string> > tickets) {
    vector<string> answer;
    
    sort(tickets.begin(), tickets.end());
    
    for(int i = 0; i < tickets.size(); i++) {
        string from = tickets[i][0];
        string to = tickets[i][1];

        if(airport.find(from) == airport.end())
            airport[from] = num++;
        if(airport.find(to) == airport.end())
            airport[to] = num++;

        graph[airport[from]].push_back(make_pair(airport[to], to));
    }

    dfs("ICN", answer);

    return answer;
}