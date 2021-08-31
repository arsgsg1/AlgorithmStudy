#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAX=10001;
struct Node{
    int y,x,n;
    Node(){Node(0,0,0);}
    Node(int a, int b, int c):y(a),x(b),n(c){}
    bool operator<(const Node node)const{
        if(y==node.y&&x==node.x)return n<node.n;
        else if(y==node.y)return x<node.x;
        else return y<node.y;
    }
};
Node node[MAX];
int tree[MAX][2];
void make_tree(int root, int val){
    
    if(node[root].x>node[val].x){
        if(tree[root][0]>0)make_tree(tree[root][0],val);
        else tree[root][0]=val;
    }
    else{
        if(tree[root][1]>0)make_tree(tree[root][1],val);
        else tree[root][1]=val;
    }
}

void preOrder(int root,vector<int>& v){
    if(root==0)return;
    v.push_back(root);
    preOrder(tree[root][0],v);
    preOrder(tree[root][1],v);
}
void postOrder(int root,vector<int>& v){
    if(root==0)return;
    postOrder(tree[root][0],v);
    postOrder(tree[root][1],v);
    v.push_back(root);
}
vector<vector<int>> solution(vector<vector<int>> n) {
    vector<vector<int>> answer(2);
    vector<Node> v;
    for(int i=0; i<n.size(); i++){
        Node nn =Node(n[i][1],n[i][0],i+1);
        v.push_back(Node(nn));
        node[i+1]=nn;
    }
    sort(v.begin(),v.end());
    int root=v.back().n;
    v.pop_back();
    while(!v.empty()){
        make_tree(root,v.back().n);
        v.pop_back();
    }
    preOrder(root,answer[0]);
    postOrder(root,answer[1]);
    return answer;
}
