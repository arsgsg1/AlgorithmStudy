#include <string>
#include <vector>

using namespace std;
const long long INF=1LL<<40;
long long dist[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    long long answer = INF;
    
    for(int i=1 ;i<=n; i++)for(int j=1; j<=n; j++)dist[i][j]=(i==j?0:INF);
    for(auto v : fares){
        dist[v[0]][v[1]]=v[2];
        dist[v[1]][v[0]]=v[2];
    }
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                
    for(int i=1; i<=n; i++)
        answer=min(answer,dist[s][i]+dist[i][a]+dist[i][b]);
    return answer;
}
