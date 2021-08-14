#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#define RAN (ty<0||tx<0||ty>=N||tx>=M)
using namespace std;
typedef pair<pair<int,int>,pair<int,int>> p;
typedef unsigned int ui;
const int MAX=101;
int dy[4]={-1,1,0,0}, dx[4]={0,0,1,-1};
ui cost[MAX][MAX][3];
int map[MAX][MAX];
bool visit[MAX][MAX][3];

int main(void){
  int N,M,n,m,y,x,nn,mm; scanf("%d %d",&N,&M);
  int sy,sx,ey,ex; scanf("%d %d %d %d",&sy,&sx,&ey,&ex);
  sy--;sx--;ey--;ex--;
  memset(cost,-1,sizeof(cost));
  for(int i=0; i<N; i++)for(int j=0; j<M; j++)scanf("%d",&map[i][j]);
  ui ans=-1;
  priority_queue<p,vector<p>,greater<p>> pq;
  pq.push({{0,1},{sy,sx}});
  cost[sy][sx][1]=0;

  while(!pq.empty()){
    do{
      y=pq.top().second.first, x=pq.top().second.second;
      n=pq.top().first.second; nn=n%3;
      pq.pop();
    }while(!pq.empty()&&visit[y][x][nn]);
    if(visit[y][x][nn])break;
    visit[y][x][nn]=true;
    if(y==ey&&x==ex){
      ans=cost[y][x][nn];
      break;
    }
    m=n+1; mm=m%3;

    for(int i=0; i<4; i++){
      int ty=y+dy[i], tx=x+dx[i];
      if(nn==1&&i>1)continue;
      if(nn==2&&i<2)continue;

      if(RAN||map[ty][tx]==-1)continue;
      if(cost[ty][tx][mm]>cost[y][x][nn]+map[ty][tx]){
        cost[ty][tx][mm]=cost[y][x][nn]+map[ty][tx];
        pq.push({{cost[ty][tx][mm],m},{ty,tx}});
      }
    }
  }
  printf("%d",ans==(ui)-1?-1:ans);
}

