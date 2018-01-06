/*
Diameter of a Binary Tree
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

long long maxDiameter = 0;


long long diameterOfBinaryTree(binaryTree *root)
{
	if( root == NULL)
		return 0;

	long long leftHeight = diameterOfBinaryTree(root->left);
	long long rightHeight = diameterOfBinaryTree(root->right);

	if( 1+ leftHeight + rightHeight > maxDiameter )
		maxDiameter = 1+ leftHeight + rightHeight;

	if( leftHeight > rightHeight )
		return 1+ leftHeight;
	else
		return 1+rightHeight;

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

  diameterOfBinaryTree(root);
  printf("%lld\n",maxDiameter);

	return 0;
}