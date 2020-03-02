#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left, *right;
	int height;

	Node(int val)
	{
		data = val;
		left = right = NULL;
		height = 1;
	}
};

class AVL
{
private:
	Node *root;

	void printInorder(Node* root)
	{
		if(root==NULL)
			return;

		printInorder(root->left);
		cout << root->data << " ";
		printInorder(root->right);
	}

	void printLevelOrder(Node *root)
	{
		if(root==NULL)
			return;

		queue<Node *> q;
		q.push(root);

		while(!q.empty())
		{
			Node *node = q.front();
			q.pop();
			cout << node->data << " ";

			if(node->left != NULL)
				q.push(node->left);
			
			if(node->right != NULL)
				q.push(node->right);
		}
		cout << endl;
	}

	int height(Node *root)
	{
		if(root==NULL)
			return 0;

		return root->height;
	}

	Node *rightRotate(Node *y)
	{
		Node *x = y->left;
		Node *t = x->right;

		// Perform rotation
		x->right = y;
		y->left = t;

		// Update heights
		y->height = 1 + max(height(y->left), height(y->right));
		x->height = 1 + max(height(x->left), height(x->right));

		return x;
	}

	Node *leftRotate(Node *x)
	{
		Node *y = x->right;
		Node *t = y->left;

		// Perform rotation
		y->left = x;
		x->right = t;

		// Update heights
		x->height = 1 + max(height(x->left), height(x->right));
		y->height = 1 + max(height(y->left), height(y->right));

		return y;
	}

	int getBalance(Node *root)
	{
		if(root==NULL)
			return 0;

		return height(root->left) - height(root->right);
	}

	Node *insert(int data, Node *root)
	{
		if(root==NULL)
			return new Node(data);

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

		// left left
		if(balance > 1 && data < root->left->data)
		{
			return rightRotate(root);
		}

		// right right
		if(balance < -1 && data > root->right->data)
		{
			return leftRotate(root);
		}

		// left right
		if(balance > 1 && data > root->left->data)
		{
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}

		// right left
		if(balance < -1 && data < root->right->data)
		{
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}

		return root;
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

	void printInorder()
	{
		printInorder(root);
		cout << endl;
	}

	void printLevelOrder()
	{
		printLevelOrder(root);
	}
};

int main()
{
	AVL avl;

	avl.insert(10);
	avl.insert(20);
	avl.insert(30);
	avl.insert(40);
	avl.insert(50);
	avl.insert(25);

	avl.printInorder();
	avl.printLevelOrder();

	return 0;
}