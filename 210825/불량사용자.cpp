#include <string>
#include <vector>

using namespace std;

bool matching(const string &str, const string &dst){
    if(str.size()!=dst.size())return false;
    for(int i=0 ;i<str.size(); i++){
        if(str[i]=='*')continue;
        if(str[i]!=dst[i])return false;
    }
    return true;
}

vector<string> banned,users;
bool used[1<<8];
int answer;

void recur(int n=0, int user=0){
    if(n==banned.size()){
        if(!used[user]){
            answer++;
            used[user]=true;
        }
        return;
    }
    for(int i=0; i<users.size(); i++)if(!(user&1<<i)){
        if(matching(banned[n],users[i])) recur(n+1,user|1<<i);
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    users=user_id; banned=banned_id;
    recur();
    return answer;
}
