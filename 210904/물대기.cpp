#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
typedef pair<int,pair<int,int>> p;
const int MAX=301;
int N, cost[MAX][MAX], par[MAX];
int getpar(int a){
  return par[a]<0?a:par[a]=getpar(par[a]);
}

bool setUnion(int a, int b){
  a=getpar(a);
  b=getpar(b);
  if(a==b)return false;
  if(par[a]>par[b])swap(a,b);
  par[a]+=par[b];
  par[b]=a;
  return true;
}
int getAns(){
  int res=0;
  memset(par,-1,sizeof(par));
  priority_queue<p,vector<p>,greater<p>> pq;
  for(int i=1; i<=N; i++)for(int j=1; j<=N; j++){
    if(i!=j)pq.push({cost[i][j],{i,j}});
    else pq.push({cost[i][j],{0,i}});
  }
  while(par[getpar(0)]>=-N){
    int curr=pq.top().second.first, next=pq.top().second.second,c=pq.top().first; pq.pop();
    if(setUnion(curr,next))res+=c;
  }
  return res;
}
int main(void){
  scanf("%d",&N);
  for(int i=1; i<=N; i++)scanf("%d",cost[i]+i);
  for(int i=1; i<=N; i++)for(int j=1; j<=N; j++){
    if(i==j)scanf("%d",cost[0]+i);
    else scanf("%d",cost[i]+j);
  }
  printf("%d",getAns());
}
