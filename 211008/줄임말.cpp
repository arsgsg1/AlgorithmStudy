#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool alS[27], alT[27];
vector<int> v[27];

int main(void){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string S,T;
  cin>>S>>T;
  int N=S.size(), M=T.size();
  for(int i=0; i<N; i++)alS[S[i]-'a']=true;
  for(int i=0; i<M; i++){alT[T[i]-'a']=true;v[T[i]-'a'].push_back(i);}
  for(int i=0; i<27; i++)if(alS[i]&(!alT[i])){
    cout<<-1; return 0;
  }
  int ans=1, last=-1;
  for(int i=0; i<N; i++){
    int t=S[i]-'a';
    int n =lower_bound(v[t].begin(), v[t].end(),last+1)-v[t].begin();
    if(n==v[t].size()){ans++;n=0;}
    last=v[t][n];
  }
  cout<<ans;
}
