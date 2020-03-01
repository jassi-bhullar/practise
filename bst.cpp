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

class BST
{
private:
	Node *root;

	void printInorderUtil(Node *root)
	{
		if(root==NULL)
			return;

		printInorderUtil(root->left);
		cout << root->data << " ";
		printInorderUtil(root->right);
	}

	Node *insertUtil(int data, Node *root)
	{
		if(root==NULL)
			return new Node(data);

		if(data > root->data)
		{
			root->right = insertUtil(data, root->right);
		}
		else if(data < root->data)
		{
			root->left = insertUtil(data, root->left);
		}

		return root;
	}

	Node* inoderSuccessor(Node* root)
	{
		root = root->right;

		while(root->left != NULL)
		{
			root = root->left;
		}

		return root;
	}

	Node *deleteNodeUtil(int data, Node *root)
	{
		if(root==NULL)
			return root;

		if(data > root->data)
		{
			root->right = deleteNodeUtil(data, root->right);
		}
		else if(data < root->data)
		{
			root->left = deleteNodeUtil(data, root->left);
		}
		else 
		{
			Node *temp;

			// single or no child
			if(root->left == NULL)
			{
				temp = root->right;
				delete root;
				return temp;
			}
			else if(root->right == NULL)
			{
				temp = root->left;
				delete root;
				return temp;
			}

			temp = inoderSuccessor(root);
			
			root->data = temp->data;

			root->right = deleteNodeUtil(temp->data, root->right);

		}
		return root;
	}

public:
	BST()
	{
		root = NULL;
	}

	void insert(int data)
	{
		root = insertUtil(data, root);
	}

	void printInorder()
	{
		printInorderUtil(root);
		cout << endl;
	}

	void deleteNode(int data)
	{
		root = deleteNodeUtil(data, root);
	}
};

int main()
{
	BST bst;

	bst.insert(4);
	bst.insert(2);
	bst.insert(6);
	bst.insert(3);
	bst.insert(1);
	bst.insert(5);
	bst.insert(7);

	bst.printInorder();
	bst.deleteNode(4);
	bst.printInorder();

	return 0;
}