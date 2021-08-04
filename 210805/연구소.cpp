#include <cstdio>
#include <queue>
#define RAN (ty<0||tx<0||ty>=N||tx>=M)
using namespace std;
const int MAX=8;
typedef pair<int,int> p;
int tmap[MAX][MAX],map[MAX][MAX], zeroPos[MAX*MAX],cnt, ans;
int N,M,dy[4]={1,-1,0,0}, dx[4]={0,0,1,-1};
queue<p> q;

int bfs(void){
  for(int i=0; i<N; i++)for(int j=0; j<M; j++){
    tmap[i][j]=map[i][j];
    if(tmap[i][j]==2) q.push({i,j});
  }
  while(!q.empty()){
    int y=q.front().first, x=q.front().second;
    q.pop();
    for(int i=0; i<4; i++){
      int ty=y+dy[i], tx=x+dx[i];
      if(RAN||tmap[ty][tx]!=0)continue;
      tmap[ty][tx]=2;
      q.push({ty,tx});
    }
  }
  int temp=0;
  for(int i=0; i<N; i++)for(int j=0; j<M; j++)if(tmap[i][j]==0)temp++;
  return temp;
}
void recur(int idx=0, int n=0){
  if(n==3){
    int temp=0;
    temp=bfs();
    ans=max(ans,temp);
    return;
  }
  for(int i=idx; i<cnt; i++){
    int y=zeroPos[i]/MAX, x=zeroPos[i]%MAX;
    map[y][x]=1;
    recur(i+1,n+1);
    map[y][x]=0;
  }
}


int main(void){
  scanf("%d %d",&N,&M);
  for(int i=0; i<N; i++)for(int j=0; j<M; j++){
    scanf("%d",&map[i][j]);
    if(map[i][j]==0)zeroPos[cnt++]=i*MAX+j;
  }
  recur();
  printf("%d",ans);
}
