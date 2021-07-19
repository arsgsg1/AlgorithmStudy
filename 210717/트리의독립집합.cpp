#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> weights;              //  그래프의 정점의 가중치
vector<vector<int> > graph;       //  처음 입력 그래프
vector<vector<int> > dfs_tree;    //  DFS로 생성한 트리
vector<vector<int> > dp_table;    //  dp_table[i][0] : 정점 i를 포함하지 않았을 때 트리 i의 최대 독립집합 크기
                                  //  dp_table[i][1] : 정점 i를 포함했을 때 트리 i의 최대 독립집합 크기
vector<int> check;      
vector<int> result;               //  최대 독립집합에 포함된 정점

void dfs(int cur, int prev) {   //  dfs로 DFS 트리 생성
    for(int i = 0; i < graph[cur].size(); i++) {
        int next = graph[cur][i];
        if(next != prev) {
            dfs_tree[cur].push_back(next);
            dfs(next, cur);
        }
    }
}

int tree_dp(int now, int include) { //  dp 테이블을 작성함.
    // cout << "tree_dp(" << now << ", " << include << ")" <<'\n';

    int& res = dp_table[now][include];

    if(res != -1)   //  이미 값이 저장된 경우 반환
        return res;

    if(include) {   //  독립집합에 정점 now를 포함할 경우
        int ans = 0;
        for(int i = 0; i < dfs_tree[now].size(); i++) {
            int next = dfs_tree[now][i];
            ans += tree_dp(next, 0);    //  now의 자식 노드들은 포함하지 않음.
        }
        return res = ans + weights[now];
    }
    else {  //  독립집합에 정점 now를 포함하지 않을 경우
        int ans = 0;
        for(int i = 0; i < dfs_tree[now].size(); i++) {
            int next = dfs_tree[now][i];
            int t1 = tree_dp(next, 0);  //  자식 노드를 포함하지 않을 경우
            int t2 = tree_dp(next, 1);  //  자식 노드를 포함할 경우

            if(t1 < t2)   //  자식 노드를 포함한 게 더 클 경우
                check[next] = 1;
            ans += max(t1, t2);
        }
        return res = ans;
    }
}

void track(int now, int include) {
    if(include) {
        result.push_back(now);
        for(int i = 0; i < dfs_tree[now].size(); i++) {
            int next = dfs_tree[now][i];
            track(next, 0);
        }
    }
    else {
        for(int i = 0; i < dfs_tree[now].size(); i++) {
            int next = dfs_tree[now][i];
            if(dp_table[next][0] > dp_table[next][1])
                track(next, 0);
            else
                track(next, 1);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    weights.assign(n + 1, 0);
    graph.resize(n + 1);
    dfs_tree.resize(n + 1);
    dp_table.resize(n + 1);
    for(int i = 0; i <= n; i++)
        dp_table[i].assign(2, -1);
    check.assign(n + 1, 0);   

    for(int i = 1; i <= n; i++) 
        cin >> weights[i];
    for(int i = 1; i <= n - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, 1);

    int t1 = tree_dp(1, 0);
    int t2 = tree_dp(1, 1);

    if(t1 < t2) 
        check[1] = 1;
    else 
        check[1] = 0;

    int cost = max(t1, t2);
    cout << cost << '\n';
    track(1, check[1]);

    sort(result.begin(), result.end());
    for(int i = 0; i < result.size(); i++)
        cout << result[i] << ' ';
    cout << '\n';
    return 0;
}

