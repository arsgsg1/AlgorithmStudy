// https://programmers.co.kr/learn/courses/30/lessons/60062
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = dist.size() + 1;
    int len = weak.size();

    for(int i = 0; i < len; i++)    // 원형으로 만들기 위해 더해줌
        weak.push_back(n + weak[i]);

    for(int i = 0; i < len; i++) {  //  친구가 탐색을 시작할 위치(weak[i])
        do {
            int cnt = 1;    //  탐색에 필요한 친구 수
            int pos = weak[i] + dist[cnt - 1];  //  weak[i]에서 탐색 시작했을때 최대 탐색할 수 있는 위치
            for(int j = i; j < i + len; j++) {
                if(pos < weak[j]) { //  다음 취약 지점까지 탐색할 수 없을 경우
                    cnt++;  //  탐색에 필요한 친구 1명 증가
                    if(cnt > dist.size())   //  친구가 부족할 경우
                        break;
                    pos = weak[j] + dist[cnt - 1];  //  다음 친구는 weak[j]부터 시작해서 최대 탐색할 수 있는 위치 정함
                }
            }
            answer = min(answer, cnt);
        } while(next_permutation(dist.begin(), dist.end()));
    }

    if(answer > dist.size())
        answer = -1;
    
    return answer;
}