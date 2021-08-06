#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX=100001;
int s[MAX];

int main(void){
  int N,S; scanf("%d %d",&N,&S);
  int a;
  for(int i=1; i<=N; i++){
    scanf("%d",&a);
    s[i]=s[i-1]+a;
  }
  int ans=MAX;
  int l=0, h=1;
  bool flag=false;
  while(l<=N){
    if(h<=N&&s[h]-s[l]<S)h++;
    else {
      if(h<=N&&s[h]-s[l]>=S){
        if(ans>h-l){
          flag=true;
          ans=h-l;
        }
      }
      l++;
    }
  }
  printf("%d",flag?ans:0);
}
