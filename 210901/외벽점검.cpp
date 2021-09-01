#include <string>
#include <vector>

using namespace std;
typedef long long ll;
vector<int> w,d;
int N;
int recur(int n, ll check=0, int fr=0){
    if(check&1LL<<n)return 0;
    int res=11;
    for(int i=0; i<d.size(); i++)if(!(fr&1<<i)){
        ll temp=check|1LL<<n;
        temp|=1LL<<(n+N);
        int tn=n;
        int t=w[tn+1]-w[tn], f=d[i];
        while(t<=f&&!(temp&1LL<<(tn+1))){
            f-=t;
            tn++;
            temp|=1LL<<tn;
            temp|=1LL<<(tn+N);
            t=w[tn+1]-w[tn];
        }
        res=min(res,recur(tn+1,temp,fr|1<<i)+1);
    }
    return res;
    
}

int solution(int n, vector<int> weak, vector<int> dist) {
    w=weak;d=dist;N=weak.size();
    for(auto a : weak)w.push_back(a+n);
    int answer = 11;
    
    for(int i=0; i<weak.size(); i++)answer=min(answer,recur(i));
    return answer==11?-1:answer;
}
