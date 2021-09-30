#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
typedef unsigned long long ul;
typedef pair<ul,ul> p;
const int MAX= 100001, INF=1000000001;
vector<p> adj[MAX];
ul N,M,A,B,C,s,e,c;
int visit[MAX], vn;
ul dist[MAX];

bool check(ul limit){
  vn++;
  priority_queue<p,vector<p>,greater<p>> pq;
  memset(dist,-1,sizeof(dist));
  dist[A]=0;
  pq.push({dist[A],A});

  while(!pq.empty()){
    ul curr;
    do{
      curr=pq.top().second; pq.pop();
    }while(!pq.empty()&&visit[curr]==vn);
    if(visit[curr]==vn)break;
    visit[curr]=vn;

    for(auto n : adj[curr]){
      ul next=n.first, cost=n.second;
      if(cost>limit)continue;
      if(dist[next]>dist[curr]+cost){
        dist[next]=dist[curr]+cost;
        pq.push({dist[next],next});
      }
    }
  }
  if(dist[B]>C)return false;
  return true;
}

int main(void){
  scanf("%lld %lld %lld %lld %lld",&N,&M,&A,&B,&C);
  A--;B--;
  for(ul i=0; i<M; i++){
    scanf("%lld %lld %lld",&s,&e,&c);
    s--; e--;
    adj[s].push_back({e,c});
    adj[e].push_back({s,c});
  }
  ul temp = min(C+1,1LLU*INF);
  ul l=0, h = temp;
  while(l+1<h){
    ul mid=(l+h)/2;
    if(check(mid)) h=mid;
    else l=mid;
  }
  if(h==temp)printf("-1");
  else printf("%llu",h);
}

