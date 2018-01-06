/*
Boundary Traversal of binary tree
Given a binary tree, print boundary nodes of the binary tree Anti-Clockwise starting from the root. For example, boundary traversal of the following tree is “20 8 4 10 14 25 22″


We break the problem in 3 parts:
1. Print the left boundary in top-down manner.
2. Print all leaf nodes from left to right, which can again be sub-divided into two sub-parts:
…..2.1 Print all leaf nodes of left sub-tree from left to right.
…..2.2 Print all leaf nodes of right subtree from left to right.
3. Print the right boundary in bottom-up manner.


*/

#include<stdio.h>
#include<malloc.h>
#include<vector>
#include <limits.h>
using namespace std;
#include<queue>


typedef struct binaryTree
{
	struct binaryTree * left;
	struct binaryTree *	right;
	long long value;
} binaryTree;

binaryTree* newNode(long long data) 
{
  binaryTree* node = (binaryTree*)
                       malloc(sizeof(binaryTree));
  node->value = data;
  node->left = NULL;
  node->right = NULL;
   
  return(node);
}

void printLeftMostBoundary(binaryTree *root)
{
	if(root == NULL)
		return;
	if(root->left != NULL || root->right !=NULL)
		printf("%lld ",root->value);
	if(root->left != NULL)
		printLeftMostBoundary(root->left);
	else if(root->right != NULL)
		printLeftMostBoundary(root->right);
}

void printLeafNodes(binaryTree *root)
{
	if(root == NULL)
		return;
	printLeafNodes(root->left);
	printLeafNodes(root->right);

	if(root->left == NULL && root->right == NULL)
		printf("%lld ",root->value);
}

void printRightMostBoundaryBottomUp(binaryTree *root)
{
	if(root == NULL)
		return;
	if(root->right != NULL)
		printLeftMostBoundary(root->right);
	else if(root->left != NULL)
		printLeftMostBoundary(root->left);	

	if(root->left != NULL || root->right !=NULL)
		printf("%lld ",root->value);
}

void printBoundary(binaryTree *root)
{
	printf("%lld ",root->value);
	printLeftMostBoundary(root->left);
	printLeafNodes(root);
	printRightMostBoundaryBottomUp(root->right);
}

int main()
{
    // Let us construct the tree given in the above diagram
    binaryTree *root          = newNode(20);
    root->left                = newNode(8);
    root->left->left          = newNode(4);
    root->left->right         = newNode(12);
    root->left->right->left   = newNode(10);
    root->left->right->right  = newNode(14);
    root->right               = newNode(22);
    root->right->right        = newNode(25);
 
    printBoundary( root );
 
    return 0;
}