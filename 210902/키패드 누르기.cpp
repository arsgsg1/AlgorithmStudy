#include <vector>
#include <algorithm>
using namespace std;

const int dial[10][2] = {{3, 1}, {0, 0}, {0, 1}, {0, 2}, {1, 0},
                         {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}};

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int lx = 3, ly = 0;
    int rx = 3, ry = 2;
    for (auto number : numbers) {
        int x = dial[number][0];
        int y = dial[number][1];
        if (number == 1 || number == 4 || number == 7) {
            answer += 'L';
            lx = x;
            ly = y;
        } else if (number == 3 || number == 6 || number == 9) {
            answer += 'R';
            rx = x;
            ry = y;
        } else {
            int ld = abs(lx - x) + abs(ly - y);
            int rd = abs(rx - x) + abs(ry - y);
            if (ld < rd || (ld == rd && hand == "left")) {
                answer += 'L';
                lx = x;
                ly = y;
            } else if (ld > rd || (ld == rd && hand == "right")) {
                answer += 'R';
                rx = x;
                ry = y;
            }
        }
    }
    return answer;
}
