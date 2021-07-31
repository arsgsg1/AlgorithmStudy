#include <iostream>
#include <vector>
using namespace std;
const int MAX=100000;
typedef pair<int,int> p;
vector<p> adj[MAX];

int ans,S;
void dfs(int curr, int sum=0, int prev=-1){
  if(ans<sum){
    ans=sum; S=curr;
  }
  for(auto n : adj[curr]){
    int next=n.first, cost=n.second;
    if(next==prev)continue;
    dfs(next,sum+cost,curr);
  }
}


int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int N; cin>>N;
  for(int i=0; i<N; i++){
    int s,e,c; cin>>s;
    while(cin>>e){
      if(e==-1)break;
      cin>>c;
      adj[s-1].push_back({e-1,c});
    }
  }
  dfs(0);
  dfs(S);
  cout<<ans;
}
