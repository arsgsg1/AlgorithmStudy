#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[1001][2], map[1001][1001];
int main(void){
  int N,M;
  while(scanf("%d %d",&N,&M)){
    if(N==0&&M==0)break;
    bool flag=false;
    for(int i=0; i<N; i++)for(int j=0; j<M; j++){
      scanf("%d",&map[i][j]);
      if(map[i][j])flag=true;
    }
    memset(dp,0,sizeof(dp));
    int ans=flag?1:0;
    for(int i=1; i<N; i++){
      for(int j=1; j<M; j++){
        if(map[i-1][j-1]&&map[i-1][j]&&map[i][j-1]&&map[i][j]){
          dp[j][1]=min({dp[j-1][0],dp[j][0],dp[j-1][1]})+1;
          ans=max(ans,dp[j][1]+1);
        }
      }
    
      for(int j=0; j<M; j++){
        dp[j][0]=dp[j][1];
        dp[j][1]=0;
      }
    }
    printf("%d\n",ans);
  }
}
