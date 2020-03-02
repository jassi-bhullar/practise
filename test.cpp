#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left, *right;
	int height;
	int count;

	Node(int val)
	{
		data = val;
		left = right = NULL;
		height = 1;
		count = 1;
	}
};

void display(Node *node)
{
	cout << node->data << endl;
	cout << node->height << endl;
	cout << node->left << endl;
	cout << node->right << endl;
	cout << node->count << endl;
}

void foo(int *x)
{
	*x = 6;
}

int main()
{
	// Node *root = new Node(1);

	// root->count++;

	// display(root);

	int y = 4;

	foo(&y);

	cout << y << endl;

	return 0;
}