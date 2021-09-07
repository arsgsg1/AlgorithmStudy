#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int MAX=10001;
vector<int> adj[MAX];
int pp[MAX], N, dp[MAX][2];

int recur(int curr, int isSelect, int prev=-1){
  int &res=dp[curr][isSelect];
  if(res!=-1)return res;
  res=isSelect>0?pp[curr]:0;
  for(auto next : adj[curr])if(next!=prev)res+=isSelect>0?recur(next,0,curr):max(recur(next,1,curr),recur(next,0,curr));
  return res;
}

int main(void){
  int s,e;
  scanf("%d",&N);
  memset(dp,-1,sizeof(dp));
  for(int i=0; i<N; i++)scanf("%d",pp+i);
  for(int i=0; i<N-1; i++){
    scanf("%d %d",&s,&e);
    s--;e--;
    adj[s].push_back(e);
    adj[e].push_back(s);
  }
  printf("%d",max(recur(0,0),recur(0,1)));
}

