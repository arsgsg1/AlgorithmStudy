#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    sort(arr.begin(), arr.end());
    
    bool flag = false;
    int answer = 2e9;
    for (int i = 0; i < n - 3 && !flag; i++) {
        for (int j = i + 3; j < n && !flag; j++) {
            int a = arr[i] + arr[j];
            int l = i + 1, r = j - 1;
            while (l < r) {
                int b = arr[l] + arr[r];
                answer = min(answer, abs(a - b));
                if (a < b) r--;
                else if (a > b) l++;
                else {
                    flag = true;
                    break;
                }
            }
        }
    }
    cout << answer << endl;
    return 0;
}
