#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#define RAN (ty<0||tx<0||ty>=N||tx>=M)
using namespace std;
const int MAX=101;
typedef pair<int,int> p;
char map[MAX][MAX], str[MAX];
vector<p> v;
int N,T,M,key,visit[MAX][MAX];
int dy[4]={0,0,1,-1}, dx[4]={1,-1,0,0};

int bfs(void){
  int res=0;
  for(int j=0; j<M; j++){
    if(map[0][j]!='*')v.push_back({0,j});
    if(map[N-1][j]!='*')v.push_back({N-1,j});
  }
  for(int i=0; i<N; i++){
    if(map[i][0]!='*')v.push_back({i,0});
    if(map[i][M-1]!='*')v.push_back({i,M-1});
  }
  queue<p> q;
  while(true){
    bool flag=false;
    for(auto n : v){
      int y=n.first, x=n.second;
      if(map[y][x]=='.'||(map[y][x]>='a'&&map[y][x]<='z')||key&1<<(map[y][x]-'A')){
        if(visit[y][x]!=key){
          q.push({y,x});
          flag=true;
        }
      }
    }
    if(!flag)break;
    while(!q.empty()){
      int cy=q.front().first, cx=q.front().second;
      q.pop();
      for(int i=0; i<4; i++){
        int ty=cy+dy[i], tx=cx+dx[i];
        if(RAN||visit[ty][tx]==key||map[ty][tx]=='*')continue;
        if(map[ty][tx]>='A'&&map[ty][tx]<='Z'&&!(key&1<<(map[ty][tx]-'A')))continue;
        else if(map[ty][tx]>='a'&&map[ty][tx]<='z')key|=1<<(map[ty][tx]-'a');
        else if(map[ty][tx]=='$'){
          res++;
          map[ty][tx]='.';
        }
        visit[ty][tx]=key;
        q.push({ty,tx});
      }
    }
  }
  return res;
}
void init(){
  key=0;
  memset(visit,-1,sizeof(visit));
  v.clear();
}
int main(void){
  scanf("%d",&T);
  while(T--){
    init();
    scanf("%d %d ",&N,&M);
    for(int i=0; i<N; i++){
      scanf("%s ",str);
      for(int j=0; j<M; j++)map[i][j]=str[j];
    }
    scanf("%s ",str);
    if(strcmp(str,"0")){
      for(size_t i=0; i<strlen(str); i++)key|=1<<(str[i]-'a');
    }
    printf("%d\n",bfs());
  }
}
