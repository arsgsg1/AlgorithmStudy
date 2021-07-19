#include <string>
#include <vector>
#include <queue>
#define RAN (ty<0||tx<0||ty>=5||tx>=5)
using namespace std;
typedef pair<int,pair<int,int>> p;
int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
char map[5][5];
int dist[5][5][26];
bool visit[5][5][26];

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(auto v : places){
        queue<p> q;
        int n=0;
        for(int i=0; i<5; i++)for(int j=0; j<5; j++)for(int k=0; k<26; k++){
            visit[i][j][k]=false;
            dist[i][j][k]=0;
        }
        for(int i=0; i<5; i++)for(int j=0; j<5; j++){
            map[i][j]=v[i][j];
            if(map[i][j]=='P'){
                q.push({n++,{i,j}});
            }
        }
        bool flag=false;
        while(!q.empty()){
            int n=q.front().first;
            int y=q.front().second.first, x=q.front().second.second;
            q.pop();
            visit[y][x][n]=true;
            if(dist[y][x][n]>=2)continue;
            for(int i=0; i<4; i++){
                int ty=y+dy[i], tx=x+dx[i];
                if(RAN||map[ty][tx]=='X'||visit[ty][tx][n])continue;
                if(map[ty][tx]=='P'&&dist[y][x][n]<=1)flag=true;
                dist[ty][tx][n]=dist[y][x][n]+1;
                q.push({n,{ty,tx}});
            }
        }
        if(flag)answer.push_back(0);
        else answer.push_back(1);
    }
    return answer;
}
