#include <cstdio>
#include <unordered_map>
using namespace std;
typedef long long ll;
const int MAX=1000001;
ll sum[MAX];

int main(void){
  int N,M,n; scanf("%d %d",&N,&M);
  unordered_map<int,ll> hm; hm[0]++;
  for(int i=0; i<N; i++){scanf("%d",&n);sum[i+1]=sum[i]+n;hm[sum[i+1]%M]++:}
  ll ans=0;
  for(auto it : hm)ans+=(it.second*(it.second-1))/2;
  printf("%lld",ans);
}

