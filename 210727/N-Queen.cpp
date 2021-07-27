#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> col;
int n, sol;

bool promising(int i) {
    int k = 1;
    bool tf = true;

    while(k < i && tf) {
        if(col[i] == col[k] || abs(col[i] - col[k]) == i - k) {  
        tf = false;
        }
        k++;
    }
    return tf;
}

void queens(int i) {
    int j;
    if(promising(i)) {
        if(i == n) 
            sol++;
        else {
            for(j = 1; j <= n; j++) {
                col[i + 1] = j;
                queens(i + 1);
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    col.assign(n + 1, 0);

    queens(0);
    cout << sol << '\n';

    return 0;
}

