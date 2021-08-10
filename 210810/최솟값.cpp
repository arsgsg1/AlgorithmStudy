#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef unsigned int ui;
const int MAX=100001, K=19;
ui val[MAX][K];
int Log[MAX];

int main(void){
  int N,M;
  scanf("%d %d",&N,&M);
  memset(val,-1,sizeof(val));
  for(int i=0; i<N; i++)scanf("%d",&val[i][0]);

  for(int j=0; j<K; j++)
    for(int i=0; i+(1<<j)<N; i++)
        val[i][j+1]=min(val[i][j],val[i+(1<<j)][j]);
  for(int i=2; i<=N; i++)Log[i]=Log[i/2]+1;

  while(M--){
    int a,b; scanf("%d %d",&a,&b); a--;b--;
    if(a>b)swap(a,b);
    int n=Log[b-a+1];
    printf("%d\n",min(val[a][n],val[b-(1<<n)+1][n]));
  }    
}
