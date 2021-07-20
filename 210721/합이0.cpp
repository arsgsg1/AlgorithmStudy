#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX=10001;
int arr[MAX], N;
int bs(int val, int low){
  int l=low, h=N;
  while(l+1<h){
    int mid=(l+h)/2;
    if(arr[mid]>=val)h=mid;
    else l=mid;
  }
  return h;
}
int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin>>N;
  for(int i=0; i<N; i++)cin>>arr[i];
  sort(arr,arr+N);
  long long answer=0;
  int l=0,h;
  while(l<N){
    h=l+1;
    while(h<N){
      int temp=arr[l]+arr[h];
      int n1=bs(-temp,h), n2=bs(-temp+1,h);
      answer+=n2-n1;
      h++;
    }
    l++;
  }
  cout<<answer;
}

