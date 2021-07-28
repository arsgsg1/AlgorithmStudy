#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int MAX=20000;
vector<int> adj[MAX];
int N,M, dfsn[MAX];
bool isOddCycle;

void dfs(int curr, int dep=1, int prev=-1){
  int res=dfsn[curr]=dep;
  for(int next:adj[curr])if(prev!=next){
    if(isOddCycle)return;
    if(dfsn[next]==0)dfs(next,dep+1,curr);
    else if(dfsn[next]<res&&(res-dfsn[next]+1)%2) isOddCycle=true;
  }
}

void init(){
  isOddCycle=false;
  memset(dfsn,0,sizeof(dfsn));
  for(int i=0; i<N; i++)adj[i].clear();
}

int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int T; cin>>T;
  while(T--){
    cin>>N>>M;
    init();
    for(int i=0; i<M; i++){
      int s, e; cin>>s>>e; s--;e--;
      adj[s].push_back(e);
      adj[e].push_back(s);
    }
    for(int i=0; i<N; i++)if(dfsn[i]==0)dfs(i);
    if(isOddCycle)cout<<"NO\n";
    else cout<<"YES\n";
  }
}
