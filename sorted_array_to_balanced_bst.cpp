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

Node *sortedArrayToBalancedBst(int arr[], int l, int r)
{
	if(l > r)
		return NULL;

	int m = (l+r)/2;

	Node *root = new Node(arr[m]);
	root->left = sortedArrayToBalancedBst(arr, l, m-1);
	root->right = sortedArrayToBalancedBst(arr, m+1, r);

	return root;
}

void printInoder(Node *root)
{
	if(root==NULL)
		return;

	printInoder(root->left);
	cout << root->data << " ";
	printInoder(root->right);
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	int n = sizeof(arr)/sizeof(arr[0]);

	Node *root = sortedArrayToBalancedBst(arr, 0, n-1);
	printInoder(root);

	return 0;
}