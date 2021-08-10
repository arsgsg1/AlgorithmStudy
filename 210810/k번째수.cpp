#include <cstdio>
typedef long long ll;
int main(void){

  ll N,K; scanf("%lld %lld",&N,&K);
  
  ll l=0, h=N*N, mid,t,r,i;
  while(l+1<h){
    mid=(l+h)/2;
    t=0;
    for(i=1; i<=N; i++){r=mid/i; t+=r<N?r:N; if(t>=K)break;}
    if(t>=K)h=mid;
    else l=mid;
  }
  printf("%lld",h);
}
