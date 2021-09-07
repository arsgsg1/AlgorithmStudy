#include <cstdio>
#include <algorithm>
using namespace std;
int arr[601];
int main(void){
  int N,l,h,t,ans=1<<30,s; scanf("%d",&N);
  for(int i=0; i<N; i++)scanf("%d",arr+i);
  sort(arr,arr+N);
  for(int i=0; i<N-1; i++)
    for(int j=i+1; j<N; j++){
      l=0;h=1;t=arr[i]+arr[j];
      while(l<h){
        if(l==i){
          l++;
        }
        if(h==j){
          if(j==N-1)h--;
          else h++;
        }
        s=arr[l]+arr[h];
        if(s>=t){
          if(h<N-1)h++;
          else l++;
        }
        else l++;
        ans=min(ans,abs(t-s));
      }
    }
  printf("%d",ans);
}
