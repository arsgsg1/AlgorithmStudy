//  40분

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, s, ans;
vector<int> arr;
vector<int> sum;

int ps(int start, int end) {
    if(start == 0)
        return sum[end];
    else
        return sum[end] - sum[start - 1];
}

int plen(int start, int end) {
    return end - start + 1;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s;
    ans = n;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    sum.assign(n, 0);

    sum[0] = arr[0];
    sum.push_back(arr[0]);
    for(int i = 1; i < n; i++) 
        sum[i] = sum[i - 1] + arr[i];

    int start = 0, end = 0;
    bool ok = false;    //  부분합이 s보다 큰 경우가 존재할 경우 true
    while(start < n && end < n) {
        // cout << "while!" << '\n';
        if(ps(start, end) < s)  //  부분합이 s보다 작을 경우 end 1 증가(부분합 증가)
            end++;
        else {  //  부분합이 s보다 크거나 같을 경우
            ok = true;  //  일단 s보다 큰 경우가 존재하긴 하므로 true
            ans = min(ans, plen(start, end));   //  그 길이 저장

            if(start == end) break; //  길이가 1인 경우 그게 최소 길이
            start++;    //  부분합을 감소시키기 위해 start 1 증가
        }
    }
    if(!ok) ans = 0;

    cout << ans << '\n';
    return 0;
}