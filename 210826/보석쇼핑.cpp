// https://programmers.co.kr/learn/courses/30/lessons/67258
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> gem_map;
int gem_num;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    vector<int> tmp(2, 0);
    int start = 0, end = 0; 
    bool found = false;

    answer.push_back(1);
    answer.push_back(100001);

    for(int i = 0; i < gems.size(); i++)
        gem_map[gems[i]] = 1;
    gem_num = gem_map.size();

    unordered_map<string, int>().swap(gem_map);

    while(true) {
        found = false;
        if(gem_map.size() < gem_num) {
            gem_map[gems[end]] += 1;
            tmp[1] = end + 1;
            end++;
        }
        
        if(gem_map.size() == gem_num) {
            found = true;
            tmp[0] = start + 1;

            if(gem_map[gems[start]] == 1) {
                gem_map[gems[start]] = 0;
                gem_map.erase(gems[start]);
            }
            else 
                gem_map[gems[start]] -= 1;
            start++;            
        }

        if(found) {
            if(tmp[1] - tmp[0] < answer[1] - answer[0]) {
                answer[0] = tmp[0];
                answer[1] = tmp[1];
            }
        }
    }

    return answer;
}