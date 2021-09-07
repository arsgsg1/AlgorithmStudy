#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX=1001;
int dp[3][MAX][MAX], N;
int map[MAX][MAX];

int recur(int last, int cy, int cx){
  int &res=dp[last][cy][cx];
  if(res!=-1)return res;
  res=0;
  if(cy==N||cx==N)return res;
  int temp=0;
  temp=max(recur(last,cy+1,cx),recur(last,cy,cx+1));
  if(last==map[cy][cx]) temp=max({temp,recur((last+1)%3,cy+1,cx)+1,recur((last+1)%3,cy,cx+1)+1});
  res+=temp;
  return res;
}

int main(void){
  memset(dp,-1,sizeof(dp));
  scanf("%d",&N);
  for(int i=0; i<N; i++)for(int j=0; j<N; j++)scanf("%d",map[i]+j);
  printf("%d",recur(0,0,0));
}
