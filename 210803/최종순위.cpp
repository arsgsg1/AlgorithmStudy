#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define NONE      -1    //  graph[a][b]가 1일 경우, a에서 b로 간선 존재함, NONE일 경우 간선 존재하지 않음
using namespace std;

int tc, n, m;
vector<vector<int> > graph; //  인접행렬
vector<int> last_year;  //  지난 년도 순위
vector<int> indegree;   //  진입 차수 저장 행렬
vector<int> this_year;  //  올해 년도 순위(정답 배열)

void topology_sort() {
    queue<int> q;
    bool ambig = false;

    for(int i = 1; i <= n; i++) {
        if(indegree[i] == 0)    //  진입 차수 0인 정점을 큐에 삽입
            q.push(i);
    }

    while(!q.empty()) { //  큐가 빌 때까지
        int input = 0;
        int x = q.front();
        q.pop();
        this_year.push_back(x);

        for(int i = 1; i <= n; i++) {
            if(graph[x][i] != NONE) {
                indegree[i] -= 1;
                if(indegree[i] == 0) {  //  진입 차수가 0일 경우 다음 순위임
                    q.push(i);
                    input += 1; //  동순위의 개수 1 증가(2 이상일 경우 경우가 여러가지임)
                }
            }
        }

        if(input > 1) ambig = true;
    }

    if(this_year.size() != n)   //  사이클이 생성되어 위상 정렬로 순위를 정할 수 없음(논리적 오류)
        cout << "IMPOSSIBLE" << '\n';
    else {  //  위상 정렬로 순위가 결정됨
        if(ambig) cout << "?" << '\n';  //  순위의 가짓수가 여러가지인 경우
        else {
            for(int i = 0; i < this_year.size(); i++)
                cout << this_year[i] << ' ';
            cout << '\n';
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> tc;

    for(int t = 0; t < tc; t++) {
        //  배열 초기화
        vector<vector<int> >().swap(graph);
        vector<int>().swap(last_year);
        vector<int>().swap(indegree);
        vector<int>().swap(this_year);

        cin >> n;
        graph.assign(n + 1, vector<int>());
        for(int i = 0; i <= n; i++) {
            graph[i].assign(n + 1, NONE);
            graph[i][i] = 0;
        }
        last_year.assign(n + 1, 0);
        indegree.assign(n + 1, 0);

        for(int i = 1; i <= n; i++)
            cin >> last_year[i];

        for(int i = 1; i < n; i++) {    //  인접 행렬과 indegree 행렬 구축
            for(int j = i + 1; j <= n; j++) {
                graph[last_year[i]][last_year[j]] = 1;
                indegree[last_year[j]] += 1;
            }
        }

        cin >> m;   //  순위 바꿀 m개 쌍 입력
        for(int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;

            if(graph[a][b] == 1 && graph[b][a] == NONE) {
                //  a->b 간선 존재할 경우
                indegree[a] += 1;
                indegree[b] -= 1;
            }
            else {
                //  b->a 간선 존재할 경우
                indegree[a] -= 1;
                indegree[b] += 1;
            }

            // 간선 방향 변경
            swap(graph[a][b], graph[b][a]);
        }
        topology_sort();
    }

    return 0;
}