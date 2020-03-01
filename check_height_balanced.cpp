#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left, *right;

	Node(int val)
	{
		data = val;
		left = NULL;
		right = NULL;
	}
};

bool isBalanced(Node *root, int *height)
{
	int lh = 0, rh = 0;
	int l = 0, r = 0;

	if(root == NULL)
	{
		*height = 0;
		return 1;
	}

	l = isBalanced(root->left, &lh);
	r = isBalanced(root->right, &rh);

	*height = 1 + max(lh, rh);

	if(abs(lh - rh) > 1)
		return 0;
	else
		return l && r;
}

int main()
{
	Node *root = new Node(1);
	root->left = new Node(2);
	root->left->right = new Node(8);
	root->right = new Node(3);
	root->right->left = new Node(4);
	root->right->right = new Node(5);
	root->right->left->left = new Node(6);
	root->right->left->right = new Node(7);

	int height = 0;
	cout << isBalanced(root, &height) << endl;


	return 0;
}