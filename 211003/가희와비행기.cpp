#include <cstdio>

int N,M;
long long dp[2][4002];

int main(void){
  scanf("%d %d",&N,&M);
  dp[0][1]=1;
  for(int i=1; i<N; i++){
    for(int j=2; j<=i+1; j++){
      dp[1][j]=(dp[0][j+1]+dp[0][j-1])%M;
    }
    dp[1][1]=dp[0][2];
    dp[1][0]=dp[0][1];
    for(int j=0; j<=N; j++){
      dp[0][j]=dp[1][j];
      dp[1][j]=0;
    }
  }
  printf("%lld",dp[0][0]);
}
