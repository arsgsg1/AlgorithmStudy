#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;

typedef pair<int,pair<int,int>> p;

const int INF = 1<<30, MAX = 1000;
int cost[MAX][1<<11];
bool visit[MAX][1<<11];
unordered_map<int,int> hm;
vector<p> adj[MAX];

int solution(int N, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    int answer = INF ,n=1;
    for(int i=0; i<N; i++)for(int j=0; j<1<<11; j++)cost[i][j]=INF;
    for(auto a : traps)hm[a-1]=n++;
    for(auto v : roads){
        adj[v[0]-1].push_back({v[2],{v[1]-1,0}});
        adj[v[1]-1].push_back({v[2],{v[0]-1,1}});
    }
    
    priority_queue<p,vector<p>>pq;
    pq.push({0,{start-1,0}});
    cost[start-1][0]=0;
    
    while(!pq.empty()){
        int curr, state;
        do{
            curr=pq.top().second.first;
            state=pq.top().second.second; pq.pop();
        }while(!pq.empty()&&visit[curr][state]);
        if(visit[curr][state])break;
        visit[curr][state]=true;
        
        int temp=hm[curr]>0?1<<hm[curr]:0;
        int newState=state^temp;

        for(auto n : adj[curr]){
            int next=n.second.first;
            bool isBack=n.second.second;
            int dist=n.first;
            int currState=newState&(temp);
            int nextState=newState&(hm[next]>0?1<<hm[next]:0);
            if(currState>0&&nextState>0){if(isBack)continue;}
            else if(currState==0&&nextState==0){if(isBack)continue;}
            else if(!isBack)continue;
            
            if(cost[next][newState]>cost[curr][state]+dist){
                cost[next][newState]=cost[curr][state]+dist;
                pq.push({-cost[next][newState],{next,newState}});
            }
        }
    }
    
    for(int i=0; i<1<<11; i++)answer=min(answer,cost[end-1][i]);
    return answer;
}
