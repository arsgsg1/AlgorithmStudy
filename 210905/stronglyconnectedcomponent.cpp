#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
const int MAX=10001;
int dfsn[MAX],cnt;
vector<int> adj[MAX];
vector<vector<int>> ans;
bool finish[MAX];
stack<int> s;
int dfs(int curr){
  int res=dfsn[curr]=++cnt;
  s.push(curr);

  for(int next : adj[curr]){
    if(dfsn[next]==0)res=min(res,dfs(next));
    else if(!finish[next])res=min(res,dfsn[next]);
  }

  if(res==dfsn[curr]){
    vector<int> scc;
    while(true){
      int temp=s.top(); s.pop();
      scc.push_back(temp+1);
      finish[temp]=true;
      if(temp==curr)break;
    }
    sort(scc.begin(),scc.end());
    scc.push_back(-1);
    ans.push_back(scc);
  }
  return res;
}

int main(void){
  int N,M,S,E;
  scanf("%d %d",&N,&M);
  for(int i=0; i<M; i++){
    scanf("%d %d",&S,&E);
    S--;E--;
    adj[S].push_back(E);
  }
  for(int i=0; i<N; i++)if(dfsn[i]==0)dfs(i);
  sort(ans.begin(),ans.end());
  printf("%lu\n",ans.size());
  for(auto v : ans){
    for(auto n : v)printf("%d ",n);
    printf("\n");
  }
}
