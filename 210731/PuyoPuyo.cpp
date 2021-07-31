#include <iostream>
#include <queue>
#define RAN (ty<0||ty>=N||tx<0||tx>=M)
using namespace std;
const int N=12, M=6;
typedef pair<int,int> p;
char map[N][M];
int dy[4]={1,-1,0,0}, dx[4]={0,0,1,-1};
int visit[N][M], group[N][M], gcnt , vcnt;
bool isDelete[N*M];
queue<p> q;

int cntGroup(void){
  vcnt++;
  gcnt=0;
  int res=0;
  for(int i=0; i<N; i++)for(int j=0; j<M; j++)
    if(visit[i][j]!=vcnt&&map[i][j]!='.'){
      gcnt++;
      int cnt=0;
      visit[i][j]=vcnt;
      group[i][j]=gcnt;
      q.push({i,j});
      while(!q.empty()){
        int cy=q.front().first, cx=q.front().second;
        q.pop();
        cnt++;
        for(int k=0; k<4; k++){
          int ty=dy[k]+cy, tx=dx[k]+cx;
          if(RAN||visit[ty][tx]==vcnt||map[i][j]!=map[ty][tx])continue;
          visit[ty][tx]=vcnt;
          group[ty][tx]=gcnt;
          q.push({ty,tx});
        }
      }
      if(cnt>3){
        res++;
        isDelete[gcnt]=true;
      }
      else isDelete[gcnt]=false;
    }
  return res;
}

void deleteGroup(void){
  for(int i=0; i<N; i++)for(int j=0; j<M; j++)
    if(isDelete[group[i][j]])map[i][j]='.';
}
void moveDown(void){
  for(int i=0; i<M; i++){
    int t=N-1, p=N-1;
    while(t>=0){
      if(map[t][i]!='.'){t--;p--;}
      else{
        while(p>=0&&map[p][i]=='.')p--;
        if(p<0)break;
        swap(map[t][i],map[p][i]);
        t--;
      }
    }
  }
}
int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  for(int i=0; i<N; i++){
    string str; cin>>str;
    for(int j=0; j<M; j++)map[i][j]=str[j];
  }
  int ans=0;
  while(cntGroup()){
    ans++;
    deleteGroup();
    moveDown();
  }
  cout<<ans;
}
