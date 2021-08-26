// https://programmers.co.kr/learn/courses/30/lessons/67258
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<string, int> g_map;       //  보석 이름, 해당 보석 개수
int g_num;                              //  보석 종류 수

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    vector<int> tmp;
    int start = 0, end = 0, cnt = 0;

    answer.push_back(1);
    answer.push_back(100001);

    for(int i = 0; i < gems.size(); i++)
        g_map[gems[i]]++;
    g_num = g_map.size();
    
    while(start < gems.size() && end < gems.size()) {
        vector<int>().swap(tmp);
        
        if(cnt < g_num) {
            // cout << "If\n"; 
            if(gem_type.find(gems[end]) == gem_type.end()) {//   구매 목록에 새 보석이 추가되는 경우
                // cout << "보석 " << gems[end] << " 추가!\n";
                cnt++;  //  보석 종류 수 1 증가
            }
            gem_type[gems[end]] += 1;   //  해당 보숙 개수 1 증가
            end++;
        }
        if(cnt == g_num) {
            // cout << "Else\n"; 

            tmp.push_back(start + 1);
            tmp.push_back(end);

            // cout << "tmp : [" << tmp[0] << ", " << tmp[1] << "]\n";             

            if(tmp[1] - tmp[0] + 1 < answer[1] - answer[0] + 1)
                tmp.swap(answer);

            if(gem_type[gems[start]] == 1) {    //  start에 있는 보석이 구매 목록 중 해당 종류로 유일할 경우
                gem_type[gems[start]] = 0;
                gem_type.erase(gems[start]); //  해당 보석 제거
                cnt--;
            }

            else //  start에 있는 보석이 start말고도 또 존재할 경우
                gem_type[gems[start]] -= 1;  //  해당 보석 개수 1 감소
            start++;
        }
    }
    return answer;
}