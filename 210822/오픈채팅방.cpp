#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<string> tocken(string str){
    vector<string> res;
    for(int i=0,j=0; i<str.size(); i++){
        while(j<str.size()&&str[j]!=' ')j++;
        res.push_back(str.substr(i,j-i));
        i=j;
        j++;
    }
    return res;
}

bool compare(string s, string e){
    if(s.size()!=e.size())return false;
    for(int i=0; i<s.size(); i++)
        if(s[i]!=e[i])return false;
    return true;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string,string> name;
    vector<string> v[record.size()];
    for(int i=0; i<record.size(); i++){
        v[i]=tocken(record[i]);
        
        name[v[i][1]]=".";
    }
    
    for(int i=record.size()-1; i>=0; i--){
        
        if((compare(v[i][0],"Enter")||compare(v[i][0],"Change"))&&compare(name[v[i][1]],".")){

            name[v[i][1]]=v[i][2];
        }
    }
    for(int i=0; i<record.size(); i++){

        if(compare(v[i][0],"Enter")){
            answer.push_back(name[v[i][1]]+"님이 들어왔습니다.");
        }
        else if(compare(v[i][0],"Leave")){
            answer.push_back(name[v[i][1]]+"님이 나갔습니다.");
        }
    }
    return answer;
}
