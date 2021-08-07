#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX=100001;
bool isFull[MAX];
int par[MAX], flight[MAX];

int getpar(int a){
  if(par[a]<0)return a;
  return par[a]=getpar(par[a]);
}

void setUnion(int a, int b){
  a=getpar(a);
  b=getpar(b);
  par[b]=a;
}

int main(void){
  int G,P; scanf("%d %d",&G,&P);
  memset(par,-1,sizeof(par));
  for(int i=0; i<P; i++)scanf("%d",flight+i);
  for(int i=0; i<P; i++){
    int n=getpar(flight[i]);
    if(n>0){
      isFull[n]=true;
      setUnion(n-1,n);
    }
    else break;
  }
  int ans=0;
  for(int i=1; i<=G; i++)if(isFull[i])ans++;
  printf("%d",ans);
}
