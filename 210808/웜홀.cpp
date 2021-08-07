#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> p;
typedef long long ll;
const int MAX=501;
bool inQue[MAX];
vector<p> adj[MAX];
int N,M,W;
ll dist[MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d %d %d",&N,&M,&W);
    for(int i=0; i<N; i++)adj[i].clear();
    int s,e,c;
    for(int i=0; i<M; i++){
      scanf("%d %d %d",&s,&e,&c);
      adj[s-1].push_back({e-1,c});
      adj[e-1].push_back({s-1,c});
    }
    for(int i=0; i<W; i++){
      scanf("%d %d %d",&s,&e,&c);
      adj[s-1].push_back({e-1,-c});
    }
    fill(dist,dist+N,0);
    fill(inQue,inQue+N,0);
    int num;
    bool isCycle=false;
    for(int i=0; i<N; i++)if(dist[i]==0){
      if(isCycle)break;
      queue<int> q;
      q.push(i);
      inQue[i]=true;
      dist[i]=0;
      num=0;
          
      while(!q.empty()){
        int curr=q.front(); q.pop();
        inQue[curr]=false;
        if(isCycle)break;
        for(auto n : adj[curr]){
          int next=n.first, cost=n.second;
          if(dist[next]>dist[curr]+cost){
            dist[next]=dist[curr]+cost;
            if(!inQue[next]){
              num++;
              if(num>N)isCycle=true;
              q.push(next);
              inQue[next]=true;
            }
          }
        }
      }
    }
    printf("%s\n",(isCycle?"YES":"NO"));
  }
}
