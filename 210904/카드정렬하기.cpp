#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int main(void){
  int N,n,n1,n2,ans=0; scanf("%d",&N);
  priority_queue<int,vector<int>,greater<int>>pq;
  for(int i=0; i<N; i++){scanf("%d",&n);pq.push(n);}
  while(pq.size()>1){
    n1=pq.top(); pq.pop(); n2=pq.top(); pq.pop();
    ans+=n1+n2;
    pq.push(n1+n2);
  }
  printf("%d",ans);
}
