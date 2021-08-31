#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Pos {
    int x, y, idx;
    bool operator<(const Pos& rhs) const {
        if (y == rhs.y) return x > rhs.x;
        return y < rhs.y;
    }
};

struct Node {
    int x, idx;
    Node* left;
    Node* right;
    Node(int x, int idx) : x(x), idx(idx) {
        left = NULL;
        right = NULL;
    }
};

vector<vector<int>> answer;

void preorder(Node *root) {
    answer[0].push_back(root->idx);
    if (root->left) preorder(root->left);
    if (root->right) preorder(root->right);
}

void postorder(Node *root) {
    if (root->left) postorder(root->left);
    if (root->right) postorder(root->right);
    answer[1].push_back(root->idx);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    answer.resize(2);
    int n = (int) nodeinfo.size();
    priority_queue<Pos> pq;
    for (int i = 0; i < n; i++)
        pq.push({nodeinfo[i][0], nodeinfo[i][1], i + 1});
    
    Node *root = new Node(pq.top().x, pq.top().idx);
    pq.pop();
    while (!pq.empty()) {
        Pos child = pq.top();
        pq.pop();
        
        Node *parent = root;
        while (1) {
            if (child.x < parent->x) {
                if (parent->left == NULL) {
                    parent->left = new Node(child.x, child.idx);
                    break;
                }
                parent = parent->left;
            } else {
                if (parent->right == NULL) {
                    parent->right = new Node(child.x, child.idx);
                    break;
                }
                parent = parent->right;
            }
        }
    }
    
    preorder(root);
    postorder(root);
    
    return answer;
}
