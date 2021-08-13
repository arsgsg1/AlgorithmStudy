#include <cstdio>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long ll;
const int MAX=100001;
priority_queue<ll, vector<ll>> pq[MAX];
int main(void){
  unordered_map<string,int> hm;
  int Q, cnt=1, m,n,t; scanf("%d",&Q);
  ll sum=0;
  char str[17];
  for(int i=0; i<Q; i++){
    scanf("%d %s",&n,str);
    if(n==1){
      if(hm[str]==0)hm[str]=cnt++;
      scanf("%d",&m);
      for(int i=0; i<m; i++){
        scanf("%d",&t);
        pq[hm[str]].push(t);
      }
    }
    else{
      scanf("%d",&m);
      while(!pq[hm[str]].empty()&&m--){
        sum+=pq[hm[str]].top(); pq[hm[str]].pop();
      }
    }
  }
  printf("%lld",sum);
}
