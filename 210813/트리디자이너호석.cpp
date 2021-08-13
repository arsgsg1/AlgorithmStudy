#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
const int MAX=100001, MOD=1000000007;
int num[MAX];
vector<int> adj[MAX];
int dp[MAX][10][2];
int recur(int curr, int isOn, int last=0, int prev=-1){
  int &res=dp[curr][last][isOn];
  if(res!=-1)return res;
  res=0;
  if(isOn)res=1;
  for(auto next : adj[curr]){
    if(next==prev)continue;
    res=(res%MOD+recur(next,0,last,curr)%MOD)%MOD;
    if(last<=num[next]) res=(res%MOD+recur(next,1,num[next],curr))%MOD;
  }

  return res;
}
int main(void){
  int N,S,E; scanf("%d",&N);
  memset(dp,-1,sizeof(dp));
  for(int i=0; i<N; i++)scanf("%d",num+i);
  for(int i=0; i<N-1; i++){
    scanf("%d %d",&S,&E);S--;E--;
    adj[S].push_back(E);
    adj[E].push_back(S);
  }
  
  printf("%d",(recur(0,0)%MOD+recur(0,1,num[0])%MOD)%MOD);
}
