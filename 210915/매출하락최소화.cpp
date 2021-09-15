#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX=300001;
typedef long long ll;
const ll INF=1LL<<60;
vector<int> cost,adj[MAX];
ll dp[2][MAX];

ll recur(int curr, int isSelect){
    ll& res=dp[isSelect][curr];
    if(res!=-1)return res;
    res=isSelect==1?cost[curr]:0;
    bool isCom=false;
    ll t1,t2,temp=INF;
    for(auto next: adj[curr]){
        t1=recur(next,0); t2=recur(next,1);
        if(t1>t2){
            isCom=true;
            res+=t2;
        }
        else {
            res+=t1;
            temp=min(temp,t2-t1);
        }

    }
    if(isSelect==0&&!isCom&&temp!=INF)res+=temp;
    return res;
}

int solution(vector<int> sales, vector<vector<int>> links) {
    cost=sales;
    int answer = 0;
    for(int i=0; i<2; i++)fill(dp[i],dp[i]+MAX,-1);
    for(auto v : links)adj[v[0]-1].push_back(v[1]-1);
    
    return answer=(int)min(recur(0,0),recur(0,1));
}
