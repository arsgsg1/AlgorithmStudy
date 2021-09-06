#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
const int MAX=10001;
unordered_map<char,int> idx;
vector<string>str[MAX], t[MAX];

void token(const string& _str, int n){
  bool isNum,isFinish=false;
  for(size_t i=0,j=0; i<_str.size(); i++)if(!isFinish){
    isNum=_str[i]>='0'&&_str[i]<='9'?true:false;
    
    if(isNum) while(j<_str.size()&&_str[j]>='0'&&_str[j]<='9')j++;
    else while(j<_str.size()&&(_str[j]<'0'||_str[j]>'9'))j++;
    
    str[n].push_back(_str.substr(i,j-i));
    i=j-1;
    isFinish=j==_str.size()?true:false;
  }
}

int numCompare(const string& str, const string& dst){
  int zn1=0, zn2=0; size_t i=0, j=0;
  while(i<str.size()&&str[i++]=='0')zn1++;
  while(j<dst.size()&&dst[j++]=='0')zn2++;
  size_t s1=str.size()-zn1, s2=dst.size()-zn2;
  if(s1>s2)return 1;
  else if(s1<s2) return -1;
  for(;i<s1; i++,j++){
    if(str[i]>dst[j])return 1;
    else if(str[i]<dst[j])return -1;
  }
  if(zn1>zn2)return 1;
  else if(zn1<zn2)return -1;
  else return 0;
}

int charCompare(const string& str, const string& dst){
  for(size_t i=0,j=0;i<str.size()&&j<dst.size();i++,j++){ 
    if(idx[str[i]]>idx[dst[j]])return 1;
    else if(idx[str[i]]<idx[dst[j]])return -1;
  }
  if(str.size()>dst.size())return 1;
  else if(str.size()<dst.size())return -1;
  else return 0;
}

int compare(const string& str, const string& dst){
  bool isStrNum=str[0]<='9'&&str[0]>='0'?true:false;
  bool isDstNum=dst[0]<='9'&&dst[0]>='0'?true:false;
  if(isStrNum^isDstNum)return isStrNum?-1:1;
  if(isStrNum)return numCompare(str,dst);
  else return charCompare(str,dst);
}

void merge(int l, int mid, int r){
  int ll=l, rr=mid, index=l;
  while(ll<mid&&rr<r){
    int check=0; size_t i=0, j=0;
    while(i<str[ll].size()&&j<str[rr].size()&&check==0){
      check=compare(str[ll][i],str[rr][j]);
      i++,j++;
    }
    if(check==1) t[index++]=str[rr++];
    else t[index++]=str[ll++];
  }
  while(ll<mid)t[index++]=str[ll++];
  while(rr<r)t[index++]=str[rr++];

  for(int i=l; i<r; i++)str[i]=t[i];
}

void mergeSort(int l, int r){
  if(l+1==r)return;
  int mid=(l+r)/2;
  mergeSort(l,mid);
  mergeSort(mid,r);
  merge(l,mid,r);
}
void print(int N){
  for(int i=0; i<N; i++){
    for(size_t j=0; j<str[i].size(); j++)cout<<str[i][j];
    cout<<'\n';
  }
}
int main(void){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int n=0,N; cin>>N;
  string st;
  for(char a='A',b='a'; a<='Z'; a++,b++){
    idx[a]=++n;
    idx[b]=++n;
  }
  for(int i=0; i<N; i++){
    cin>>st;
    token(st,i);
  }
  mergeSort(0,N);
  print(N);
}
