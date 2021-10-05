#include <cstdio>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
const int MAX=200010;
const long long X=1LL<<40, Y=1LL<<41;
unordered_map<double, int> hm[4];
int n;

int gcd(int a, int b){
  if(b==0)return a;
  return gcd(b,a%b);
}

int getRange(int y, int x){
  if(y>=0&&x>=0)return 0;
  else if(y>=0) return 1;
  else if(x>=0) return 3;
  else return 2;
}
vector<long long> v[MAX];
long long d[MAX];
int main(void){
  int N,M;
  long long x,y,dd; 
  scanf("%d %d ",&N,&M);
  for(int i=0; i<N; i++){
    scanf("%lld %lld %lld",&x,&y,&dd);
    int r= getRange(y,x);
    y=y<0?-y:y;
    x=x<0?-x:x;
    int g = gcd(x,y);
    double t = ((double)(y/g))/(x/g);
    if(x>y)t=-t;
    if(x==0)t=X;
    else if(y==0)t=Y;
    if(hm[r][t]==0)hm[r][t]=++n;
    v[hm[r][t]].push_back(dd);
  }
  for(int i=1; i<=n; i++)sort(v[i].begin(),v[i].end());

  int ans = N;
  for(int i=0; i<M; i++){
    scanf("%lld %lld %lld",&x,&y,&dd);
    int r= getRange(y,x);
    y=y<0?-y:y;
    x=x<0?-x:x;
    int g =gcd(x,y);
    double t = ((double)(y/g))/(x/g);
    if(x>y)t=-t;
    if(x==0)t=X;
    else if(y==0)t=Y;
    d[hm[r][t]]+=dd;
    int temp = upper_bound(v[hm[r][t]].begin(),v[hm[r][t]].end(),d[hm[r][t]])-v[hm[r][t]].begin();
    int ttemp = lower_bound(v[hm[r][t]].begin(),v[hm[r][t]].end(),d[hm[r][t]]-dd)-v[hm[r][t]].begin();
    ans-=(temp-ttemp);
    printf("%d\n",ans);
  }
}
