#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int MAX=100001, MOD=1000000007;
int N, dp[10][MAX][2], light[MAX];
vector<int> adj[MAX];

int recur(int prev, int curr, int isOn, int par=-1){
  int &res=dp[prev][curr][isOn];
  if(res!=-1)return res;
  res=isOn?1:0;
  for(int next : adj[curr])if(next!=par){
    res=(res+recur(prev,next,0,curr))%MOD;
    if(light[next]>=prev)res=(res+recur(light[next],next,1,curr))%MOD;
    
  }
  return res;
}

int main(void){
  scanf("%d",&N);
  memset(dp,-1,sizeof(dp));
  for(int i=0; i<N; i++)scanf("%d",light+i);
  int s,e;
  for(int i=0; i<N-1; i++){
    scanf("%d %d",&s,&e);
    s--;e--;
    adj[s].push_back(e);
    adj[e].push_back(s);
  }
  printf("%d",(recur(0,0,0)+recur(light[0],0,1))%MOD);
}
