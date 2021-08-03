#include <iostream>
#include <vector>
#define GEAR       5
#define TEETH      9
#define CCW       -1    //  반시계 방향
#define STOP       0    //  정지
#define CW         1    //  시계 방향
using namespace std;

int k, gear, rot, add = 1, ans;
vector<vector<int> > gears;
vector<bool> to_rotate(GEAR);
vector<int> direction(GEAR);

void decide_to_rotate(int g_num, int rot) {
    direction[g_num] = rot;

    for(int i = g_num - 1; i >= 1; i--) {
        if(gears[i + 1][7] == gears[i][3]) 
            direction[i] = STOP;
        else 
            direction[i] = (-1) * direction[i + 1];
    }

    for(int i = g_num + 1; i < GEAR; i++) {
        if(gears[i - 1][3] == gears[i][7]) 
            direction[i] = STOP;
        else 
            direction[i] = (-1) * direction[i - 1];
    }
}

void rotate(int g_num, int dir) {
    int tmp;

    if(dir == CW) { //  g_num 번째 톱니바퀴를 시계 방향으로 회전시킴
        tmp = gears[g_num][TEETH - 1];

        for(int i = TEETH - 1; i > 1; i--)
            gears[g_num][i] = gears[g_num][i - 1];
        gears[g_num][1] = tmp;
    }
    else if(dir == CCW) {  //  g_num 번째 톱니바퀴를 반시계 방향으로 회전시킴 
        tmp = gears[g_num][1];
        for(int i = 1; i < TEETH - 1; i++)
            gears[g_num][i] = gears[g_num][i + 1];
        gears[g_num][TEETH - 1] = tmp;
    }
    else;   //  STOP일 경우 아무것도 안함
}

void rotate() {
    for(int i = 1; i < GEAR; i++)
        rotate(i, direction[i]);
}

void calculate_score() {
    for(int i = 1; i < GEAR; i++) {
        if(gears[i][1] == 1) ans += add;
        add *= 2;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    gears.assign(GEAR, vector<int>());
    for(int i = 0; i < GEAR; i++)
        gears[i].assign(TEETH, 0);

    for(int i = 1; i < GEAR; i++) {
        for(int j = 1; j < TEETH; j++) {
            char c;
            cin >> c;
            gears[i][j] = int(c - '0');
        }
        cin.ignore();
    }

    cin >> k;
    for(int i = 0; i < k; i++) {
        for(int i = 1; i < GEAR; i++) 
            direction[i] = STOP;

        cin >> gear >> rot;
        decide_to_rotate(gear, rot);
        rotate();
    }

    calculate_score();

    cout << ans << '\n';
    return 0;
}