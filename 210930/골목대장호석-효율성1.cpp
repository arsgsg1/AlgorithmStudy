#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int,int> p;
const int MAX= 100001;
vector<p> adj[MAX];
unsigned int N,M,A,B,C,s,e,c;
int visit[MAX], vn;
unsigned int dist[MAX];

bool check(int limit){
  vn++;
  priority_queue<p,vector<p>,greater<p>> pq;
  memset(dist,-1,sizeof(dist));
  
  dist[A]=0;
  pq.push({dist[A],A});

  while(!pq.empty()){
    int curr;
    do{
      curr=pq.top().second; pq.pop();
    }while(!pq.empty()&&visit[curr]==vn);
    if(visit[curr]==vn)break;
    visit[curr]=vn;

    for(auto n : adj[curr]){
      int next=n.first, cost=n.second;
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
  scanf("%d %d %d %d %d",&N,&M,&A,&B,&C);
  A--;B--;
  for(int i=0; i<M; i++){
    scanf("%d %d %d",&s,&e,&c);
    s--; e--;
    adj[s].push_back({e,c});
    adj[e].push_back({s,c});
  }

  int l=0, h=21;
  while(l+1<h){
    int mid=(l+h)/2;
    if(check(mid)) h=mid;
    else l=mid;
  }
  if(h==21)h=-1;
  printf("%d",h);
}


