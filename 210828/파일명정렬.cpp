#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> temp;
vector<string> answer;
int head(const string& str, const string& dst ){
    bool isStr=false, isDst=false;
    int n=min(str.size(),dst.size());
    char s,d;
    for(int i=0; i<n; i++){
        if((str[i]>='0'&&str[i]<='9')||(dst[i]>='0'&&dst[i]<='9')){
            if(str[i]<'0'||str[i]>'9'){isStr=true;break;}
            if(dst[i]<'0'||dst[i]>'9'){isDst=true;break;}
            break;
        }
        s=str[i]+((str[i]>='A'&&str[i]<='Z')?32:0);
        d=dst[i]+((dst[i]>='A'&&dst[i]<='Z')?32:0);
        if(s>d){isStr=true;break;}
        else if(s<d){isDst=true;break;}
    }

    if(isStr)return 1;
    else if(isDst)return -1;
    else return 0;
}
int number(const string& str, const string& dst ){
    int s=0, d=0, i=0,j=0;
    
    while(i<str.size()&&(str[i]<'0'||str[i]>'9'))i++;
    while(j<dst.size()&&(dst[j]<'0'||dst[j]>'9'))j++;
    
    for(; i<str.size(); i++){
        if(str[i]<'0'||str[i]>'9')break;
        s*=10;s+=str[i]-'0';
    }
    for(; j<dst.size(); j++){
        if(dst[j]<'0'||dst[j]>'9')break;
        d*=10;d+=dst[j]-'0';
    }

    if(s>d)return 1;
    else if(s<d)return -1;
    else return 0;
}
void merge(int l, int mid, int r){
    int ll=l, rr=mid, n=l;
    while(ll<mid&&rr<r){
        string str=answer[ll], dst=answer[rr];
        int t=head(str,dst);
        if(t==1){temp[n++]=answer[rr++];}
        else if(t==-1){temp[n++]=answer[ll++];}
        else{
            t=number(str,dst);
            if(t==1)temp[n++]=answer[rr++];
            else temp[n++]=answer[ll++];
        }
    }
    while(ll<mid){temp[n++]=answer[ll++];}
    while(rr<r){temp[n++]=answer[rr++];}
    
    for(int i=l; i<r; i++)answer[i]=temp[i];
}
void mergeSort(int l, int r){
    if(l+1<r){
    int mid=(l+r)/2;

    mergeSort(l,mid);
    mergeSort(mid,r);
    merge(l,mid,r);
    }
}
vector<string> solution(vector<string> files) {
    answer=files;
    temp.resize(files.size());
    mergeSort(0,answer.size());
    return answer;
}
