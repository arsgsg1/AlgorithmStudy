#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


string bigAdd(string& a, string &b){
  int carry =0;
  string result="";

  while(!a.empty()||!b.empty()||carry){
    if(!a.empty()){
      carry+=a.back()-'0';
      a.pop_back();
    }
    if(!b.empty()){
      carry+=b.back()-'0';
      b.pop_back();
    }
    result+=(carry%10+'0');
    carry/=10;
  }
  reverse(result.begin(),result.end());
  return result;
}
string bigDot(string& a, string& b){
  string x,y,w,z,r,p,q;
  int n, m;
  n=max(a.size(),b.size());
  if(a.size==0||b.size()==0) return "0";
  else{
    m=n/2;
    x=:
  }
}
int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int T; cin>>T;
  while(T--){
    string a,b;
    cin>>a>>b;
  }
}
