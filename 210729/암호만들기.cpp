#include <iostream>
#include <algorithm>
using namespace std;
char arr[16], temp[16];
bool isMo[27];
int N,K;

void recur(int n, int curr, int j, int m){
  if(n==N){
    if(j<2||m<1)return;
    for(int i=0; i<N; i++)cout<<temp[i];
    cout<<'\n';
    return;
  }
  for(int i=curr; i<K; i++){
    temp[n]=arr[i];
    int jj=j, mm=m;
    if(isMo[arr[i]-'a'])mm++;
    else jj++;
    recur(n+1,i+1,jj,mm);
  }
}

int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin>>N>>K;
  for(int i=0; i<K; i++){
    cin>>arr[i];
    if(arr[i]=='a'||arr[i]=='e'||arr[i]=='i'||arr[i]=='o'||arr[i]=='u')
      isMo[arr[i]-'a']=true;
  }
  sort(arr,arr+K);
  recur(0,0,0,0);
}
