#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int n;
// priority_queue<int, vector<int>, greater<int> > pq; //  최소 힙
priority_queue<int> pq;
vector<pair<int, int> > lectures;
vector<pair<int, int> >::iterator iter;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        lectures.push_back(make_pair(a, b));
    }

    sort(lectures.begin(), lectures.end());
    pq.push((-1) * lectures[0].second);

    for(int i = 1; i < n; i++) {
        if((-1) * pq.top() <= lectures[i].first) pq.pop();
        pq.push((-1) * lectures[i].second);
    }
    
    cout << pq.size() << '\n';
    return 0;
}
