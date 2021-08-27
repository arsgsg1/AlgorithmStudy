#include <string>
#include <vector>
#include <queue>
#define int long long
using namespace std;
typedef pair<int,bool> pib;
const int MAX=360002;
int num[MAX];
int tt1(const string &str){
    string h=str.substr(0,2), m=str.substr(3,2), s=str.substr(6,2);
    int hh=0,mm=0,ss=0;
    for(int i=0; i<2; i++){
        hh*=10; mm*=10; ss*=10;
        hh+=h[i]-'0'; mm+=m[i]-'0'; ss+=s[i]-'0';
    }
    return hh*60*60+mm*60+ss;
}
string tt2(int n){
    int s=n%60;n/=60;
    int m=n%60;n/=60;
    int h=n;
    char str[9]={'0','0',':','0','0',':','0','0','\0'};
    for(int i=1; i>=0; i--){
        str[6+i]=s%10+'0';str[3+i]=m%10+'0';str[0+i]=h%10+'0';
        s/=10;m/=10;h/=10;
    }
    return string(str);
}
int getans(int& advnum, int& playnum){
    int curr=0,prev=0;
    int cmax=0;
    for(int i=0; i<advnum; i++){
        curr+=num[i];
        cmax+=curr;
    }
    int ans=0, temp=cmax;
    for(int i=advnum,j=0; i<playnum; i++){
        curr+=num[i];
        prev+=num[j++];
        temp+=(curr-prev);
        if(temp>cmax){
            cmax=temp;
            ans=j;
        }
    }
    return ans;
}
string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    int advnum=tt1(adv_time);
    int playnum=tt1(play_time);
    
    for(auto str : logs){
        int s=tt1(str.substr(0,8));
        int e=tt1(str.substr(9,8));
        num[s]++; num[e]--;
    }
    return tt2(getans(advnum,playnum));
}
