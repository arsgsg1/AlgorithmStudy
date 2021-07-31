#include <iostream>
#include <queue>
#include <vector>
#define RAN (ty<0||tx<0||ty>=N||tx>=N)
using namespace std;
const int MAX=101;
typedef pair<int,int> p;
int dy[4]={1,-1,0,0}, dx[4]={0,0,1,-1};
bool visit[MAX][MAX], isOn[MAX][MAX];
vector<int> button[MAX*MAX];

int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int N,M; cin>>N>>M;
  for(int i=0; i<M; i++){
    int x,y,a,b; cin>>x>>y>>a>>b;
    x--;y--;a--;b--;
    button[y*N+x].push_back(b*N+a);
  }
  queue<p> q;
  isOn[0][0]=true;
  visit[0][0]=true;
  q.push({0,0});
  int ans=0;
  while(!q.empty()){
    int cy=q.front().first, cx=q.front().second;
    q.pop();
    for(auto n : button[cy*N+cx]){
      int y=n/N, x=n%N;
      if(isOn[y][x])continue;
      isOn[y][x]=true;
      for(int i=0; i<4; i++){
        int ty=y+dy[i], tx=x+dx[i];
        if(RAN||!isOn[ty][tx])continue;
        if(visit[ty][tx]){
          visit[y][x]=true;
          q.push({y,x});
          break;
        }
      }
    }
    for(int i=0; i<4; i++){
      int ty=cy+dy[i], tx=cx+dx[i];
      if(RAN||visit[ty][tx]||!isOn[ty][tx])continue;
      visit[ty][tx]=true;
      q.push({ty,tx});
    }
  }
  for(int i=0; i<N; i++)for(int j=0; j<N; j++)if(isOn[i][j])ans++;
  cout<<ans;
}
