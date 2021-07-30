#include <iostream>
using namespace std;
const int INF=1<<29;
int N,M,ans=INF;
int dist[101][14], map[51][51];
int minval[105],home[101], hn, chicken[14], cn;

void recur(int n=0, int idx=0, int check=0){
  if(n==M){
    int temp=0;
    for(int i=0; i<hn; i++)temp+=minval[i];
    ans=min(ans,temp);
    return;
  }
  for(int i=idx; i<cn; i++)if(!(check&1<<i)){
    int temp[101];
    for(int j=0; j<hn; j++){
      temp[j]=minval[j];
      minval[j]=min(minval[j],dist[j][i]);
    }
    recur(n+1,i+1,check|1<<i);
    for(int j=0; j<hn; j++)
      minval[j]=temp[j];
  }
}

int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin>>N>>M;
  fill(minval,minval+2*N+1,INF);
  for(int i=0; i<N; i++)for(int j=0; j<N; j++){
    cin>>map[i][j];
    if(map[i][j]==2){
      chicken[cn++]=i*50+j;
    }
    else if(map[i][j]==1){
      home[hn++]=i*50+j;
    }
  }
  for(int i=0; i<hn; i++){
    int hy=home[i]/50, hx=home[i]%50;
    for(int j=0; j<cn; j++){
      int cy=chicken[j]/50, cx=chicken[j]%50;
      dist[i][j]=abs(cy-hy)+abs(cx-hx);
    }
  }
  recur();
  cout<<ans;
}
