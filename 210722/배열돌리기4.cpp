#include <iostream>
using namespace std;
const int INF=1<<29;
int dr[4]={0,1,0,-1}, dc[4]={1,0,-1,0};
int arr[51][51], v[10][3], N,M,K;

void rotate(int r, int c, int s){
  while(s){
    int temp=arr[r][c], S=s*2;
    for(int i=0; i<4; i++){
      for(int j=1; j<=S; j++){
        int rr=r+j*dr[i], cc=c+j*dc[i];
        int temp2=arr[rr][cc];
        arr[rr][cc]=temp;
        temp=temp2;
      }
      c+=S*dc[i];
      r+=S*dr[i];
    }
    s--;
    r++;c++;
  }
}
int ans=INF;
void getans(){
  for(int i=0; i<N; i++){
    int temp=0;
    for(int j=0; j<M; j++)temp+=arr[i][j];
    ans=min(ans,temp);
  }
}
void recur(int n, int check){
  if(n==K){
    getans();
    return;
  }
  int tarr[51][51];

  for(int i=0; i<K; i++)if(!(check&1<<i)){
    for(int i=0; i<N; i++)for(int j=0; j<M; j++)tarr[i][j]=arr[i][j];
    rotate(v[i][0],v[i][1],v[i][2]);
    recur(n+1,check|1<<i);
    for(int i=0; i<N; i++)for(int j=0; j<M; j++)arr[i][j]=tarr[i][j];
  }
}

int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin>>N>>M>>K;
  for(int i=0; i<N; i++)for(int j=0; j<M; j++)cin>>arr[i][j];
  for(int i=0; i<K; i++){
    int r,c,s; cin>>r>>c>>s; r--;c--;
    v[i][0]=r-s;
    v[i][1]=c-s;
    v[i][2]=s;
  }
  recur(0,0);
  cout<<ans;
}
