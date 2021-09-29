#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 100001;
typedef long long ll;
int N,K;
ll dp[2][MAX], arr[MAX];

ll recur(int curr, int isStart){
  if(curr>N)return 0;
  ll &res = dp[isStart][curr];
  if(res!=-1)return res;
  res=0;
  int next = curr+1;
  if(isStart){
    int l=curr-1, h=N;
    while(l+1<h){
      int mid=(l+h)/2;
      if(arr[mid]-arr[curr-1]>=K)h=mid;
      else l=mid;
    }
    res=arr[h]-arr[curr-1]-K;
    next=h+1;
  }
  res+=max(recur(next,0),recur(next,1));
  return res;
}

int main(void){
  ll t;
  scanf("%d %d",&N,&K);
  memset(dp,-1,sizeof(dp));
  for(int i=0; i<N; i++){
    scanf("%lld ",&t);
    arr[i+1]=arr[i]+t;
  }
  printf("%lld",max(recur(1,0),recur(1,1)));
}

