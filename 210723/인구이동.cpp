#include <iostream>
#include <cstring>
#include <queue>
#define RAN (ty<0||tx<0||ty>=N||tx>=N)
using namespace std;
typedef pair<int,int> p;
int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
int check[51][51], cnt, Move[2503][2];
int map[51][51], N, L, R;

bool isMove(void){
  cnt=0;
  memset(check,0,sizeof(check));
  queue<p> q;
  for(int i=0; i<N; i++)for(int j=0; j<N; j++)if(check[i][j]==0){
    check[i][j]=++cnt;
    q.push({i,j});
    Move[cnt][0]=map[i][j];
    Move[cnt][1]=1;
    while(!q.empty()){
      int cy=q.front().first, cx=q.front().second;
      q.pop();
      for(int i=0; i<4; i++){
        int ty=cy+dy[i], tx=cx+dx[i];
        if(RAN||abs(map[cy][cx]-map[ty][tx])<L||abs(map[cy][cx]-map[ty][tx])>R||check[ty][tx]>0)continue;
        check[ty][tx]=cnt;
        Move[cnt][0]+=map[ty][tx];
        Move[cnt][1]+=1;
        q.push({ty,tx});
      }
    }
  }
  if(cnt==N*N)return false;
  for(int i=0; i<N; i++)for(int j=0; j<N; j++){
    int n=check[i][j];
    map[i][j]=Move[n][0]/Move[n][1];
  }
  return true;
} 

int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin>>N>>L>>R;
  for(int i=0; i<N; i++)for(int j=0; j<N; j++)cin>>map[i][j];
  int ans=0;
  while(isMove())ans++;
  cout<<ans;
}
