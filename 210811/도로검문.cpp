#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int MAX=1001;
typedef pair<int,int> p;
typedef unsigned int ui;
int visit[MAX],vcnt=1;
vector<p> adj[MAX];
ui dist[MAX];
int Prev[MAX];

int main(void){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0; i<M; i++){
    int s,e,c; scanf("%d %d %d",&s,&e,&c); s--;e--;
    adj[s].push_back({e,c});
    adj[e].push_back({s,c});
  }
  memset(dist,-1,sizeof(dist));
  priority_queue<p,vector<p>>pq;
  dist[0]=0;
  pq.push({0,0});
  while(!pq.empty()){
    int curr;
    do{
      curr=pq.top().second; pq.pop();
    }while(!pq.empty()&&visit[curr]==vcnt);
    if(visit[curr]==vcnt)break;
    visit[curr]=vcnt;
    for(auto m : adj[curr]){
      int next=m.first, cost=m.second;
      if(dist[next]==(ui)-1||dist[next]>dist[curr]+cost){
        dist[next]=dist[curr]+cost;
        Prev[next]=curr;
        pq.push({-dist[next],next});
      }
    }
  }
  int n = N-1;
  ui ans=0, dst=dist[N-1];
  while(n){
    int mm=Prev[n];
    memset(dist,-1,sizeof(dist));
    vcnt++;
    dist[N-1]=0;
    pq.push({0,N-1});
    while(!pq.empty()){
      int curr;
      do{
        curr=pq.top().second; pq.pop();
      }while(!pq.empty()&&visit[curr]==vcnt);
      if(visit[curr]==vcnt)break;
      visit[curr]=vcnt;
      for(auto m : adj[curr]){
        int next=m.first, cost=m.second;
        if(curr==n&&next==mm)continue;
        if(dist[next]==(ui)-1||dist[next]>dist[curr]+cost){
          dist[next]=dist[curr]+cost;
          pq.push({-dist[next],next});
        }
      }
    }
    n=mm;
    ans=max(ans,dist[0]);
    if(ans==(ui)-1)break;
  }
  printf("%d",ans==(ui)-1?-1:ans-dst);
}
