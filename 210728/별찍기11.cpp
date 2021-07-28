#include <iostream>
using namespace std;
const int MAX=3*(1<<10);
char star[3][5]={
  {' ',' ','*',' ',' '},
  {' ','*',' ','*',' '},
  {'*','*','*','*','*'}
};
char map[MAX][MAX*2-1];
int N;
void divide(int r, int c, int n, int k){
  if(k==0){
    for(int i=0; i<3; i++)for(int j=0; j<5; j++)
      map[r+i][c+j]=star[i][j];
    return;
  }
  divide(r,c+n,n/2,k-1);
  divide(r+n,c,n/2,k-1);
  divide(r+n,c+2*n,n/2,k-1);
}

int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin>>N;
  int cnt=-1, temp=N;
  while(temp%3==0){
    temp/=2;
    cnt++;
  }
  for(int i=0; i<N; i++)for(int j=0; j<N*2-1; j++)map[i][j]=' ';
  divide(0,0,N/2,cnt);
  for(int i=0; i<N; i++){
    for(int j=0; j<N*2-1; j++)cout<<map[i][j];
    cout<<'\n';
  }
}
