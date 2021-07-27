#include <iostream>
using namespace std;

bool r[16],c[16],a[32],b[32];
int N;
long long ans;

void recur(int i){
  if(i==N){
    ans++;
    return;
  }
    for(int j=0; j<N; j++){
      if(r[i]||c[j]||a[j+i]||b[N-j+i])continue;
        r[i]=c[j]=a[j+i]=b[N-j+i]=true;
        recur(i+1);
        r[i]=c[j]=a[i+j]=b[N-j+i]=false;
      }
}
int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin>>N;
  recur(0);
  cout<<ans;
}

