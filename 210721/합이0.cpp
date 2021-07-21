//  성공

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long result;

int n;
vector<int> students;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    students.resize(n);

    for(int i = 0; i < n; i++) 
        cin >> students[i];

    if(n < 3) result = 0;
    else if(n == 3) {
        if(students[0] + students[1] + students[2] == 0) result = 1;
        else result = 0;
    }
    else {
        sort(students.begin(), students.end());

        for(int left = 0; left < n - 2; left++) {
            for(int right = left + 1; right < n - 1; right++) {
                int target = -(students[left] + students[right]);
                vector<int>::iterator start = students.begin() + right + 1;
                vector<int>::iterator end = students.end();

                int idx1 = lower_bound(start, end, target) - students.begin();
                int idx2 = upper_bound(start, end, target) - students.begin();
                result += (idx2 - idx1);
            }
        }

    }

    cout << result << '\n';
    
    return 0;
}