#include <iostream>
#include <queue>
#include <cstring>
#define RAN (ty<0||tx<0||ty>=N||tx>=M)
using namespace std;
typedef pair<int,int> p;
int N,M;
int map[300][300], water[300][300];
int dy[4]={1,-1,0,0}, dx[4]={0,0,1,-1};
bool visit[300][300];
queue<p> q;
void bfs(int y, int x){
  visit[y][x]=true;
  q.push({y,x});
  while(!q.empty()){
    int cy=q.front().first, cx=q.front().second;
    int cnt=0;
    q.pop();
    for(int i=0; i<4; i++){
      int ty=cy+dy[i], tx=cx+dx[i];
      if(RAN||map[ty][tx]<=0){
        cnt++; continue;
      }
      if(!visit[ty][tx]){
        visit[ty][tx]=true;
        q.push({ty,tx});
      }
    }
    water[cy][cx]=cnt;
  }
}
int getcnt(void){
  int cnt=0;
  memset(visit,0,sizeof(visit));
  for(int i=0; i<N; i++)for(int j=0; j<M; j++)if(map[i][j]>0&&!visit[i][j]){
    cnt++;
    bfs(i,j);
  }
  return cnt;
}

int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin>>N>>M;
  for(int i=0; i<N; i++)for(int j=0; j<M; j++)cin>>map[i][j];
  int cnt=0, year=0;
  while(true){
    cnt=getcnt();
    if(cnt==0||cnt>1)break;
    year++;
    for(int i=0; i<N; i++)for(int j=0; j<M; j++)
      if(map[i][j]>0)map[i][j]-=water[i][j];
  }
  if(cnt==0)cout<<0;
  else cout<<year;
}
