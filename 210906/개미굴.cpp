#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
vector<string> vv[1001];
struct Trie{
  map<string,Trie*> next;
  
  void insert(const vector<string> &v){
    Trie* temp=this;
    for(auto str:v){
      if(!temp->next[str])temp->next[str]=new Trie();
      temp=temp->next[str];
    }
  }
  void find(int n=0){
    for(auto m : this->next){
      for(int i=0; i<2*n; i++)cout<<'-';
      cout<<m.first<<'\n';
      m.second->find(n+1);
    }
  }
};
int main(void){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  Trie* root =new Trie();
  int N,n; cin>>N;
  string str;
  for(int i=0; i<N; i++){
    cin>>n;
    while(n--){
      cin>>str;
      vv[i].push_back(str);
    }
  }
  for(int i=0; i<N; i++)root->insert(vv[i]);
  root->find();
  delete root;
}

