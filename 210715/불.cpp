#include <iostream>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

int t, w, h, result;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

vector<vector<char> > graph;

void bfs() {
    queue<pair<int, int> > fq;
    queue<pair<int, int> > mq;
    int finput = 0;
    int minput = 0;

    for(int i = 1; i <= h; i++) {
        for(int j = 1; j <= w; j++) {
            if(graph[i][j] == '*') {
                fq.push(make_pair(i, j));
                finput += 1;
            }
            else if(graph[i][j] == '@') {
                mq.push(make_pair(i, j));
                minput += 1;
            }
        }
    }

    while(true) {
        int ftemp = 0, mtemp = 0;
        int y, x, ny, nx;

        for(int i = 0; i < finput; i++) {
            y = fq.front().first;
            x = fq.front().second;
            fq.pop();

            for(int j = 0; j < 4; j++) {
                ny = y + dy[j];
                nx = x + dx[j];
                if(graph[ny][nx] != '#' && graph[ny][nx] != '*' && !(ny <= 0 || ny > h || nx <= 0 || nx > w)) {
                    graph[ny][nx] = '*';
                    fq.push(make_pair(ny, nx));
                    ftemp += 1;
                }
            }
        }
        finput = ftemp;
        ftemp = 0;

        for(int i = 0; i < minput; i++) {
            y = mq.front().first;
            x = mq.front().second;
            mq.pop();

            for(int j = 0; j < 4; j++) {
                ny = y + dy[j];
                nx = x + dx[j];

                if(((ny == 0 || ny == h + 1) && (0 <= nx && nx <= w + 1)) || 
                    ((nx == 0 || nx == w + 1) && (1 <= ny && ny <= h))) {
                    while(!fq.empty())
                        fq.pop();
                    while(!mq.empty())
                        mq.pop();
                    return;
                }
                else if(graph[ny][nx] == '.') {
                    graph[ny][nx] = '@';
                    mq.push(make_pair(ny, nx));
                    mtemp += 1;
                }
            }
        }
        minput = mtemp;
        if(mtemp == 0) {
            result = -1;
            return;
        }

        mtemp = 0;
        result += 1;
    }   //  while-end
}   //  bfs-end

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> t;
    for(int i = 0; i < t; i++) {
        result = 0;
        cin >> w >> h;
        cin.ignore();

        graph.assign(h + 2, vector<char>());
        for(int i = 0; i <= h + 1; i++)
            graph[i].assign(w + 2, '.');
        
        for(int i = 1; i <= h; i++) {
            for(int j = 1; j <= w; j++) 
                cin >> graph[i][j];
            cin.ignore();
        }

        bfs();
        if(result != -1)
            cout << result + 1 << '\n';
        else
            cout << "IMPOSSIBLE" << '\n';
    }

    return 0;
}