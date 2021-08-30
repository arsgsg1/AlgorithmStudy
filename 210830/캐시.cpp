#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
typedef pair<int,string> p;
char temp[23];
string lowerCase(const string& str){
    int i;
    for(i=0; i<str.size(); i++)
        temp[i]=((str[i]>='A'&&str[i]<='Z')?str[i]+32:str[i]);
    temp[i]='\0';
    return (string)temp;
}
int solution(int cacheSize, vector<string> cities) {
    int answer = 0, curr=0;
    string str;
    unordered_map<string,int> hm;
    priority_queue<p,vector<p>,greater<p>> pq;
    for (int i=0; i<cities.size(); i++){
        str=lowerCase(cities[i]);
        while(!pq.empty()&&curr>cacheSize){
            hm[pq.top().second]--;
            if(hm[pq.top().second]==0)curr--;
            pq.pop();
        }
        hm[str]++;
        if(hm[str]==1){curr++;answer+=5;}
        else answer+=1;
        pq.push({i,str});
    }
    return answer;
}
