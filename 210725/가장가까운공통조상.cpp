#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int MAX=10000, K=17;
int par[MAX][K], p[MAX], dep[MAX];
vector<int> adj[MAX];

int getp(int a){
  if(p[a]==-1)return a;
  return p[a]=getp(p[a]);
}
void dfs(int curr, int prev=-1){
  for(int next: adj[curr])if(next!=prev){
    par[next][0]=curr;
    dep[next]=dep[curr]+1;
    dfs(next,curr);
  }
}
int lca(int a, int b){
  if(dep[a]<dep[b])swap(a,b);
  int t=dep[a]-dep[b];
  for(int j=0; t; j++){
    if(t&1)a=par[a][j];
    t>>=1;
  }
  if(a==b)return a;
  for(int j=K-1; j>=0; j--)
    if(par[a][j]!=-1&&par[a][j]!=par[b][j]){
      a=par[a][j];
      b=par[b][j];
    }
  return par[a][0];
}

int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int T;cin>>T;
  while(T--){
    int N; cin>>N;
    for(int i=0; i<N; i++){
      p[i]=-1;dep[i]=0; adj[i].clear();
      for(int j=0; j<K; j++)par[i][j]=-1;
    }
    for(int i=0; i<N-1; i++){
      int s,e; cin>>s>>e;
      s--;e--;
      adj[s].push_back(e);
      p[e]=getp(s);
    }
    int root=getp(0);
    dfs(root);

    for(int j=0; j<K; j++)
      for(int i=0; i<N; i++)
        if(par[i][j]!=-1)
          par[i][j+1]=par[par[i][j]][j];
    int a,b; cin>>a>>b; a--;b--;
    cout<<lca(a,b)+1<<'\n';
  }
}
