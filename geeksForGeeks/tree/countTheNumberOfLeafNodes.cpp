/*
**************************GFG**************************
Program to count leaf nodes in a binary 
*/
#include<stdio.h>
#include<malloc.h>

typedef struct binaryTree
{
	struct binaryTree * left;
	struct binaryTree *	right;
	long long value;
} binaryTree;


binaryTree* newNode(int data) 
{
  binaryTree* node = (binaryTree*)
                       malloc(sizeof(binaryTree));
  node->value = data;
  node->left = NULL;
  node->right = NULL;
   
  return(node);
}

long long countLeafNodes(binaryTree *root)
{
	if( root == NULL )
		return 0;

	if ( root -> left == NULL && root -> right ==NULL )
		return 1;
	else
		return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main()
{
	binaryTree *root= NULL;
	long long leafNodes;

	root = newNode(1);
 	root->left        = newNode(2);
 	root->right       = newNode(3);
 	root->left->left  = newNode(4);
 	root->left->right = newNode(5);  

	leafNodes = countLeafNodes(root);

	printf("Number Of Leaves:%lld",leafNodes);

	return 0;
}