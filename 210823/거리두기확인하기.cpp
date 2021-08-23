#include <string>
#include <vector>
#include <queue>

#define RAN (ty<0||tx<0||ty>=5||tx>=5)
using namespace std;
typedef pair<int,int> p;
int n=0, dx[4]={0,0,1,-1}, dy[4]={1,-1,0,0};
int dist[5][5], visit[5][5];

bool bfs(int y, int x,const vector<string> &map){
    queue<p> q;
    q.push({y,x});
    visit[y][x]=++n;
    dist[y][x]=0;
    while(!q.empty()){
        int cy=q.front().first, cx=q.front().second;
        q.pop();
        if(map[cy][cx]=='P'&&dist[cy][cx]>0&&dist[cy][cx]<=2){
            return true;
        }
        for(int i=0; i<4; i++){
            int ty=cy+dy[i], tx=cx+dx[i];
            if(RAN||visit[ty][tx]==n||map[ty][tx]=='X')continue;
            dist[ty][tx]=dist[cy][cx]+1;
            visit[ty][tx]=n;
            q.push({ty,tx});
        }
    }
    return false;
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int k=0; k<5; k++){
        bool flag=false;
        for(int i=0; i<5; i++){
            if(flag)break;
            for(int j=0; j<5; j++) {
                if(places[k][i][j]=='P'){
                    if(bfs(i,j,places[k])){
                        flag=true;
                        break;
                    }
                }
            }
        }
        if(flag)answer.push_back(0);
        else answer.push_back(1);
    }
    return answer;
}
