#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <iostream>
#define RAN (ty<0||tx<0||ty>=4||tx>=4)
using namespace std;
typedef pair<int,pair<int,int>> p;
const int INF=1<<10;
bool visit[4][4];
int cost[4][4];
int dy[4]={0,0,1,-1}, dx[4]={1,-1,0,0};
vector<vector<int>> map;
int move(int sy, int sx, int ey, int ex){
    priority_queue<p,vector<p>> pq;
    memset(visit,0,sizeof(visit));
    for(int i=0; i<4; i++)for(int j=0; j<4; j++)cost[i][j]=INF;
    cost[sy][sx]=0;
    pq.push({0,{sy,sx}});
    
    while(!pq.empty()){
        int cy,cx, c;
        do{
            cy=pq.top().second.first;
            cx=pq.top().second.second;
            c=pq.top().first; pq.pop();
        }while(!pq.empty()&&visit[cy][cx]);
        if(visit[cy][cx])break;
        visit[cy][cx]=true;
        if(cy==ey&&cx==ex)break;
        for(int i=0; i<4; i++){
            int ty=cy+dy[i], tx=cx+dx[i];
            if(RAN)continue;
            if(cost[ty][tx]>cost[cy][cx]+1){
                cost[ty][tx]=cost[cy][cx]+1;
                pq.push({-cost[ty][tx],{ty,tx}});
            }
            while(!RAN&&map[ty][tx]==0){ty+=dy[i]; tx+=dx[i];}
            if(RAN){ty-=dy[i];tx-=dx[i];}
            if(cost[ty][tx]>cost[cy][cx]+1){
                cost[ty][tx]=cost[cy][cx]+1;
                pq.push({-cost[ty][tx],{ty,tx}});
            }
        }
    }
    return cost[ey][ex];
}
int N;
vector<int> cards[6];
int recur(int r, int c, int check=0, int n=0){
    if(n==N)return 0;
    int res=INF;
    for(int i=0; i<N; i++)if(!(check&1<<i)){
        int cy1 = cards[i][0]/6, cx1 = cards[i][0]%6;
        int cy2 = cards[i][1]/6, cx2 = cards[i][1]%6;
        int dist1=move(r,c,cy1,cx1) , dist2=move(r,c,cy2,cx2), dist3=move(cy1,cx1,cy2,cx2), dist4=move(cy2,cx2,cy1,cx1);
        map[cy1][cx1]=map[cy2][cx2]=0;
        int temp=min(dist1+dist3+recur(cy2,cx2,check|1<<i,n+1),dist2+dist4+recur(cy1,cx1,check|1<<i,n+1))+2;
        map[cy1][cx1]=map[cy2][cx2]=i+1;
        res=min(res,temp);
    }
    return res;
}

int solution(vector<vector<int>> board, int r, int c) {
    map=board;
    int answer = 0;
    for(int i=0; i<4; i++) for(int j=0; j<4; j++) if(board[i][j]>0){
        cards[board[i][j]-1].push_back(i*6+j);
        N=max(N,board[i][j]);
    }

    return answer=recur(r,c);
}
