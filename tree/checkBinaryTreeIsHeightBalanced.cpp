/*
How to determine if a binary tree is height-balanced?

*/

#include<stdio.h>
#include<malloc.h>
#include<vector>
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
long long flag =0;

long long checkBinaryTreeIsHeightBalanced(binaryTree *root)
{
	if( root == NULL )
		return 0;

	long long heightLeft = checkBinaryTreeIsHeightBalanced(root -> left);
	long long heightRight = checkBinaryTreeIsHeightBalanced(root -> right);

	long long diff = heightLeft - heightRight;
	if( diff >= 1 && diff <= -1)
		flag = 1;
	if( diff > 0)
		return 1 + heightLeft;
	else
		return 1 + heightRight;
}

int main()
{
	binaryTree *root= NULL;

  root = newNode(50);
  root->left        = newNode(7);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right = newNode(5);
  root->right->left  = newNode(1);
  root->right->right = newNode(30); 

  checkBinaryTreeIsHeightBalanced(root);
  //printf("%lld\n",maxDiameter);
  printf("%lld",flag);
	return 0;
}