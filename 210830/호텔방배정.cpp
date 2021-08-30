#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
const int MAX=200001;
struct Node{
    long long num;
    int cnt;
    Node(){Node(0,0);}
    Node(long long n, int c):num(n),cnt(c){}
};
unordered_map<long long , int > hm;
int par[MAX];
Node node[MAX];
int getpar(int a){
    return par[a]==-1?a:par[a]=getpar(par[a]);
}
void setUnion(int a, int b){
    a=getpar(a);
    b=getpar(b);
    if(a==b)return;
    par[a]=b;
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    int n=0;
    
    vector<long long> t = room_number;
    sort(t.begin(),t.end());
    t.erase(unique(t.begin(),t.end()),t.end());
    for(auto m : t){hm[m]=++n;node[n]=Node(m,0);}
    fill(par,par+n+1,-1);
    
    for(auto m : room_number){
        int curr=getpar(hm[m]);
        while(curr<n&&node[curr].cnt+node[curr].num==node[curr+1].num){
            setUnion(curr,curr+1);
            curr=getpar(curr);
        }
        answer.push_back(node[curr].num+node[curr].cnt++);
    }
    return answer;
}
