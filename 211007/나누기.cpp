#include <cstdio>
const int MAX=100001;
typedef long long ll;
int N;
ll sum[MAX], dp[5];
int main(void){
  scanf("%d ",&N);
  for(int i=0; i<N; i++){
    scanf("%lld",sum+i+1);
    sum[i+1]+=sum[i];
  }
  if(sum[N]%4!=0){
    printf("0");
    return 0;
  }
  ll t = sum[N]/4;
  dp[0]=1;
  for(int i=1; i<=N-1; i++){
    if(sum[i]==t*3)dp[3]+=dp[2];
    if(sum[i]==t*2)dp[2]+=dp[1];
    if(sum[i]==t)dp[1]+=dp[0];
  }
  printf("%lld",dp[3]);
}

