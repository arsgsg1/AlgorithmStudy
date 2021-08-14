#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, X, K;
vector<int> times;
// priority_queue<int> pq;

void func() {
    int start = 1;  //  최소 1개 라인은 필요
    int end = N;    //  최대 N개 있으면 충분
    int mid = (start + end) / 2;

    while(start <= end) {
        priority_queue<int> pq;
        bool possible = true;   //  라인 개수가 mid개일 때 배치 가능하면 true, 더 필요하면 false
        for(int i = 0; i < mid; i++)
            pq.push(X);

        for(int i = 1; i <= N; i++) {   //  i번째 선물을 라인에 배정하려 함
            int remain_time = pq.top();  //   가장 사용시간이 적은 라인의 남은 시간을 꺼내옴
            int new_time = remain_time - times[i];   //  이 라인에 i번째 선물을 배정했을 때 남은 시간
            pq.pop();

            if(new_time < 0) {  //  배정하기엔 남은 시간이 부족한 경우 라인을 증가시켜야 함
                start = mid + 1;
                mid = (start + end) / 2;    //  라인 개수 증가
                possible = false;
                break;
            }
            else pq.push(new_time); //  i번째 선물을 배치하고 남은 시간을 큐에 삽입
        }

        while(!pq.empty())
            pq.pop();

        if(possible) {  //  현재 라인 개수에 N개 선물 일단 배치 가능할 경우
            K = min(K, mid);    //   K값 갱신
            end = mid - 1;
            mid = (start + end) / 2;    //  더 적은 라인 개수로 가능한지 시도
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> X;
    times.assign(N + 1, 0);

    for(int i = 1; i <= N; i++)
        cin >> times[i];

    K = N + 1;

    // cout << "before func\n";
    func();
    // cout << "after func\n";

    cout << K << '\n';
    return 0;
}