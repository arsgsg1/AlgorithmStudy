#include <iostream>
#include <queue>
#include <cstring>
#define RAN (ty<0||tx<0||ty>=N||tx>=N)
using namespace std;
typedef pair<int,int> p;
queue<p> q;
char map[101][101];
bool visit[101][101];
int dy[4]={1,-1,0,0}, dx[4]={0,0,1,-1}, N;

void bfs(int y, int x){
  q.push({y,x});
  visit[y][x]=true;
  while(!q.empty()){
    int cy=q.front().first, cx=q.front().second;
    q.pop();
    for(int i=0; i<4; i++){
      int ty=cy+dy[i], tx=cx+dx[i];
      if(RAN||visit[ty][tx]||map[ty][tx]!=map[y][x])continue;
      visit[ty][tx]=true;
      q.push({ty,tx});
    }
  }
}

int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin>>N;
  for(int i=0; i<N; i++){
    string str; cin>>str;
    for(int j=0; j<N; j++)map[i][j]=str[j];
  }
  int ans=0,ans2=0;
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)if(!visit[i][j]){
      ans++;
      bfs(i,j);
    }
  memset(visit,0,sizeof(visit));
  for(int i=0; i<N; i++)for(int j=0; j<N; j++)if(map[i][j]=='G')map[i][j]='R';
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)if(!visit[i][j]){
      ans2++;
      bfs(i,j);
    }
  cout<<ans<<" "<<ans2;
}
