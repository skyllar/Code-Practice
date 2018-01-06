/*
 * Convert Binary tree to linked list.cpp
 *
 *  Created on: Dec 1, 2014
 *      Author: Apratim
 */
/*
 Convert a given Binary Tree to Doubly Linked List | Set 1
 Given a Binary Tree (Bt), convert it to a Doubly Linked List(DLL). The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL. The order of nodes in DLL must be same as Inorder of the given Binary Tree. The first node of Inorder traversal (left most node in BT) must be head node of the DLL.

 TreeToList
 */
#include <cstdio>
#include <iostream>
using namespace std;

#define TRACE
#define DEBUG
#ifdef TRACE
#define trace1(x)                cerr <<"\n"<< #x << ": " << x << endl;
#define trace2(x, y)             cerr<<"\n" << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr<<"\n" << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr <<"\n"<< #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr <<"\n"<< #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr <<"\n"<< #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif

#define si(x) scanf("%d" , &x)
#define sl(x) scanf("%ld" , &x)
#define sll(x) scanf("%lld" , &x)
#define sc(x) scanf("%c" , &x)
#define ss(x) scanf("%s" , &x)

#define pi(x) printf("%d\n" , x)
#define pl(x) printf("%ld\n" , x)
#define pll(x) printf("%lld\n" , x)
#define pc(x) printf("%c\n" , x)
#define ps(x) printf("%s\n" , x)

#define fup(i,a,b) for(int i=a;i<b;i++)
#define fdn(i,a,b) for(int i=a;i>=b;i--)

#define gc getchar
#define ll long long

typedef struct node {
	node* left;
	node* right;
	int data;
} node;

node *bintree2list(node *root, int side) {

	if (root == NULL) {
		return NULL;
	} else {
		node *tempRight = bintree2list(root->right, 0);
		root->right = tempRight;
		if (tempRight != NULL)
			tempRight->left = root;

		node *tempLeft = bintree2list(root->left, 1);
		root->left = tempLeft;
		if (tempLeft != NULL)
			tempLeft->right = root;

		if (side == 1) {
			node *temp = root;
			while (temp->right != NULL)
				temp = temp->right;

			return temp;
		} else {
			node *temp = root;
			while (temp->left != NULL)
				temp = temp->left;
			return temp;
		}
	}
}

node* newNode(int data) {
	node* new_node = new node;
	new_node->data = data;
	new_node->left = new_node->right = NULL;
	return (new_node);
}

/* Function to print nodes in a given doubly linked list */
void printList(node *node) {
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->right;
	}
}

/* Driver program to test above functions*/
int main() {
	// Let us create the tree shown in above diagram
	node *root = newNode(10);
	root->left = newNode(12);
	root->right = newNode(15);
	root->left->left = newNode(25);
	root->left->right = newNode(30);
	root->right->left = newNode(36);

	// Convert to DLL
	node *head = bintree2list(root, 0);

	// Print the converted list
	printList(head);

	return 0;
}
