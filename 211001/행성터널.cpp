#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int MAX=100001;
typedef pair<int, int> p;
typedef pair<int, pair<int,int>> pp;
priority_queue<p,vector<p>,greater<p>> pq[3];
priority_queue<pp,vector<pp>,greater<pp>> ppq;

int par[MAX];

int getpar(int a){return par[a]<0?a:par[a]=getpar(par[a]);}
bool setUnion(int a, int b){
  a=getpar(a);
  b=getpar(b);
  if(a==b)return false;
  if(par[a]>par[b])swap(a,b);
  par[a]+=par[b];
  par[b]=a;
  return true;
}

int main(void){
  memset(par,-1,sizeof(par));
  int N, prev, n, curr, cn, s, e; scanf("%d ",&N);
  for(int i=0; i<N; i++){
    for(int j=0; j<3; j++){
      scanf("%d ",&n);
      pq[j].push({n,i});
    }
  }

  for(int i=0; i<3; i++){
    n=pq[i].top().first;
    prev=pq[i].top().second;
    pq[i].pop();
    while(!pq[i].empty()){
      curr = pq[i].top().first;
      cn = pq[i].top().second;
      pq[i].pop();
      ppq.push({abs(curr-n),{prev,cn}});
      prev=cn;
      n=curr;
    }
  }
  long long ans=0;
  while(!ppq.empty()){
    n=ppq.top().first;
    s=ppq.top().second.first;
    e=ppq.top().second.second;
    ppq.pop();
    if(setUnion(s,e))ans+=n;
  }
  printf("%lld",ans);
}
