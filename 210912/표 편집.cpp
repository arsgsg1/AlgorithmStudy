#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

struct Node {
    int index;
    Node *prev;
    Node *next;
    Node(int index) : index(index) {
        prev = NULL;
        next = NULL;
    }
};

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    stack<Node*> st;
    Node *head = new Node(0);
    Node *tail = head;
    for (int i = 1; i < n; i++) {
        Node *node = new Node(i);
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
    
    for (int i = 0; i < k; i++) head = head->next;
    
    for (auto& c : cmd) {
        if (c[0] == 'D') {
            int cnt = stoi(c.substr(2));
            while (cnt--) {
                head = head->next;
            }
        } else if (c[0] == 'U') {
            int cnt = stoi(c.substr(2));
            while (cnt--) {
                head = head->prev;
            }
        } else if (c[0] == 'Z') {
            Node *node = st.top();
            st.pop();
            Node *prev = node->prev;
            Node *next = node->next;
            
            if (prev != NULL) prev->next = node;
            if (next != NULL) next->prev = node;
        } else if (c[0] == 'C') {
            Node *node = head;
            st.push(node);
            Node *prev = head->prev;
            Node *next = head->next;
            
            if (prev != NULL) prev->next = next;
            if (next != NULL) next->prev = prev;
            
            if (head->next == NULL) head = head->prev;
            else head = head->next;
        }
    }
    
    for (int i = 0; i < n; i++) answer += 'X';
    while (head->prev != NULL) head = head->prev;
    while (head != NULL) {
        answer[head->index] = 'O';
        head = head->next;
    }
    
    return answer;
}

int main() {
    vector<string> cmd = {"D 2","C","U 3","C","D 4","C","U 2","Z","Z"};
    cout << solution(8, 2, cmd) << endl;
    return 0;
}
