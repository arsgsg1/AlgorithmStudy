#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> p;
ll N,M,a,x,q;

vector<p> v;
vector<ll> s1,s2;
int main(void){
  scanf("%lld %lld ",&N,&M);
  v.resize(N);
  s1.resize(N+1,0);
  s2.resize(N+1,0);
  for(int i=0; i<N; i++){
    scanf("%lld %lld ",&a,&x);
    v[i]={x,a};
  }
  sort(v.begin(),v.end());
  for(int i=0; i<N; i++){
    x=v[i].first; a=v[i].second;
    s1[i+1]=(s1[i]+a);
    s2[i+1]=(s2[i]+a*x);
  }
  while(M--){
    scanf("%lld",&q);
    int l=-1, h=N;
    while(l+1<h){
      int mid=(l+h)/2;
      if(v[mid].first>=q)h=mid;
      else l=mid;
    }
    ll temp =s2[N]-2*s2[h]-q*s1[N]+q*2*s1[h];
    printf("%lld\n",temp);
  }
}
