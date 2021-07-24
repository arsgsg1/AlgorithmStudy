#include <iostream>
#include <queue>
#define RAN (ty<0||tx<0||ty>=N||tx>=M)
using namespace std;
const int INF=1<<28;
typedef pair<pair<int,int>,pair<int,int>> p;
char map[50][50];
int dy[4]={1,-1,0,0}, dx[4]={0,0,1,-1};
bool visit[50][50][1<<6];

int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int N,M; cin>>N>>M;
  queue<p> q;
  for(int i=0; i<N; i++)for(int j=0; j<M; j++){
    cin>>map[i][j];
    if(map[i][j]=='0'){
      visit[i][j][0]=true;
      q.push({{i,j},{0,0}});
    }
  }
  int ans=INF;
  while(!q.empty()){
    int cy=q.front().first.first, cx=q.front().first.second;
    int key=q.front().second.first, cnt=q.front().second.second;
    q.pop();
    if(map[cy][cx]=='1'){
      ans=cnt;
      break;
    }
    else if(map[cy][cx]>='a'&&map[cy][cx]<='z')key|=(1<<(map[cy][cx]-'a'));

    for(int i=0; i<4; i++){
      int ty=cy+dy[i], tx=cx+dx[i];
      if(RAN||map[ty][tx]=='#'||visit[ty][tx][key])continue;
      if(map[ty][tx]>='A'&&map[ty][tx]<='Z'){
        if(key&(1<<(map[ty][tx]-'A'))){
          visit[ty][tx][key]=true;
          q.push({{ty,tx},{key,cnt+1}});
        }
      }
      else{
        visit[ty][tx][key]=true;
        q.push({{ty,tx},{key,cnt+1}});
      }
    }
  }
  if(ans<INF)cout<<ans;
  else cout<<-1;
}

