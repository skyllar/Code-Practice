/*
Find the node with minimum value in a Binary Search Tree
*/

#include<stdio.h>
#include<malloc.h>
#include<queue>
using namespace std;

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

long long nodeWithMinValue(binaryTree *root)
{
	if( root->right == NULL && root-> left == NULL)
		return root->value;

	if( root -> left != NULL )
		return (nodeWithMinValue(root->left));
}

int main()
{
	binaryTree *root= NULL;

	root = newNode(4);
 	root->left        = newNode(2);
 	root->right       = newNode(5);
 	root->left->left  = newNode(1);
 	root->left->right = newNode(3);  

	printf("Min Value:%lld",nodeWithMinValue(root));

	return 0;
}