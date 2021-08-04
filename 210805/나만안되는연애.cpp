#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int MAX=1000;
int par[MAX], ans;
bool isMan[MAX];
struct Edge{
  int s,e,c;
  Edge(){Edge(0,0,0);}
  Edge(int a, int b, int cc):s(a),e(b),c(cc){}
  bool operator>(const Edge n)const{
    if(c==n.c&&e==n.e)return s>n.s;
    else if(c==n.c) return e>n.e;
    else return c>n.c;
  }
};

int getpar(int a){
  if(par[a]<0)return a;
  return par[a]=getpar(par[a]);
}

void setUnion(int a, int b, int c){
  a=getpar(a);
  b=getpar(b);
  if(a==b)return;
  if(par[a]>par[b])swap(a,b);
  par[a]+=par[b];
  par[b]=a;
  ans+=c;
  return;
}

int main(void){
  int N,M,s,e,c; scanf("%d %d",&N,&M);
  char ch;
  memset(par,-1,sizeof(par));
  priority_queue<Edge,vector<Edge>,greater<Edge>> pq;
  for(int i=0; i<N; i++){
    scanf(" %c",&ch);
    if(ch=='M')isMan[i]=true;
  }
  for(int i=0; i<M; i++){
    scanf("%d %d %d",&s,&e,&c);
    pq.push(Edge(s-1,e-1,c));
  }
  while(!pq.empty()){
    Edge edge=pq.top(); pq.pop();
    int s=edge.s, e=edge.e, c=edge.c;
    if(isMan[s]==isMan[e])continue;
    setUnion(s,e,c);
  }
  printf("%d",N==-par[getpar(0)]?ans:-1);
}
