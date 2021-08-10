#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef unsigned int ui;
const int MAX=100001, K=19;
ui arr[MAX],val[MAX][K];

int main(void){
  int N,M;
  scanf("%d %d",&N,&M);
  memset(val,-1,sizeof(val));
  for(int i=0; i<N; i++)scanf("%d",arr+i);

  for(int i=0; i<N; i++)val[i][0]=min(arr[i],arr[i+1]);
  for(int j=0; j<K; j++)
    for(int i=0; i<N; i++)
        if(i+(1<<j)<N)val[i][j+1]=min(val[i][j],val[i+(1<<j)][j]);
  while(M--){
    int a,b; scanf("%d %d",&a,&b); a--;b--;
    if(a>b)swap(a,b);
    int n=b-a;
    ui ans=arr[a];
    for(int j=K-1; j>=0; j--){
      if(n&(1<<j)){
        ans=min(ans,val[a][j]);
        a+=(1<<j);
      }
    }
    printf("%d\n",ans);
  }    
}
