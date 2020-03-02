#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	int count;
	int height;
	struct Node *left, *right;

	Node(int data)
	{
		this->data = data;
		count = 1;
		height = 1;
		left = right = NULL;
	}
};

class AVL
{
private:
	Node *root;

	int height(Node *root)
	{
		if(root==NULL)
			return 0;

		return root->height;
	}

	int getBalance(Node *root)
	{
		if(root==NULL)
			return 0;

		return height(root->left) - height(root->right);
	}

	Node *rightRotate(Node *y)
	{
		Node *x = y->left;
		Node *t = x->right;

		y->left = t;
		x->right = y;

		y->height = 1 + max(height(y->left), height(y->right));
		x->height = 1 + max(height(x->left), height(x->right));

		return x;
	}

	Node *leftRotate(Node *x)
	{
		Node *y = x->right;
		Node *t = y->left;

		x->right = t;
		y->left = x;

		x->height = 1 + max(height(x->left), height(x->right));
		y->height = 1 + max(height(y->left), height(y->right));

		return y;
	}

	Node *insert(int data, Node *root)
	{
		if(root==NULL)
			return new Node(data);

		if(data == root->data) 
	    { 
	        (root->count)++; 
	        return root; 
	    } 

		if(data > root->data)
		{
			root->right = insert(data, root->right);
		}
		else if(data < root->data)
		{
			root->left = insert(data, root->left);
		}

		root->height = 1 + max(height(root->left), height(root->right));

		int balance = getBalance(root);

		// LL
		if(balance > 1 && data < root->left->data)
		{
			return rightRotate(root);
		}
		
		// LR
		if(balance > 1 && data > root->left->data)
		{
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}
		
		// RR
		if(balance < -1 && data > root->right->data)
		{
			return leftRotate(root);
		}
		
		// RL
		if(balance < -1 && data < root->right->data)
		{
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}
		
		return root;
	}

	void storeNodesInOrder(int *arr, Node *root, int *index_count)
	{
		if(root==NULL)
			return;

		storeNodesInOrder(arr, root->left, index_count);

		for(int i=0; i < root->count; i++)
		{
			arr[(*index_count)] = root->data;
			(*index_count)++;
		}

		storeNodesInOrder(arr, root->right, index_count);
	}

public:
	AVL()
	{
		root = NULL;
	}

	void insert(int data)
	{
		root = insert(data, root);
	}

	void storeNodesInOrder(int *arr)
	{
		int index_count = 0;
		storeNodesInOrder(arr, root, &index_count);
	}
};

void sort(int *arr, int n)
{
	AVL avl;
	for (int i = 0; i < n; ++i)
	{
		avl.insert(arr[i]);
	}

	avl.storeNodesInOrder(arr);
}

void printArr(int *arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
}

int main()
{
	int arr[] = {100, 12, 100, 1, 1, 12, 100, 1, 12, 100, 1, 1}; 
	int n = sizeof(arr)/sizeof(arr[0]); 

	cout << "Input array is\n"; 
	printArr(arr, n); 

	sort(arr, n); 

	cout << "Sorted array is\n"; 
	printArr(arr, n); 

	return 0;
}