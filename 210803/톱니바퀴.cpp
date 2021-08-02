#include <cstdio>
using namespace std;
char wheel[4][9];
int right[4];
bool isTurn[4];

void checkRot(int n){
  for(int next=n+1; next<4; next++){
    int curr=next-1;
    int left=(right[next]+4)%8;
    if(wheel[next][left]!=wheel[curr][right[curr]])isTurn[next]=true;
    else break;
  }
  for(int next=n-1; next>=0; next--){
    int curr=next+1;
    int left=(right[curr]+4)%8;
    if(wheel[curr][left]!=wheel[next][right[next]]) isTurn[next]=true;
    else break;
  }
}

void turn(int n, int d){
  right[n]=(right[n]-d+8)%8;
  int pd=d;
  for(int next=n+1; next<4; next++)if(isTurn[next]){
    right[next]=(right[next]+pd+8)%8;
    pd=-pd;
  }
  pd=d;
  for(int next=n-1; next>=0; next--)if(isTurn[next]){
    right[next]=(right[next]+pd+8)%8;
    pd=-pd;
  }
  for(int i=0; i<4; i++)isTurn[i]=false;
}

int main(void){
  for(int i=0; i<4; i++){
    scanf("%s",wheel[i]);
    right[i]=2;
  }
  
  int N,n,dir; scanf("%d",&N);
  while(N--){
    scanf("%d %d",&n,&dir);
    n--;
    checkRot(n);
    turn(n,dir);

  }

  int ans=0, score=1;
  for(int i=0; i<4; i++){
    int idx=(right[i]-2+8)%8;
    if(wheel[i][idx]-'0')ans+=score;
    score*=2;
  }
  printf("%d",ans);
}
