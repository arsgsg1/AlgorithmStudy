#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;
unordered_map<string,int> hm;
int num=1;
bool isSort[110];
vector<int> v[110];

void recur(int n, const vector<string> &vstr, int val, string str=""){
    if(n==4){
        if(hm[str]==0)hm[str]=num++;
        v[hm[str]].push_back(val);
        return;
    }
    recur(n+1,vstr,val,str+vstr[n]);
    recur(n+1,vstr,val,str+"-");
}

void token(const string& str){
    vector<string> vstr;
    for(int i=0, j=0; i<str.size(); i++){
        while(j<str.size()&&str[j]!=' ')j++;
        vstr.push_back(str.substr(i,j-i));
        i=j++;
    }
    int val=stoi(vstr.back());
    recur(0,vstr,val);
}

int getAns(const string& str){
    vector<string> vstr;
    for(int i=0, j=0; i<str.size(); i++){
        while(j<str.size()&&str[j]!=' ')j++;
        string temp=str.substr(i,j-i);
        i=j++;
        if(temp=="and")continue;
        vstr.push_back(temp);
    }
    string t=vstr[0]+vstr[1]+vstr[2]+vstr[3];
    if(!isSort[hm[t]]){
        sort(v[hm[t]].begin(),v[hm[t]].end());
        isSort[hm[t]]=true;
    }
    return v[hm[t]].size()-(upper_bound(v[hm[t]].begin(),v[hm[t]].end(),stoi(vstr[4])-1)-v[hm[t]].begin());
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    for(auto s : info)token(s);
    for(auto s : query)answer.push_back(getAns(s));
    return answer;
}
