#include <string>
#include <vector>
#include <queue>
#define RAN (ty<0||tx<0||ty>=N||tx>=N)
using namespace std;
struct State{
    int y,x,d,c;
    State(){State(0,0,0,0);}
    State(int yy,int xx, int dd, int cc):y(yy),x(xx),d(dd),c(cc){}
    bool operator > (const State &s)const{
        if(c==s.c&&y==s.y&&x==s.x)return d>s.d;
        else if(c==s.c&&y==s.y)return x>s.x;
        else if(c==s.c)return y>s.y;
        else return c>s.c;
    }
};
bool visit[25][25][5];
int dy[5]={0,1,-1,0,0}, dx[5]={0,0,0,1,-1};
int dist[25][25][5];

int solution(vector<vector<int>> board) {
    int INF = 1<<30;
    int N=board.size();
    for(int i=0; i<N; i++)for(int j=0; j<N; j++)for(int k=0; k<5; k++)dist[i][j][k]=INF;
    
    dist[0][0][0]=0;
    State s =State(0,0,0,0);
    priority_queue<State,vector<State>,greater<State>> pq;
    pq.push(s);
    while(!pq.empty()){
        State curr;
        do{
            curr=pq.top(); pq.pop();
        }while(!pq.empty()&&visit[curr.y][curr.x][curr.d]);
        if(visit[curr.y][curr.x][curr.d])break;
        visit[curr.y][curr.x][curr.d]=true;
        int y=curr.y, x=curr.x, d=curr.d;
        
        for(int i=1; i<5; i++){
            int ty=y+dy[i], tx=x+dx[i];
            int cost=((d==0||d==i)?1:6);
            if(RAN||board[ty][tx]==1)continue;
            if(dist[ty][tx][i]>dist[y][x][d]+cost){
                dist[ty][tx][i]=dist[y][x][d]+cost;
                pq.push(State(ty,tx,i,dist[ty][tx][i]));
            }
        }
    }
    int answer=INF;
    for(int i=0; i<5; i++)answer=min(answer,dist[N-1][N-1][i]);
    return answer*100;
}
