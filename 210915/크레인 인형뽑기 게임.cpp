#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int pick(int col, vector<vector<int>>& board) {
    for (int i = 0; i < board.size(); i++) {
        if (board[i][col] > 0) {
            int num = board[i][col];
            board[i][col] = 0;
            return num;
        }
    }
    return -1;
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> st;
    for (auto move : moves) {
        int num = pick(move - 1, board);
        if (num == -1) continue;
        if (!st.empty() && st.top() == num) {
            st.pop();
            answer += 2;
        } else {
            st.push(num);
        }
    }
    return answer;
}
