#include <cstdio>
#include <queue>
#include <algorithm>
#define RAN (ty<0||tx<0||ty>=N||tx>=M)
using namespace std;
typedef pair<int,int> p;
int map[51][51], region[51][51], cntRoom[2501];
int N, M, dy[4]={0,-1,0,1}, dx[4]={-1,0,1,0}, cnt;
int ans1,ans2,ans3;
bool visit[51][51];

void bfs(int y, int x){
  queue<p> q;
  cnt++;
  q.push({y,x});
  visit[y][x]=true;
  int num=0;
  while(!q.empty()){
    int cy=q.front().first, cx=q.front().second;
    q.pop();
    region[cy][cx]=cnt;
    num++;

    for(int i=0; i<4; i++)if(!(map[cy][cx]&1<<i)){
      int ty=cy+dy[i], tx=cx+dx[i];
      if(visit[ty][tx])continue;
      visit[ty][tx]=true;
      q.push({ty,tx});
    }
  }
  ans2=max(ans2,num);
  cntRoom[cnt]=num;
}

int main(void){
  scanf("%d %d",&M,&N);
  for(int i=0; i<N; i++)for(int j=0; j<M; j++)scanf("%d ",&map[i][j]);
  for(int i=0; i<N; i++)for(int j=0; j<M; j++)if(!visit[i][j]){ans1++;bfs(i,j);}
  
  for(int i=0; i<N; i++)for(int j=0; j<M; j++)
    for(int k=0; k<4; k++){
      int ty=i+dy[k], tx=j+dx[k];
      if(RAN||region[i][j]==region[ty][tx])continue;
      ans3=max(ans3,cntRoom[region[i][j]]+cntRoom[region[ty][tx]]);
    }
  printf("%d\n%d\n%d",ans1,ans2,ans3);
}
