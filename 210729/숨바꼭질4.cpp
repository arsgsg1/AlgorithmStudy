#include <iostream>
#include <queue>
using namespace std;
const int MAX=100001;
int step[MAX], rule[3]={1,-1,2};
bool visit[MAX];

bool tracking(int n, int k, int cnt, int ans){
  if(n<0||n>=MAX||step[n]!=ans-cnt)return false;
  if(n==k&&cnt==ans){
    cout<<n<<" ";
    return true;
  }
  if(tracking(n-1,k,cnt+1,ans)){cout<<n<<" "; return true;}
  if(tracking(n+1,k,cnt+1,ans)){cout<<n<<" "; return true;}
  if(tracking(n/2,k,cnt+1,ans)){cout<<n<<" "; return true;}
  return false;
}

int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int N,K; cin>>N>>K;
  if(N>=K){
    cout<<N-K<<'\n';
    for(int i=N; i>=K; i--)cout<<i<<" ";
  }
  else{
    queue<int> q;
    q.push(N);
    visit[N]=true;
    while(!q.empty()){
      int curr=q.front(); q.pop();
      if(curr==K)break;
      for(int i=0; i<3; i++){
        int temp;
        if(i==2)temp=curr*rule[i];
        else temp=curr+rule[i];
        if(temp<0||temp>=MAX)continue;
        if(!visit[temp]){
          visit[temp]=true;
          step[temp]=step[curr]+1;
          q.push(temp);
        }
      }
    }
    cout<<step[K]<<'\n';
    tracking(K,N,0,step[K]);
  }
}

