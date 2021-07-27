#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> p;
p arr[200001];
int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int N;cin>>N;
  priority_queue<int,vector<int>,greater<int>> pq;
  for(int i=0; i<N; i++){
    int s,e; cin>>s>>e;
    arr[i]={s,e};
  }
  sort(arr,arr+N);
  pq.push(arr[0].second);
  for(int i=1; i<N; i++){
    if(arr[i].first>=pq.top()){
      pq.pop();
      pq.push(arr[i].first);
    }
    else pq.push(arr[i].first);
  }
  cout<<pq.size();
}
