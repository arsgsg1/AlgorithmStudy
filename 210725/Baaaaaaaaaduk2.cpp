#include <iostream>
#include <queue>
#define RAN (ty<0||tx<0||ty>=N||tx>=M)
using namespace std;
typedef pair<int,int> p;
int dy[4]={1,-1,0,0}, dx[4]={0,0,1,-1};
int visit[20][20], cnt=1;
int N,M,map[20][20];
p stone[400];
int bfs(void){
  int ans=0;
  cnt++;
  queue<p> q;
  for(int i=0; i<N; i++)
    for(int j=0; j<M; j++)if(visit[i][j]<cnt&&map[i][j]==2){
      int cnt0=0, cnt2=1;
      q.push({i,j});
      visit[i][j]=cnt;
      while(!q.empty()){
        int cy=q.front().first, cx=q.front().second;
        q.pop();
        for(int k=0; k<4; k++){
          int ty=cy+dy[k], tx=cx+dx[k];
          if(RAN||map[ty][tx]==1)continue;
          if(visit[ty][tx]==cnt){
            if(map[ty][tx]==0)cnt0++;
            continue;
          }
          visit[ty][tx]=cnt;
          if(map[ty][tx]==0) cnt0++;
          else {
            cnt2++;
            q.push({ty,tx});
          }
        }
      }
      if(cnt0==0)ans+=cnt2;
    }
  return ans;
}
int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n=0;cin>>N>>M;
  for(int i=0; i<N; i++)for(int j=0; j<M; j++)cin>>map[i][j];
  queue<p> q;
  for(int i=0; i<N; i++)for(int j=0; j<M; j++)if(map[i][j]==2&&visit[i][j]==0){
    q.push({i,j});
    visit[i][j]=1;
    while(!q.empty()){
      int cy=q.front().first, cx=q.front().second;
      q.pop();
      for(int k=0; k<4; k++){
        int ty=cy+dy[k], tx=cx+dx[k];
        if(RAN||map[ty][tx]==1||visit[ty][tx]==1)continue;
        visit[ty][tx]=1;
        if(map[ty][tx]==0) stone[n++]={ty,tx};
        else q.push({ty,tx});
      }
    }
  }
  int ans=0;
  for(int i=0; i<n-1; i++)
    for(int j=i+1; j<n; j++){
      int y1=stone[i].first, x1=stone[i].second;
      int y2=stone[j].first, x2=stone[j].second;
      map[y1][x1]=map[y2][x2]=1;
      ans=max(ans,bfs());
      map[y1][x1]=map[y2][x2]=0;
    }
  cout<<ans;
}
