#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
int num[10][3][3]={
  {{1,1,1},{1,0,1},{0,1,0},},{{0,0,1},{0,0,1},{0,0,0},},
  {{0,1,1},{1,1,0},{0,1,0}},{{0,1,1},{0,1,1},{0,1,0}},
  {{1,0,1},{0,1,1},{0,0,0}},{{1,1,0},{0,1,1},{0,1,0}},
  {{1,1,0},{1,1,1,},{0,1,0}},{{0,1,1},{0,0,1},{0,0,0}},
  {{1,1,1},{1,1,1},{0,1,0}},{{1,1,1},{0,1,1},{0,1,0}}};
int change[10][10],N,K,P,x;
char X[10], T[10];
int _stoi(){
  int res=0;
  for(int i=0; i<K; i++){
    res*=10; res+=T[i]-'0';
  }
  return res;
}
ll recur(int n, int cnt=P){
  int number=_stoi();
  if(cnt<0)return 0;
  if(n>=K){
    if(x!=number&&number>0&&number<=N)return 1;
    return 0;
  }

  ll temp=0;
  for(int i=0; i<10; i++){
    int tcnt=change[T[n]-'0'][i];
    char tmp=T[n];
    T[n]=i+'0';
    temp+=recur(n+1,cnt-tcnt);
    T[n]=tmp;
  }

  return temp;
}
int main(void){
  scanf("%d %d %d %s",&N,&K,&P,X);
  size_t n=K-strlen(X);
  for(size_t i=0; i<n; i++)T[i]='0';
  for(size_t i=0; i<strlen(X); i++)T[i+n]=X[i];
  T[K]='\0';
  x=_stoi();

  for(int i=0; i<10; i++)
    for(int j=0; j<10; j++)if(i!=j){
      int temp=0;
      for(int k=0; k<3; k++)for(int l=0; l<3; l++)if(num[i][k][l]!=num[j][k][l])temp++;
      change[i][j]=temp;
    }
  printf("%lld",recur(0));
}
