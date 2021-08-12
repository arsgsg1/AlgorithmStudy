#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int,int> p;
const int MAX=101, INF=1<<29;
vector<p> adj[MAX], back[MAX];
int dist[MAX], _prev[MAX],cnt[MAX];
bool inq[MAX], visit[MAX];

void trace(int n){
  if(n>0)trace(_prev[n]);
  printf("%d ",n+1);
}

int main(void){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0; i<M; i++){
    int S,E,C; scanf("%d %d %d",&S,&E,&C);
    C=-C;S--;E--;
    adj[S].emplace_back(E,C);
    back[E].emplace_back(S,C);
  }
  queue<int> q;
  q.push(N-1);
  visit[N-1]=true;
  while(!q.empty()){
    int curr=q.front(); q.pop();
    for(auto m : back[curr]){
      if(!visit[m.first]){
        visit[m.first]=true; q.push(m.first);
      }
    }
  }
  fill(dist,dist+N,INF);
  dist[0]=0;
  q.push(0);
  bool isCycle=false;
  while(!q.empty()){
    int curr=q.front(); q.pop();
    inq[curr]=false;
    for(auto n : adj[curr]){
      int next=n.first, cost=n.second;
      if(dist[next]>dist[curr]+cost){
        dist[next]=dist[curr]+cost;
        _prev[next]=curr;
        if(!inq[next]){
          cnt[next]++;
          if(cnt[next]>N){
            if(visit[curr])isCycle=true;
            continue;
          }
          inq[next]=true;
          q.push(next);
        }
      }
    }
  }
  if(isCycle)printf("-1");
  else trace(N-1);
}
