#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left, *right;

	Node(int data)
	{
		this.data = data;
		left = NULL;
		right = NULL;
	}
};

Node *sorted_array_to_balanced_bst(int arr[], int l, int r)
{
	int l = 0, r = n-1;
	int m = (l+r)/2;

	Node *root = new Node(arr[m]);
	root->left = sorted_array_to_balanced_bst(arr, l, m-1);
	root->right = sorted_array_to_balanced_bst(arr, m, r);
}