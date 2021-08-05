#include <string>
#include <vector>
#include <iostream>

using namespace std;
const int INF=101;
typedef long long ll;
int ans=INF, M, N, K;
vector<int> w,d;

void recur(int n=0, int m=0, int midx=0, ll wall=0, int frd=0){
    if(ans<=n)return;
    if(m==M){
        ans=n;
        return;
    }
    for(int i=0; i<N; i++)if(!(frd&1<<i)){
        int t=midx;
        if(wall&(1LL<<t))return;
        ll temp=wall|(1LL<<t);
        temp|=(1LL<<(t+M));
        int cnt=1, v=d[i];
        while(!(temp&(1LL<<(t+1)))){
            v-=(w[t+1]-w[t]+K)%K;
            if(v<0)break;
            cnt++;
            t++;
        }
        recur(n+1,m+cnt,t+1,temp,frd|1<<i);
    }
}


int solution(int n, vector<int> weak, vector<int> dist) {
    M=weak.size(); N=dist.size(); K=n;
    w=weak; d=dist;
    for(auto n : weak)w.push_back(n);

    for(int i=0; i<M; i++)recur(0,0,i,0,0);
    return ans==INF?-1:ans;
}
