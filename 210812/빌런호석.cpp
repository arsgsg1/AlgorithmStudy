#include <iostream>
#include <vector>
using namespace std;

int N, K, P, X, ans;
int START = 1, END;
bool segment7[10][7] = {
    {1, 1, 1, 0, 1, 1, 1},  //  0
    {0, 0, 1, 0, 0, 1, 0},  //  1
    {1, 0, 1, 1, 1, 0, 1},  //  2
    {1, 0, 1, 1, 0, 1, 1},  //  3
    {0, 1, 1, 1, 0, 1, 0},  //  4
    {1, 1, 0, 1, 0, 1, 1},  //  5
    {1, 1, 0, 1, 1, 1, 1},  //  6
    {1, 0, 1, 0, 0, 1, 0},  //  7
    {1, 1, 1, 1, 1, 1, 1},  //  8
    {1, 1, 1, 1, 0, 1, 1}   //  9
};

int diff[10][10];
vector<int> current_floor;
vector<int> target_floor;

void print_floor(vector<int> target) {
    for(int i = 0; i < target.size(); i++)
        cout << target[i];
    cout << '\n';
}

void set_floor(int floor, vector<int>& target) {
    int pos = target.size() - 1;

    for(int i = 0; i < target.size(); i++)
        target[i] = 0;

    while(floor != 0) {
        int num = floor % 10;
        target[pos--] = num;
        floor /= 10;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K >> P >> X;
    END = N;
    current_floor.assign(K, 0);
    target_floor.assign(K, 0);

    for(int i = 0; i < 9; i++) {
        for(int j = i + 1; j < 10; j++) {
            int cnt = 0;
            for(int k = 0; k < 7; k++) {
                if(segment7[i][k] != segment7[j][k])
                    cnt++;
            }
            diff[i][j] = diff[j][i] = cnt;
        }
    }

    set_floor(X, current_floor);

    for(int i = START; i <= END; i++) {
        int cnt = 0;    //  현재 층과 조작된 층간의 변경 횟수
        set_floor(i, target_floor);

        for(int i = 0; i < K; i++) {
            int a = current_floor[i];
            int b = target_floor[i];
            int mod = diff[a][b];
            cnt += mod;
        }

        if(1 <= cnt && cnt <= P) ans += 1;
    }
    cout << ans << '\n';

    return 0;
}