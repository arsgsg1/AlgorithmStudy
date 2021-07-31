#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int MAX=100001,K=18;
int par[MAX][K], dep[MAX];
vector<int> adj[MAX];

void dfs(int curr, int prev=-1){
  for(int next : adj[curr])if(next!=prev){
    par[next][0]=curr;
    dep[next]=dep[curr]+1;
    dfs(next,curr);
  }
}

int lca(int a, int b){
  if(dep[a]<dep[b])swap(a,b);
  int t=dep[a]-dep[b];
  for(int j=0; t; j++){
    if(t&1) a=par[a][j];
    t>>=1;
  }
  if(a==b)return a+1;
  
  for(int j=K-1; j>=0; j--)
    if(par[a][j]!=-1&&par[a][j]!=par[b][j]){
      a=par[a][j];
      b=par[b][j];
    }
  return par[a][0]+1;
}

int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int N; cin>>N;
  for(int i=0; i<N-1; i++){
    int s, e; cin>>s>>e;
    s--; e--;
    adj[s].push_back(e);
    adj[e].push_back(s);
  }
  memset(par,-1,sizeof(par));
  dfs(0);

  for(int j=0; j<K; j++)
    for(int i=0; i<N; i++)
      if(par[i][j]!=-1)
        par[i][j+1]=par[par[i][j]][j];
  int M; cin>>M;
  while(M--){
    int a, b; cin>>a>>b;
    cout<<lca(a-1,b-1)<<'\n';
  }
}
