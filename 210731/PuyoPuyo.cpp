#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define R        0
#define G        1
#define B        2
#define P        3
#define Y        4
#define NONE    -1
#define HEIGHT  12
#define WIDTH    6
using namespace std;

char field[HEIGHT][WIDTH];
bool visited[HEIGHT][WIDTH];
unordered_map<char, int> color;
vector<pair<int, int> > to_clear[5];
int ans;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

void reset_visited() {
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++)
            visited[i][j] = false;
    }
}

void reset_clear() {
    for(int i = 0; i < 5; i++) {
        while(!to_clear[i].empty())
            to_clear[i].pop_back();
    }
}

bool clear() {
    bool is_clear = false;
    for(int i = 0; i < 5; i++) {
        if(to_clear[i].size() < 4) continue;
        else {
            is_clear = true;
            break;
        }
    }
    if(!is_clear) return false;

    ans++;
    for(int k = 0; k < 5; k++) {
        for(int i = 0; i < to_clear[k].size(); i++) 
            field[to_clear[k][i].first][to_clear[k][i].second] = '.';
    }
    reset_visited();

    for(int k = 0; k < HEIGHT; k++) {
        for(int i = HEIGHT - 1; i >= 1; i--) {
            for(int j = 0; j < WIDTH; j++) {
                if(color[field[i][j]] == NONE && color[field[i - 1][j]] != NONE) {
                    swap(field[i - 1][j], field[i][j]);
                }
            }
        }
    }

    return true;
}

void bfs(int y, int x) {
    queue<pair<int, int> > q;
    int input = 1;
    int pos = color[field[y][x]];
    visited[y][x] = true;
    q.push(make_pair(y, x));
    to_clear[pos].push_back(make_pair(y, x));

    while(!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny < 0 || ny >= HEIGHT || nx < 0 || nx >= WIDTH)
                continue;
            
            if(!visited[ny][nx] && field[ny][nx] == field[y][x]) {
                visited[ny][nx] = true;
                q.push(make_pair(ny, nx));
                to_clear[pos].push_back(make_pair(ny, nx));
                input += 1;
            }
        }
    }

    if(input < 4) {
        for(int i = 0; i < input; i++)
            to_clear[pos].pop_back();
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    color['R'] = R; color['G'] = G; color['B'] = B;
    color['P'] = P; color['Y'] = Y; color['.'] = NONE;

    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) 
            cin >> field[i][j];
        cin.ignore();
    }

    while(true) {
        reset_clear();
        for(int i = HEIGHT - 1; i >= 0; i--) {
            for(int j = WIDTH - 1; j >= 0; j--) {
                if(!visited[i][j] && color[field[i][j]] != NONE) 
                    bfs(i, j);
            }
        }

        if(!clear()) break;
    }

    cout << ans << '\n';
    return 0;
}