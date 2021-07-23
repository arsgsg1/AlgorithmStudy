#include <iostream>
#include <deque>
using namespace std;
deque<int> dq;
int N;

int sti(const string& str){
  int n=0;
  for(size_t i=0; i<str.size(); i++){
    n*=10;
    n+=str[i]-'0';
  }
  return n;
}

void tocken(const string& str){
  size_t end = str.size()-1;
  for(size_t i=1, j=1; i<end; i++){
    j=i;
    while(j<end&&str[j]!=',')j++;
    dq.push_back(sti(str.substr(i,j-i)));
    i=j;
  }
}
int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int T; cin>>T;
  while(T--){
    string str; cin>>str;
    cin>>N;
    dq.clear();
    bool isBack=false, isError=false;
    string temp; cin>>temp;
    tocken(temp);
    for(size_t i=0; i<str.size(); i++){
      if(str[i]=='R')isBack=!isBack;
      else{
        if(isBack){
          if(dq.empty()){isError=true; break;}
          dq.pop_back();
        }
        else{
          if(dq.empty()){isError=true; break;}
          dq.pop_front();
        }
      }
    }
    if(isError){
      cout<<"error\n";
      continue;
    }
    cout<<'[';
    while(!dq.empty()){
      int n;
      if(isBack){
        n=dq.back();
        dq.pop_back();
      }
      else{
        n=dq.front();
        dq.pop_front();
      }
      cout<<n;
      if(!dq.empty())cout<<',';
    }
    cout<<"]\n";
  }
}
