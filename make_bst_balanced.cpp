#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left, *right;

	Node(int data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

Node *sortedArrayToBalancedBst(vector<int>& nodes, int l, int r)
{
	if(l > r)
		return NULL;

	int m = (l+r)/2;

	Node *root = new Node(nodes[m]);
	root->left = sortedArrayToBalancedBst(nodes, l, m-1);
	root->right = sortedArrayToBalancedBst(nodes, m+1, r);

	return root;
}

void storeNodesInArray(Node *root, vector<int>& nodes)
{
	if(root==NULL)
		return;

	storeNodesInArray(root->left, nodes);
	nodes.push_back(root->data);
	storeNodesInArray(root->right, nodes);
}

Node *balancedBst(Node *root)
{
	vector<int> nodes;

	storeNodesInArray(root, nodes);

	return sortedArrayToBalancedBst(nodes, 0, nodes.size()-1);
}

void printPreOrder(Node *root)
{
	if(root==NULL)
		return;

	cout << root->data << " ";
	printPreOrder(root->left);
	printPreOrder(root->right);
}

int main()
{
	Node* root = new Node(10); 
    root->left = new Node(8); 
    root->left->left = new Node(7); 
    root->left->left->left = new Node(6); 
    root->left->left->left->left = new Node(5); 

	root = balancedBst(root);
	printPreOrder(root);

	return 0;
}