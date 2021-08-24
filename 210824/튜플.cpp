#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
unordered_map<int,int> hm;

int strtoint(const string& str){
    int res=0;
    for(int i=0; i<str.size(); i++){
        res*=10;res+=str[i]-'0';
    }
    return res;
}
void grouping(const string& str){
    vector<int> t;
    int n=0;
    for(int i=0; i<str.size(); i++)if(str[i]!=','){
        n++;
        int j=i+1;
        while(j<str.size()&&str[j]>='0'&&str[j]<='9')j++;
        t.push_back(strtoint(str.substr(i,j-i)));
        i=j-1;
    }
    for(auto temp : t)
        if(hm[temp]==0||hm[temp]>n)hm[temp]=n;
}
vector<int> solution(string s) {
    vector<int> answer;
    for(int i=1; i<s.size(); i++)if(s[i]=='{'){
        int j=i+1;
        while(j<s.size()&&s[j]!='}')j++;
        grouping(s.substr(i+1,j-i-1));
    }
    answer.resize(hm.size());
    for(auto n : hm)answer[n.second-1]=n.first;
    return answer;
}
