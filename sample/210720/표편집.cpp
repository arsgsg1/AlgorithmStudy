#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAX=1<<20;
int N, now;
bool _remove[MAX];
int seg[MAX];
stack<int> del;

void update(int n, int val){
    while(n<N){
        seg[n]+=val;
        n+=n&-n;
    }
}
int sum(int n){
    int ans=0;
    while(n){
        ans+=seg[n];
        n-=n&-n;
    }
    return ans;
}


int down(int idx, int cnt){
    int l=0, h=N;
    while(l+1<h){
        int mid=(l+h)/2;
        if(sum(mid)-sum(idx)>=cnt)h=mid;
        else l=mid;
    }
    return h;
}
int up(int idx, int cnt){
    int l=0, h=N;
    while(l+1<h){
        int mid=(l+h)/2;
        if(sum(idx)-sum(mid)>cnt)l=mid;
        else h=mid;
    }
    return h;
}

int doDelete(int idx){
    _remove[idx]=false;
    update(idx,-1);
    del.push(idx);
    int l=0, h=N;
    while(l+1<h){
        int mid=(l+h)/2;
        if(sum(mid)-sum(idx)>=1)h=mid;
        else l=mid;
    }
    if(h<N)return h;
    l=0; h=N;
    while(l+1<h){
        int mid=(l+h)/2;
        if(sum(idx)-sum(mid)>0)l=mid;
        else h=mid;
    }
    return h;
}
void rollback(void){
    _remove[del.top()]=true;
    update(del.top(),1);
    del.pop();
}
int sti(const string& str){
    int n=0;
    for(int i=0; i<str.size(); i++){
        n*=10; n+=str[i]-'0';
    }
    return n;
}
string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    N=n+2;now=k+1;
    for(int i=1; i<=n; i++){
        update(i,1);
        _remove[i]=true;
    }
    for(auto str : cmd){
        if(str[0]=='C') now=doDelete(now);
        else if(str[0]=='D') now=down(now,sti(str.substr(2)));
        else if(str[0]=='U') now=up(now,sti(str.substr(2)));
        else rollback();
    }
    for(int i=1; i<=n; i++){
        if(_remove[i])answer+="O";
        else answer+="X";
    }
    return answer;
}
