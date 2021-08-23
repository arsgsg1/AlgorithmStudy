#include <string>
#include <vector>
#include <stack>

using namespace std;

char temp[1001];
string fix(const string &str){
    int i=0;
    for(;i<str.size(); i++){
        if(str[i]==')')temp[i]='(';
        else temp[i]=')';
    }
    temp[i]='\0';
    return temp;
}
bool isCorrect(const string &str){
    stack<char> s;
    for(int i=0; i<str.size(); i++){
        if(s.empty()&&str[i]==')')return false;
        if(str[i]=='(')s.push('(');
        else s.pop();
    }
    if(s.empty())return true;
    else return false;
}
string recur(const string& str){
    string res="";
    for(int i=0, j=0, k=0; i<str.size(); i++){
        if(str[i]==')')j++;
        else k++;
        if(j>0&&j==k){
            string temp=str.substr(0,i+1);
            if(isCorrect(temp)){
                res+=temp;
                res+=recur(str.substr(i+1));
            }
            else{
                res+="("+recur(str.substr(i+1))+")";
                res+=fix(temp.substr(1,temp.size()-2));
            }
            return res;
        }
    }
    return res;
}

string solution(string p) {
    string answer = "";
    return answer=recur(p);
}
