#include <cstdio>
#include <cstring>
using namespace std;

int N;
char arr[53];
bool recur(bool isPrevC, bool isPpC, bool isPrevB, int n, int a, int b, int c){
  if((b>1&&a+c<b-1)||(c>1&&a+b<2*(c-1)))return false;
  if(n==N-1){
    arr[n]=(a>0?'A':(b>0?'B':(c>0?'C':'\0')));
    return true;
  }
  if(!isPrevC&&!isPpC&&c>0){
    if(recur(1,isPrevC,0,n+1,a,b,c-1)){arr[n]='C'; return true;}
  }
  if(!isPrevB&&b>0){
    if(recur(0,isPrevC,1,n+1,a,b-1,c)){arr[n]='B'; return true;}
  }
  if(a>0){
    if(recur(0,isPrevC,0,n+1,a-1,b,c)){arr[n]='A'; return true;}
  }
  return false;
}

int main(void){
  scanf("%s",arr);
  int a=0,b=0,c=0;
  for(size_t i=0; i<strlen(arr); i++){
    if(arr[i]=='A')a++;
    else if(arr[i]=='B')b++;
    else c++;
  }
  N=a+b+c;
  if(recur(0,0,0,0,a,b,c))printf("%s",arr);
  else printf("-1");
}
