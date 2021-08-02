#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
const int MAX=501;
int arr[MAX], ans[MAX], indegree[MAX], cnt;
bool adj[MAX][MAX];

void init(){
  cnt=0;
  memset(indegree,0,sizeof(indegree));
  memset(adj,0,sizeof(adj));
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    int N; scanf("%d",&N);
    init();
    for(int i=1; i<=N; i++)scanf("%d",arr+i);
    for(int i=1; i<=N-1; i++)for(int j=i+1; j<=N; j++){
      indegree[arr[j]]++;
      adj[arr[i]][arr[j]]=true;
    }
    int M; scanf("%d",&M);
    for(int i=0; i<M; i++){
      int s, e; scanf("%d %d",&s,&e);
      if(adj[s][e]){
        adj[s][e]=false;
        adj[e][s]=true;
        indegree[s]++;
        indegree[e]--;
      }
      else{
        adj[e][s]=false;
        adj[s][e]=true;
        indegree[e]++;
        indegree[s]--;
      }
    }

    queue<int> q;
    bool isIm=false, isMul=false;
    for(int i=1; i<=N; i++)if(indegree[i]==0)q.push(i);
    
    while(!q.empty()){
      int curr=q.front(); q.pop();
      ans[cnt++]=curr;
      if(q.size()>0){
        isMul=true;break;
      }
      for(int i=1; i<=N; i++)if(adj[curr][i]){
        indegree[i]--;
        if(indegree[i]==0)q.push(i);
      }
    }
    if(cnt<N)isIm=true;

    if(isMul)printf("?\n");
    else if(isIm)printf("IMPOSSIBLE\n");
    else{
      for(int i=0; i<N; i++)printf("%d ",ans[i]);
      printf("\n");
    }
  }
}
