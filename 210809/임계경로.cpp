#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int MAX=10001;
typedef pair<int,int> p;
int dist[MAX];
int indegree[MAX];
vector<p> front[MAX], back[MAX];
bool visit[MAX];

int main(void){
  int N,M; scanf("%d %d",&N,&M);
  for(int i=0; i<M; i++){
    int s, e, c; scanf("%d %d %d",&s,&e,&c);
    s--; e--;
    indegree[e]++;
    front[s].push_back({e,c});
    back[e].push_back({s,c});
  }
  int S,E; scanf("%d %d",&S,&E); S--; E--;
  queue<int> q;
  q.push(S);
  while(!q.empty()){
    int curr= q.front(); q.pop();

    for(auto n : front[curr]){
      int next=n.first, cost= n.second;
      indegree[next]--;
      if(indegree[next]==0)q.push(next);
      dist[next]=max(dist[next],dist[curr]+cost);
    }
  }
  int cnt=0;
  q.push(E);
  while(!q.empty()){
    int curr=q.front(); q.pop();

    for(auto n : back[curr]){
      int next=n.first, cost= n.second;
      if(dist[next]+cost==dist[curr]){
        if(!visit[next]){
          visit[next]=true;
          q.push({next});
        }
        cnt++;
      }
    }
  }
  printf("%d\n%d",dist[E],cnt);
}
