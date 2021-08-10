#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;
LL N, K;

LL func(LL x) { //  N^2 행렬 A의 수 중 x보다 작거나 같은 것의 개수
    LL sum = 0;

    for(LL i = 1; i <= N; i++) {
        sum += min(N, x / i);
    }

    return sum;
}

LL binsearch() {
    LL start = 1;
    LL end = N * N;
    LL mid = (start + end) / 2;
    LL ret = N * N;

    while(start <= end) {
        LL p = func(mid);
        
        if(p < K) 
            start = mid + 1;
        else {
            ret = mid;
            end = mid - 1;
        }
        mid = (start + end) / 2;
    }

    return ret;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> K;

    cout << binsearch() << '\n';
    return 0;
}