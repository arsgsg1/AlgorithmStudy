#include <cstdio>
using namespace std;
const int MAX=65537;
int seg[MAX],arr[250001];

void update(int n, int v){
  while(n<MAX){
    seg[n]+=v;
    n+=n&-n;
  }
}
int get(int n){
  int ans=0;
  while(n){
    ans+=seg[n];
    n-=n&-n;
  }
  return ans;
}

int main(void){
  int N,K,k;
  long long ans=0;
  scanf("%d %d",&N,&K);
  k=(K+1)/2;
  for(int i=1; i<=N; i++){
    scanf("%d",arr+i);
    update(arr[i]+1,1);
    if(i>=K){
      int l=0, h=MAX;
      while(l+1<h){
        int mid=(l+h)/2;
        if(get(mid)>=k)h=mid;
        else l=mid;
      }
      ans+=h-1;
      update(arr[i-K+1]+1,-1);
    }
  }
  printf("%lld",ans);
}

