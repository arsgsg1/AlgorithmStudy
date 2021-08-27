#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    vector<string> t=gems;
    sort(t.begin(),t.end());
    t.erase(unique(t.begin(),t.end()),t.end());
    
    unordered_map<string,int> hm;
    int n=0, l=0,h=0;
    while(h<gems.size()&&n<t.size()){
        hm[gems[h]]++;
        if(hm[gems[h++]]==1)n++;
    }
    answer={1,h};
    int range=h;
    while(l<gems.size()){
        while(n==t.size()&&l<h){
            hm[gems[l]]--;
            if(hm[gems[l]]==0){
                n--;
                if(range>h-l){
                    range=h-l;
                    answer={l+1,h};
                }
            }
            l++;
        }
        if(h<gems.size()){
            hm[gems[h]]++;
            if(hm[gems[h++]]==1)n++;
        }
        else l++;
    }
    
    return answer;
}
