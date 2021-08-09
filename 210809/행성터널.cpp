#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
typedef pair<int,int> p;
typedef pair<int,pair<int,int>> pp;
const int MAX=100001;
int par[MAX];

int getpar(int a){
  return par[a]<0?a:par[a]=getpar(par[a]);
}

bool setUnion(int a, int b){
  a=getpar(a);
  b=getpar(b);
  if(a==b)return false;
  par[a]=b;
  return true;
}
int main(void){
  int N; scanf("%d",&N);
  priority_queue<p,vector<p>,greater<p>> pos[3];
  priority_queue<pp,vector<pp>,greater<pp>> pq;
  memset(par,-1,sizeof(par));
  for(int i=0; i<N; i++){
    int a,b,c; scanf("%d %d %d",&a,&b,&c); a--;b--;c--;
    pos[0].push({a,i});
    pos[1].push({b,i});
    pos[2].push({c,i});
  }
  for(int i=0; i<3; i++)
    while(!pos[i].empty()){
      int s, e, x1, x2;
      s=pos[i].top().second; x1=pos[i].top().first;
      pos[i].pop();
      if(pos[i].empty())break;
      e=pos[i].top().second; x2=pos[i].top().first;
      pq.push({abs(x1-x2),{s,e}});
    }
  long long ans=0;
  while(!pq.empty()){
    int s = pq.top().second.first, e=pq.top().second.second;
    int c=pq.top().first; pq.pop();
    if(setUnion(s,e))ans+=c;
  }
  printf("%lld",ans);
}
