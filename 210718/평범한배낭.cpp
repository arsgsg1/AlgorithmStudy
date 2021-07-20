#include <iostream>
#include <vector>
using namespace std;

vector<int> weight;
vector<int> value;
vector<vector<int> > table;

void knapsack(vector<int> weight, vector<int> value, vector<vector<int> >& table, int N, int K) {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= K; j++) {
            if(weight[i] > j) table[i][j] = table[i - 1][j];
            else {
                if(value[i] + table[i - 1][j - weight[i]] > table[i - 1][j])
                    table[i][j] = value[i] + table[i - 1][j - weight[i]];
                else     
                    table[i][j] = table[i - 1][j];
            }
        }
    }
}

int main(void) {
    int N, K;

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;

    weight.assign(N + 1, 0);
    value.assign(N + 1, 0);
    table.resize(N + 1);
    for(int i = 0; i <= N; i++)
        table[i].assign(K + 1, 0);

    for(int i = 0; i <= K; i++)
        table[0][i] = 0;
    for(int i = 0; i <= N; i++)
        table[i][0] = 0;

    for(int i = 1; i <= N; i++) 
        cin >> weight[i] >> value[i];

    knapsack(weight, value, table, N, K);

    cout << table[N][K] << "\n";

    return 0;
}