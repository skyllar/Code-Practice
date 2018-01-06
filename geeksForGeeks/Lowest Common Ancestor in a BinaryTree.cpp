/* Program to find LCA of n1 and n2 using one traversal of Binary Tree.
 It handles all cases even when n1 or n2 is not there in Binary Tree */
#include <iostream>
using namespace std;

// A Binary Tree Node
struct Node {
	struct Node *left, *right;
	int key;
};

// Utility function to create a new tree Node
Node* newNode(int key) {
	Node *temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
}

Node* findLCA(Node *root, int a, int b) {

	if (root = NULL)
		return NULL;
	if (root->key == a || root->key == b) {
		return root;
	}
	Node *l = findLCA(root->left, a, b);
	Node *r = findLCA(root->right, a, b);

	if (l && r)
		return root;

	if (l != NULL)
		return l;
	else
		return r;
}

// Driver program to test above functions
int main() {
	// Let us create binary tree given in the above example
	Node * root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	Node *lca = findLCA(root, 4, 5);
	if (lca != NULL)
		cout << "LCA(4, 5) = " << lca->key;
	else
		cout << "Keys are not present ";

	lca = findLCA(root, 4, 10);
	if (lca != NULL)
		cout << "\nLCA(4, 10) = " << lca->key;
	else
		cout << "\nKeys are not present ";

	return 0;
}
