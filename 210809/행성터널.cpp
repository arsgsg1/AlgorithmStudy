#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int n;
vector<int> parents;
vector<pair<int, int> > coord_x;    //  (행성의 x 좌표, 행성 번호)
vector<pair<int, int> > coord_y;    //  (행성의 y 좌표, 행성 번호)
vector<pair<int, int> > coord_z;    //  (행성의 z 좌표, 행성 번호)
vector<pair<int, pair<int, int> > > edges;  //  (행성 A, B 사이의 거리, 행성 A, B)

int find_parent(int x) {
    if(parents[x] == x)
        return x;
    else  
        return parents[x] = find_parent(parents[x]);
}

void union_parent(int x, int y) {
    x = find_parent(x);
    y = find_parent(y);

    if(x == y)  //  이미 같은 집합에 속함
        return;
    else if(x > y)
        parents[x] = y;
    else
        parents[y] = x;
}

int kruskal() {
    int sum = 0, cnt = 0;   //  간선 비용 합, 간선 개수
    sort(edges.begin(), edges.end());   //  간선 비용 순으로 정렬

    for(int i = 0; i < edges.size(); i++) {
        int cost = edges[i].first;             //  간선 비용
        int a = edges[i].second.first;         //  간선의 두 행성 번호
        int b = edges[i].second.second;

        if(find_parent(a) != find_parent(b)) {  //  두 행성이 같은 집합에 속하지 않을 경우
            union_parent(a, b); //  두 행성이 같은 집합에 속하도록 합침
            cnt++;  //  간선 개수 1 증가
            sum += cost;    //  비용 증가
        }

        if(cnt == n - 1) break; //  간선 개수 n - 1이면 멈춤
    }

    return sum;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    for(int i = 0; i <= n; i++)
        parents.push_back(i);

    for(int i = 1; i <= n; i++) {
        int x, y, z;    //  i번째 행성 번호 x, y, z 좌표
        cin >> x >> y >> z;

        coord_x.push_back(make_pair(x, i));     //  x 좌표, 행성 번호 저장
        coord_y.push_back(make_pair(y, i));     //  y 좌표, 행성 번호 저장
        coord_z.push_back(make_pair(z, i));     //  z 좌표, 행성 번호 저장
    }

    sort(coord_x.begin(), coord_x.end());   //  x 좌표순으로 정렬
    sort(coord_y.begin(), coord_y.end());   //  y 좌표순으로 정렬
    sort(coord_z.begin(), coord_z.end());   //  z 좌표순으로 정렬

    for(int i = 0; i < n - 1; i++) {
        //  정렬 후 인접한 좌표끼리만 고려하면 됨. 그 이상의 경우 거리가 더 멀어지므로 고려할 필요가 없음
        edges.push_back(make_pair(coord_x[i + 1].first - coord_x[i].first, make_pair(coord_x[i].second, coord_x[i + 1].second)));
        edges.push_back(make_pair(coord_y[i + 1].first - coord_y[i].first, make_pair(coord_y[i].second, coord_y[i + 1].second)));
        edges.push_back(make_pair(coord_z[i + 1].first - coord_z[i].first, make_pair(coord_z[i].second, coord_z[i + 1].second)));
    }   //  간선 3(n - 1)개

    cout << kruskal() << '\n';

    return 0;
}