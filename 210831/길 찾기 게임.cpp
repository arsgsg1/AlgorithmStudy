#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
	int idx;
	int x, y;
	node* left;
	node* right;
};
bool comp(node& n1, node& n2)
{
	return n1.y > n2.y;
}
node* root = NULL;
void insertNode(node* cur, node* newNode)
{
	if (root != NULL) {
		node* left = cur->left, *right = cur->right;
		if (left == NULL && newNode->x < cur->x)
			cur->left = newNode;
		else if (right == NULL && newNode->x > cur->x)
			cur->right = newNode;

		if (left != NULL && newNode->x < cur->x) {
			insertNode(left, newNode);
		}
		else if (right != NULL && newNode->x > cur->x) {
			insertNode(right, newNode);
		}
	}
	else
		root = newNode;
}
void preOrder(node* cur, vector<int>& answer)
{
	answer.push_back(cur->idx);
	if (cur->left != NULL) {
		preOrder(cur->left, answer);
	}
	if (cur->right != NULL) {
		preOrder(cur->right, answer);
	}
}
void postOrder(node* cur, vector<int>& answer)
{
	if (cur->left != NULL) {
		postOrder(cur->left, answer);
	}
	if (cur->right != NULL) {
		postOrder(cur->right, answer);
	}
	answer.push_back(cur->idx);
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<vector<int>> answer;
	vector<node> nodes;
	int idx = 1;
	for (const auto& info : nodeinfo) {
		node n;
		n.idx = idx++;
		n.x = info[0];
		n.y = info[1];
		n.left = NULL, n.right = NULL;
		nodes.push_back(n);
	}
	sort(nodes.begin(), nodes.end(), comp);
	for (int i = 0; i < nodes.size(); i++)
		insertNode(root, &nodes[i]);
	vector<int> preAnswer, postAnswer;
	preOrder(root, preAnswer);
	postOrder(root, postAnswer);
	answer.push_back(preAnswer);
	answer.push_back(postAnswer);
	return answer;
}

void main()
{
	solution({ { 5, 3 },{ 11, 5 },{ 13, 3 },{ 3, 5 },{ 6, 1 },{ 1, 3 },{ 8, 6 },{ 7, 2 },{ 2, 2 } });
}