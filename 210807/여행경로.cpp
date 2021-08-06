#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int MAX=10001;
unordered_map<string,int> hm;
vector<pair<string,bool>> adj[MAX];
int cnt, N;
bool dfs(int nn, const string& src, vector<string>& ans){
    if(nn==N)return true;
    int curr=hm[src];
    for(auto &n : adj[curr]){
        string dst=n.first;
        bool &isUse =n.second;
        if(isUse)continue;
        isUse=true;
        if(dfs(nn+1,dst,ans)){ans.push_back(dst); return true;}
        isUse=false;
    }
    
    return false;
}

vector<string> solution(vector<vector<string>> t) {
    vector<string> answer,ans;
    N=1+t.size();
    for(auto v : t){
        string src=v[0], dst=v[1];
        if(hm[src]==0)hm[src]=++cnt;
        if(hm[dst]==0)hm[dst]=++cnt;
        adj[hm[src]].push_back({dst,false});
    }
    for(int i=1; i<=cnt; i++)sort(adj[i].begin(),adj[i].end());
    if(dfs(1,"ICN",ans))ans.push_back("ICN");
    for(int i=N-1; i>=0; i--)answer.push_back(ans[i]);
    return answer;
}
