#include <cstdio>
#include <queue>
using namespace std;
const int MAX=1000001;
typedef pair<int,int> p;
int arr[MAX];
int main(void){
  int N,K; scanf("%d %d",&N,&K);
  int k=2*K-1;
  priority_queue<p, vector<p>> pq;
  for(int i=0; i<N; i++)scanf("%d ",arr+i);
  for(int i=0; i<k-1; i++)pq.push({arr[i],i});
  for(int i=k-1; i<N; i++){
    pq.push({arr[i],i});
    while(pq.top().second<=i-k)pq.pop();
    printf("%d ",pq.top().first);
  }
}
