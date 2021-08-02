#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX=100002;
typedef long long ll;
typedef pair<int,int> p;
p d[MAX];
ll s[MAX];
int main(void){
  int N; scanf("%d",&N);
  for(int i=0; i<N; i++){
    int f,ss;
    scanf("%d %d",&f,&ss);
    d[i]={f,ss};
  }
  sort(d,d+N);
  for(int i=1; i<=N; i++)
    s[i]=s[i-1]+d[i-1].second;
  int l=0, h=N+1;
  while(l+1<h){
    int mid=(l+h)/2;
    if(s[mid]<s[N]-s[mid])l=mid;
    else h=mid;
  }
  printf("%d",d[l].first);
}
