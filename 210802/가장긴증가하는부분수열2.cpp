#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int N; cin>>N;
  vector<int> v;
  for(int i=0; i<N; i++){
    int n; cin>>n;
    int idx=lower_bound(v.begin(),v.end(),n)-v.begin();
    if(idx>=v.size())v.push_back(n);
    else v[idx]=n;
  }
  cout<<v.size();
}
