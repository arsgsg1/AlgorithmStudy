#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

void setting(vector<int> &f, vector<int> &b, string &s, string& c){
  int idx=0;
  for(size_t i=0; i<s.size(); i++)if(c[idx]==s[i]){
    f.push_back(i);
    idx++;
    if(idx==c.size()){
      f.push_back(s.size());
      break;
    }
  }
  idx--;
  b.push_back(s.size());
  for(int i=s.size()-1; i>=0; i--)if(c[idx]==s[i]){
    b.push_back(i);
    idx--;
    if(idx<0){
      break;
    }
  }
  sort(b.begin(),b.end());
}

int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int N; cin>>N;
  while(N--){
    string a,b,c;
    cin>>a>>b>>c;
    vector<int> xf,xb,yf,yb;
    setting(xf,xb,a,c);
    setting(yf,yb,b,c);
    for(int i=0; i<xf.size(); i++){
      cout<<xf[i]<<" "<<xb[i]<<" "<<yf[i]<<" "<<yb[i]<<'\n';
    }
    int alpha[26];
    bool flag=false;
    cout<<(flag?1:0)<<'\n';
  }
}
