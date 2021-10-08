#include <cstdio>
#include <vector>
using namespace std;
int K,N;
char ans[1<<8][1<<8];
vector<char> v;

void testing(int r, int c, int rl, int cl){
  for(int i=0; i<N; i++){
    if(v[i]=='U')
  }
}

int main(void){
  char ch;
  scanf("%d ",&K);
  for(int i=0; i<K; i++){
    scanf("%c ",&ch); v.push_back(ch);
  }
  scanf("%d ",&N);

  for(int i=0; i<(1<<K); i++)
    printf("%s\n",ans[i]);
}
