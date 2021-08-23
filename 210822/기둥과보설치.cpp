#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
int Size;
bool map[101][101][2];
struct Temp{
    int x,y,a;
    bool operator < (const Temp& t)const{
        if(x==t.x&&y==t.y)return a<t.a;
        else if(x==t.x)return y<t.y;
        else return x<t.x;
    }
};
bool isPossibleColumn(int x, int y){
    if(y==0||map[y-1][x][0]||map[y][x][1])
        return true;
    if(x-1>=0&&map[y][x-1][1]) return true;
    return false;
}
bool isPossibleBow(int x, int y){
    if(y>0&&(map[y-1][x][0]||(x+1<Size&&map[y-1][x+1][0])))
        return true;
    if(x-1>=0&&x+1<Size&&map[y][x-1][1]&&map[y][x+1][1]) 
        return true;
    return false;
}
bool isPossibleDel(int x, int y, int a){
    map[y][x][a]=false;
    
    if(a){
        if(map[y][x][0]&&!isPossibleColumn(x,y))map[y][x][a]=true;
        if(x+1<Size&&map[y][x+1][0]&&!isPossibleColumn(x+1,y))map[y][x][a]=true;
        if(x+1<Size&&map[y][x+1][1]&&!isPossibleBow(x+1,y))map[y][x][a]=true;
        if(x-1<Size&&map[y][x-1][1]&&!isPossibleBow(x-1,y))map[y][x][a]=true;
    }
    else{
        if(y+1<Size&&map[y+1][x][0]&&!isPossibleColumn(x,y+1))map[y][x][a]=true;
        if(y+1<Size&&map[y+1][x][1]&&!isPossibleBow(x,y+1))map[y][x][a]=true;
        if(y+1<Size&&x-1>=0&&map[y+1][x-1][1]&&!isPossibleBow(x-1,y+1))map[y][x][a]=true;
    }
    
    return !map[y][x][a];
}
vector<vector<int>> solution(int n, vector<vector<int>> b) {
    vector<vector<int>> answer;
    Size=n+1;
    set<Temp>temp;
    for(int i=0; i<b.size(); i++){
        int x=b[i][0],y=b[i][1],isbow=b[i][2],isins=b[i][3];
        bool flag=false;
        if(isins){
            if(isbow)flag=isPossibleBow(x,y);
            else flag=isPossibleColumn(x,y);
            if(flag){
                map[y][x][isbow]=true;
                Temp t;t.x=x;t.y=y;t.a=isbow;
                temp.insert(t);
            }
        }
        else{
            flag=isPossibleDel(x,y,isbow);
            if(flag){
                Temp t;t.x=x;t.y=y;t.a=isbow;
                temp.erase(t);
            }
        }
    }

    for(auto n : temp){
        vector<int> t;
        t.push_back(n.x);
        t.push_back(n.y);
        t.push_back(n.a);
        answer.push_back(t);
    }
    return answer;
}
