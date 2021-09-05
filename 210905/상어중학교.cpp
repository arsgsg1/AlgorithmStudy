#include <cstdio>
#include <queue>
#define RAN (ty<0||tx<0||ty>=N||tx>=N)
using namespace std;
typedef pair<int,int> p;
int map[21][21], temp[21][21], N,M,ans,rainbow;
int visit[21][21], rbow[21][21], rn, vn, dx[4]={0,0,1,-1}, dy[4]={1,-1,0,0};
void gravity(){
  for(int i=0; i<N; i++){
    int t=N-1, p=N-1;
    while(t>=0&&p>=0){
      while(t>=0&&map[t][i]!=-2)t--;
      p=t;
      while(p>=0&&map[p][i]==-2)p--;
      while(p>=0&&map[p][i]>=0&&map[t][i]==-2){
        map[t--][i]=map[p][i];
        map[p--][i]=-2;
      }
      if(map[p][i]==-1){t=p;}
    }
  }
}

void rotat(){

  for(int i=0; i<N; i++)for(int j=0; j<N; j++)temp[i][j]=map[i][j];
  for(int i=0; i<N; i++)for(int j=0 ;j<N; j++)map[i][j]=temp[j][N-i-1];
}
int bfs(int y, int x){
  int res=0, color=map[y][x]; rainbow=0; rn++;
  queue<p> q;
  q.push({y,x}); visit[y][x]=vn;
  while(!q.empty()){
    int cy=q.front().first, cx=q.front().second;
    q.pop(); res++; if(map[cy][cx]==0)rainbow++;
    for(int i=0; i<4; i++){
      int ty=cy+dy[i], tx=cx+dx[i];
      if(RAN||visit[ty][tx]==vn)continue;
      if(map[ty][tx]!=color&&map[ty][tx]!=0)continue;
      if(map[ty][tx]==0){if(rbow[ty][tx]==rn)continue; rbow[ty][tx]=rn;}
      else visit[ty][tx]=vn;
      q.push({ty,tx});
    }
  }
  return res;
}
int del(int y, int x){
  int color=map[y][x], res=0;
  queue<p> q;
  q.push({y,x}); map[y][x]=-2;
  
  while(!q.empty()){
    int cy=q.front().first, cx=q.front().second;
    q.pop();
    res++;
    for(int i=0; i<4; i++){
      int ty=cy+dy[i], tx=cx+dx[i];
      if(RAN)continue;
      if(map[ty][tx]==0||map[ty][tx]==color){
        map[ty][tx]=-2;
        q.push({ty,tx});
      }
    }
  }

  return res*res;
}
bool getScore(){
  int num=-1, temp, ny, nx, rb; vn++;
  for(int i=0; i<N; i++)for(int j=0; j<N; j++)if(map[i][j]>0&&visit[i][j]!=vn){
    temp=bfs(i,j);
    if(temp>1&&(temp>num||(temp==num&&rainbow>=rb))){
      ny=i;nx=j;num=temp; rb=rainbow;
    }
  }
  if(num<2)return false;
  ans+=del(ny,nx);
  return true;
}
int main(void){
  scanf("%d %d",&N,&M);
  for(int i=0; i<N; i++)for(int j=0; j<N; j++)scanf("%d",map[i]+j);
  while(getScore()){
    gravity();
    rotat();
    gravity();
  }
  printf("%d",ans);
}
