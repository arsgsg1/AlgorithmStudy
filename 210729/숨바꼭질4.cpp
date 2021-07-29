#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#define MAXNUM  100001
#define MIN          0
#define MUL          1
#define ADD          2
#define NONE        -1
using namespace std;

int n, k, ans;
vector<bool> visited(MAXNUM, false);
vector<int> parent(MAXNUM, NONE);
stack<int> path;

void bfs() {
    int qinput = 1;
    queue<int> q;
    visited[n] = true;
    q.push(n);

    while(!q.empty()) {
        int tmp = 0;
        for(int i = 0; i < qinput; i++) {
            int num = q.front();
            int nnum;
            q.pop();

            for(int i = 0; i < 3; i++) {
                if(i == MIN) nnum = num - 1;
                else if(i == MUL) nnum = num * 2;
                else if(i == ADD) nnum = num + 1;

                if(nnum < 0 || nnum >= MAXNUM || visited[nnum])
                    continue;

                parent[nnum] = num;
                if(nnum == k) {
                    ans += 1;
                    return;
                }
                
                visited[nnum] = true;
                q.push(nnum);
                tmp++;
            }
        }
        qinput = tmp;
        ans += 1;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;

    if(n == k) {
        cout << ans << '\n';
        cout << n << '\n';
    }
    else {
        bfs();

        int start = k;
        while(parent[start] != NONE) {
            path.push(start);
            start = parent[start];
        }

        cout << ans << '\n';
        cout << n << ' ';
        while(!path.empty()) {
            cout << path.top() << ' ';
            path.pop();
        }
        cout << '\n';
    }

    return 0;
}