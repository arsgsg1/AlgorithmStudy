#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX=401, INF=1<<10;
int dist[MAX][MAX];
int main(void){
  int s,e,N,M;
  scanf("%d %d",&N,&M);
  for(int i=0; i<N; i++)for(int j=0; j<N; j++)dist[i][j]=i==j?0:INF;
  for(int i=0; i<M; i++){
    scanf("%d %d",&s,&e);
    s--; e--;
    dist[s][e]=1;
  }
  for(int k=0; k<N; k++)
    for(int i=0; i<N; i++)
      for(int j=0; j<N; j++)dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
  int k; scanf("%d",&k);
  while(k--){
    scanf("%d %d",&s,&e);
    s--;e--;
    bool isP=dist[s][e]==INF?false:true;
    bool isBP=dist[e][s]==INF?false:true;
    if(isP^isBP)printf("%d\n",isP?-1:1);
    else printf("0\n");
  }
}
