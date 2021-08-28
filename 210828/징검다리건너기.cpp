#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int,int> p;

int solution(vector<int> stones, int k) {
    int answer = 0;
    priority_queue<p,vector<p>> pq;
    for(int i=0; i<k; i++)pq.push({stones[i],i});
    answer=pq.top().first;
    for(int i=k; i<stones.size(); i++){
        pq.push({stones[i],i});
        while(pq.top().second<=i-k)pq.pop();
        answer=min(answer,pq.top().first);
    }
    
    return answer;
}
