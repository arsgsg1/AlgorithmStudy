#include <cstdio>
#include <vector>
#include <cstring>
#include <unordered_map>
using namespace std;
const int MAX=502;

int N,M, dy[4]={0,0,1,-1}, dx[4]={1,-1,0,0}, par[MAX*MAX];
bool isCycle[MAX*MAX];
char map[MAX];
int getpar(int a){
  return par[a]<0?a:par[a]=getpar(par[a]);
}

void setUnion(int a, int b){
  a=getpar(a);
  b=getpar(b);
  if(a==b){isCycle[a]=true;return;}
  par[a]+=par[b];
  par[b]=a;
  return;
}

int main(void){
  memset(par,-1,sizeof(par));
  scanf("%d %d ",&N,&M);
  unordered_map<char,int> st;
  st['L']=1; st['R']=0; st['U']=3; st['D']=2;
  for(int i=1; i<=N; i++){
    scanf("%s ",map);
    for(int j=0; j<M; j++){
      int ty=i+dy[st[map[j]]], tx=j+dx[st[map[j]]];
      setUnion(ty*MAX+tx+1,i*MAX+j+1);
    }
  }
  int ans=0;
  for(int i=0; i<=N+1; i++)for(int j=0; j<=M+1; j++)if(par[i*MAX+j]<-1&&!isCycle[i*MAX+j])ans-=par[i*MAX+j]+1;
  printf("%d",ans);
}
