#include <cstdio>
#include <cstring>
const int MAX=10001;
int alpha;
int word[MAX];

int main(void){
  int N,M; scanf("%d %d",&N,&M);
  char str[1001];
  for(int i=0; i<N; i++){
    scanf(" %s",str);
    size_t size=strlen(str);
    for(size_t j=0; j<size; j++){
      alpha|=(1<<(str[j]-'a'));
      word[i]|=(1<<(str[j]-'a'));
    }
  }
  int n,m; char c;
  while(M--){
    scanf("%d %c",&n,&c);
    if(n==1)alpha^=(1<<(c-'a'));
    else alpha|=(1<<(c-'a'));
    m=0;
    for(int i=0; i<N; i++)if((alpha&word[i])==word[i])m++;
    printf("%d\n",m);
  }
}
