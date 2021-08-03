#include <cstdio>
#include <set>
#define RAN (ty<0||tx<0||ty>=N||tx>=N)
using namespace std;
struct SS{
  int n,t;
  SS(){SS(0,0);}
  SS(int n, int t){this->n=n;this->t=t;}
};
struct SHARK{
  int y, x, d;
  SHARK(){SHARK(0,0,0);}
  SHARK(int y, int x, int d){this->y=y; this->x=x; this->d=d;}
};
const int MAX=401;
int dir[MAX][5][5], sn=0, t, N,M,K;
int dy[5]={0,-1,1,0,0},dx[5]={0,0,0,-1,1};
int isDead[MAX], dn;
SS ss[21][21];
SHARK shark[MAX];
set<int> shset;
bool isMove[MAX];

void delShark(){
  for(int i=0; i<dn ;i++)if(shset.find(isDead[i])!=shset.end()){
    shset.erase(isDead[i]);
    sn--;
  }
  dn=0;
}
bool canMove(int n, int d, int y, int x){
  bool flag=false;
  for(int i=1; i<=4; i++)if(!flag){
    int ty=y+dy[dir[n][d][i]], tx=x+dx[dir[n][d][i]];
    if(RAN)continue;
    if(t-ss[ty][tx].t>K){
      ss[ty][tx].t=t;
      ss[ty][tx].n=n;
      shark[n]=SHARK(ty,tx,dir[n][d][i]);
      flag=true;
    }
    else if(ss[ty][tx].t==t){
      flag=true;
      if(ss[ty][tx].n>n){
        ss[ty][tx].t=t;
        ss[ty][tx].n=n;
        shark[n]=SHARK(ty,tx,dir[n][d][i]);
        isDead[dn++]=ss[ty][tx].n;
      }
      else isDead[dn++]=n;
    }
  }
  return flag;
}
void move2(int n, int d, int y, int x){
  for(int i=1; i<=4; i++){
    int ty=y+dy[dir[n][d][i]], tx=x+dx[dir[n][d][i]];
    if(RAN||ss[ty][tx].n!=n)continue;
    ss[ty][tx].t=t;
    shark[n]=SHARK(ty,tx,dir[n][d][i]);
    return;
  }
}
void move(){
  for(auto n : shset){
    int y=shark[n].y, x=shark[n].x, d=shark[n].d;
    isMove[n]=canMove(n,d,y,x);
  }
  for(auto n : shset){
    int y=shark[n].y, x=shark[n].x, d=shark[n].d;
    if(!isMove[n])move2(n,d,y,x);
  }
  delShark();
}

int main(void){
  scanf("%d %d %d",&N,&M,&K);
  for(int i=0; i<N; i++)for(int j=0; j<N; j++)ss[i][j]=SS(M+1,-K);
  int a;
  for(int i=0; i<N; i++)for(int j=0; j<N; j++){
    scanf("%d",&a);
    if(a>0) {shark[a]=SHARK(i,j,0);sn++;}
  }
  for(int i=1; i<=M; i++){
    scanf("%d",&a);
    shark[i].d=a;
    shset.insert(i);
  }
  for(int i=1; i<=M; i++)
    for(int j=1; j<=4; j++)
      for(int k=1; k<=4; k++)scanf("%d",&dir[i][j][k]);
  
  for(auto s : shset){
    int y=shark[s].y, x=shark[s].x;
    ss[y][x].n=s;
    ss[y][x].t=t;
  }
  while(sn>1){
    if(++t>1000)break;
    move();
  }
  printf("%d",t>1000?-1:t);
}
