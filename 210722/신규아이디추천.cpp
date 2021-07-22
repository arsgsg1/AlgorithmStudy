#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool charcheck(char& a){
    if((a>='a'&&a<='z')||a=='-'||a=='_'||a=='.'
      ||(a>='0'&&a<='9'))
        return true;
    return false;
}
string solution(string new_id) {
    string answer = "";
    char str[1001];
    for(int i=0; i<new_id.size(); i++)
        str[i]=new_id[i];
    str[new_id.size()]='\0';
    for(int i=0; i<strlen(str); i++)
        if(str[i]>='A'&&str[i]<='Z')
            str[i]+=32;
    char tmp[1001];
    int j=0;
    for(int i=0; i<strlen(str); i++)
        if(charcheck(str[i]))tmp[j++]=str[i];
    tmp[j]='\0';
    j=0;
    for(int i=0; i<strlen(tmp); i++){
        str[j++]=tmp[i];
        if(tmp[i]=='.'){
            int t=i+1;
            while(t<strlen(str)&&tmp[t]=='.')
                t++;
            i=t-1;
        }
    }
    str[j]='\0';
    j=0;
    for(int i=0; i<strlen(str);i++){
        if((i==0||i==strlen(str)-1)&&str[i]=='.')
            continue;
        tmp[j++]=str[i];
    }
    tmp[j]=0;
    if(strlen(tmp)<1){
        tmp[0]='a';
        tmp[1]='\0';
    }
    else if(strlen(tmp)>15){
        tmp[15]='\0';
        if(tmp[14]=='.')tmp[14]='\0';
    }
    answer=string(tmp);
    string ans=answer.substr(answer.size()-1,1);
    while(answer.size()<3)answer+=ans;
    return answer;
}
