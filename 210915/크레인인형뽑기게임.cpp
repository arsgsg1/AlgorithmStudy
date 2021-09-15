#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
const int MAX=31;
queue<int> q[MAX];
stack<int> s;
int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0,N=board.size(),M=board[0].size();
    for(int i=0; i<N; i++)for(int j=0; j<M; j++)if(board[i][j]>0)q[j].push(board[i][j]);
    for(auto n : moves){
        int temp;
        if(!q[n-1].empty()){temp=q[n-1].front(); q[n-1].pop();}
        else continue;
        if(s.empty()||s.top()!=temp)s.push(temp);
        else{
            s.pop(); answer+=2;
        }
    }
    
    return answer;
}
