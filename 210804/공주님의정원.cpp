#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int,int> p;
int main(void){
  int N; scanf("%d",&N);
  priority_queue<p,vector<p>,greater<p>> pq;
  for(int i=0; i<N; i++){
    int sm,sd,em,ed; scanf("%d %d %d %d",&sm,&sd,&em,&ed);
    pq.push({sm*100+sd,em*100+ed});
  }
  int ans=0, start=301;
  while(true){
    int temp=-1;
    while(!pq.empty()&&pq.top().first<=start){
      temp=max(temp,pq.top().second);
      pq.pop();
    }
    if(temp<0)break;
    else if(start<=1130){
      ans++;
      start=temp;
    }
    else break;
  }
  if(start>1130)
    printf("%d",ans);
  else printf("0");
}
