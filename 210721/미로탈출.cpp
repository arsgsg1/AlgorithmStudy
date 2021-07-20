#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
const int INF=1<<30, MAX=1001;
typedef pair<int,pair<int,int>> p;
int dist[MAX][1<<11], isTrap[MAX]; 
bool visit[MAX][1<<11];
vector<p> adj[MAX];
int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    int answer = INF, t=1;
    for(int i=0; i<n; i++)for(int j=0; j<1<<11; j++)
        dist[i][j]=INF;
    for(int i : traps)isTrap[i-1]=t++;
    for(auto n : roads){
        int s=n[0], e=n[1], c=n[2]; s--; e--;
        adj[s].push_back({e,{c,true}});
        adj[e].push_back({s,{c,false}});
    }
    start--;end--;
    dist[start][0]=0;
    priority_queue<p,vector<p>,greater<p>> pq;
    pq.push({0,{start,0}});
    while(!pq.empty()){
        int curr, state;
        do{
            curr=pq.top().second.first;
            state=pq.top().second.second; 
            pq.pop();
        }while(!pq.empty()&&visit[curr][state]);
        if(visit[curr][state])break;
        visit[curr][state]=true;
        int tstate=state;
        if(isTrap[curr]>0)tstate^=(1<<isTrap[curr]);
        
        for(auto n : adj[curr]){
            int next=n.first, cost=n.second.first;
            bool estate=n.second.second, flag=true;
            int isCurrOn=tstate&(1<<isTrap[curr]);
            int isNextOn=tstate&(1<<isTrap[next]);
            
            if(isCurrOn<1&&isNextOn<1){if(!estate)flag=false;}
            else if(isCurrOn<1&&isNextOn>1){if(estate)flag=false;}
            else if(isCurrOn>1&&isNextOn<1){if(estate)flag=false;}
            else{if(!estate)flag=false;}
            
            if(flag){
                if(dist[next][tstate]>cost+dist[curr][state]){
                    dist[next][tstate]=cost+dist[curr][state];
                    pq.push({dist[next][tstate],{next,tstate}});
                }
            }
        }
    }
    for(int i=0; i<1<<11; i++)answer=min(answer,dist[end][i]);
    return answer;
}
