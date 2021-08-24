#include <string>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;
unordered_map<char,int> opp;
stack<long long> num;
stack<char> op;
vector<int> n;
vector<char> o;
long long answer=0;
int strtoint(const string& str){
    int res=0;
    for(int i=0; i<str.size(); i++){
        res*=10;
        res+=str[i]-'0';
    }
    return res;
}
long long cal(){
    long long res=0;
    long long n1,n2;
    char c;
    n1=num.top(); num.pop();
    n2=num.top(); num.pop();
    c=op.top(); op.pop();
    if(c=='*')res=n2*n1;
    else if(c=='+'||(c=='-'&&!op.empty()&&op.top()=='-')) res=n2+n1;
    else if(c=='-')res=n2-n1;
    return res;
}
void getans(){
    num.push(n[0]);
    
    for(int i=1; i<n.size(); i++){
        while(!op.empty()&&opp[op.top()]>opp[o[i-1]])num.push(cal());
        
        op.push(o[i-1]);
        num.push(n[i]);
    }
    while(!op.empty())num.push(cal());
    

    answer=max(answer,abs(num.top()));
    num.pop();
}
string str="+-*";
void recur(int n=0, int m=0, int check=0){
    if(n==3){
        getans();
        return;
    }
    for(int i=0; i<3; i++)if(!(check&1<<i)){
        opp[str[i]]=m;
        recur(n+1,m+1,check|1<<i);
    }
    
}

long long solution(string e) {

    for(int i=0; i<e.size(); i++){
        if(e[i]<='9'&&e[i]>='0'){
            int j=i;
            while(j<e.size()&&e[j]>='0'&&e[j]<='9')j++;
            n.push_back(strtoint(e.substr(i,j-i)));
            i=j-1;
        }
        else o.push_back(e[i]);
    }
    
    recur();
    
    return answer;
}
