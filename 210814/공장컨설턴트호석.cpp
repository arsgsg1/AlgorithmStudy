#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
const int MAX=100001;
int arr[MAX];
int N,M;

bool check(int k){
  priority_queue<int,vector<int>,greater<int>> pq;
  int temp;
  for(int i=1; i<k; i++)pq.push(0);
  pq.push(arr[0]);
  for(int i=1; i<N; i++){
    temp=arr[i];
    if(temp+pq.top()<=M){
      temp+=pq.top();
      pq.pop();
    }
    pq.push(temp);
  }
  if(pq.size()>k)return false;
  return true;
}

int main(void){
  scanf("%d %d",&N,&M);
  for(int i=0; i<N; i++)scanf("%d",arr+i);
  
  int l=-1, h=MAX;
  while(l+1<h){
    int mid=(l+h)/2;
    if(check(mid))h=mid;
    else l=mid;
  }
  printf("%d",h);
}
