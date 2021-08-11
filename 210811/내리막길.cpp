#include <cstdio>
#include <cstring>
#define RAN (ty<0||tx<0||ty>=N||tx>=M)

int dy[4]={1,-1,0,0}, dx[4]={0,0,1,-1};
int dp[501][501],map[501][501];
int N,M;
int recur(int y, int x){
  int &res= dp[y][x];
  if(res!=-1)return res;
  if(y==N-1&&x==M-1)return res=1;
  res=0;
  for(int i=0; i<4; i++){
    int ty=y+dy[i], tx=x+dx[i];
    if(RAN||map[ty][tx]>=map[y][x])continue;
    res+=recur(ty,tx);
  }
  return res;
}

int main(void){
  scanf("%d %d",&N,&M);
  for(int i=0; i<N; i++)for(int j=0; j<M; j++)scanf("%d",map[i]+j);
  memset(dp,-1,sizeof(dp)); 
  printf("%d",recur(0,0));
}
