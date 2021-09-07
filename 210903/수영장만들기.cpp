#include <cstdio>
#include <algorithm>
#define RAN (ty<0||tx<0||ty>=N||tx>=M)
using namespace std;

int dy[4]={1,-1,0,0}, dx[4]={0,0,1,-1};
int N,M,map[51][51],water[2501], par[2501];
int getpar(int a){
  return par[a]<0?a:par[a]=getpar(par[a]);
}
void setUnion(int a, int b){
  a=getpar(a);
  b=getpar(b);
  if(a==b)return;
  par[b]=a;
  water[a]=min(water[a],water[b]);
}

int getMax(int y, int x){
  int res=10, ty,tx,temp;
  bool isZero=false;
  for(int i=0; i<4; i++)if(!isZero){
    ty=y+dy[i]; tx=x+dx[i];
    if(RAN)isZero=true;

    temp=map[ty][tx];
    while(!RAN&&!isZero){
      if(map[ty][tx]==0)isZero=true;
      temp=max(temp,map[ty][tx]);
      ty+=dy[i]; tx+=dx[i];
    }
    res=min(res,temp);
  }
  res=res<map[y][x]?0:res-map[y][x];
  return isZero?0:res;
}

int main(void){
  scanf("%d %d ",&N,&M);
  fill(par,par+N*M,-1);
  char str[51];
  for(int i=0; i<N; i++){
    scanf("%s ",str);
    for(int j=0; j<M; j++)map[i][j]=str[j]-'0';
  }
  for(int i=0; i<N; i++)for(int j=0; j<M; j++)if(map[i][j]>0)water[i*50+j]=getMax(i,j);
  for(int i=0; i<N; i++)for(int j=0; j<M; j++)if(water[i*50+j]>0){
    for(int k=0; k<4; k++){
      int ty=i+dy[k], tx=j+dx[k];
      if(RAN||water[ty*50+tx]==0)continue;
      setUnion(i*50+j,ty*50+tx);
    }
  }
  int ans=0;
  for(int i=0; i<N; i++){for(int j=0; j<M; j++)printf("%d ",water[i*50+j]);
  printf("\n");}
  for(int i=0; i<N; i++)for(int j=0; j<M; j++)ans+=water[getpar(i*50+j)];
  printf("%d",ans);
}
