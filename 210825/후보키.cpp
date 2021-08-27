#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
int col;
set<int> used;
vector<vector<string>> r;
int recur(int n, int m=0, int check=0){
    if(n==0){
        for(auto u: used)if(used.find(check&u)!=used.end())return 0;
        vector<string> v;
        for(auto rr : r){
            string str="";
            for(int i=0; i<col; i++)if(check&(1<<i))str+=rr[i];
            v.push_back(str);
        }
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        
        if(v.size()==r.size()){
            used.insert(check);
            return 1;
        }
        return 0;
    }
    int res=0;
    for(int i=m; i<col; i++)res+=recur(n-1,i+1,check|1<<i);
    return res;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    col=relation[0].size();
    r=relation;
    for(int i=1; i<=col; i++)answer+=recur(i);
    return answer;
}
