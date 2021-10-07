#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX=200000;
typedef long long ll;
const ll INF=1LL<<60;
int cost[MAX], N;
vector<int> adj[MAX];
ll A[MAX], B[MAX], C[MAX], ans;

void recur(int curr){
  A[curr]=cost[curr];
  B[curr]=-INF;
  ll M1=-INF, M2=-INF;

  for(int next : adj[curr]){
    recur(next);
    if(A[next]<=0) B[curr]=max(B[curr],C[next]);
    else{
      A[curr]+=A[next];
      B[curr]=max(B[curr],B[next]);
    }
    if(M1<C[next]) {M2=M1; M1=C[next];}
    else if(M2<C[next]) M2=C[next];
  }
  C[curr]=max(A[curr],M1);
  ans=max({ans,A[curr]+B[curr],M1+M2});
}

int main(void){
  int p;
  scanf("%d ",&N);
  scanf("%d %d",&cost[0],&p)
  for(int i=1; i<N; i++){
    scanf("%d %d",&cost[i],&p); p--;
    adj[p].push_back(i);
  }
  recur(0);
  printf("%lld",ans);
}
