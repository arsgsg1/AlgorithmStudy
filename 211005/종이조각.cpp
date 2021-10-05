#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[2][1<<16], map[4][4];
int N,M;

int recur(int isRight, int check){
  int& res = dp[isRight][check];
  if(res!=-1)return res;
  res=0;
  
  int temp=check, t=0, tt=0;
  bool flag=isRight==1?true:false;
  for(int i=0; i<N; i++)for(int j=0; j<M; j++)if(!(check&(1<<(j+M*i)))){
    while(flag&&j<M&&!(temp&1<<(j+M*i))){
      temp|=(1<<(j+M*i));
      tt*=10;
      tt+=map[i][j];
      t=max({t,recur(0,temp)+tt,recur(1,temp)+tt});
      j++;
    }
    temp=check;
    tt=0;
    while(!flag&&i<N&&!(temp&1<<(j+M*i))){
      temp|=(1<<(j+M*i));
      tt*=10;
      tt+=map[i][j];
      t=max({t,recur(0,temp)+tt,recur(1,temp)+tt});
      i++;
    }
    res+=t;
    return res;
  }
  return res;
}

int main(void){
  char str[5];
  memset(dp,-1,sizeof(dp));
  scanf("%d %d ",&N,&M);
  for(int i=0; i<N; i++){
    scanf("%s ",str);
    for(int j=0; j<M; j++)map[i][j]=str[j]-'0';
  }
  printf("%d",max(recur(1,0),recur(0,0)));
}
