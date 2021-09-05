#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int MAX=100001;
typedef long long ll;
typedef pair<ll,int> p;
int main(void){
  priority_queue<p,vector<p>> pq;
  int N,n,m=MAX,M=0;
  ll ans=0,temp;
  scanf("%d",&N);
  for(int i=0; i<N; i++){scanf("%d",&n);pq.push({n,i});}
  m=min(m,pq.top().second);
  M=max(M,pq.top().second);
  pq.pop();

  while(!pq.empty()){
    temp=pq.top().first*(max(abs(m-pq.top().second),abs(M-pq.top().second))-1);
    m=min(m,pq.top().second);
    M=max(M,pq.top().second);
    ans=max(temp,ans);
    pq.pop();
  }
  
  printf("%lld",ans);
}
