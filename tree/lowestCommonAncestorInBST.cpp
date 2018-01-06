/*
Lowest Common Ancestor in a Binary Search Tree.
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

long long lowestCommonAncestorInBST(binaryTree *root,long long val1,long long val2)
{
	if( root->value == val1 )
		return val1;
	if( root -> value == val2)
		return val2;

	if( val1 < root -> value && val2 < root->value )
		return lowestCommonAncestorInBST(root -> left,val1,val2);

	if( val1 > root -> value && val2 > root->value )
		return lowestCommonAncestorInBST(root -> right,val1,val2);

	return root->value;
}

int main()
{
	binaryTree *root= NULL;


	root = newNode(4);
 	root->left        = newNode(2);
 	root->right       = newNode(5);
 	root->left->left  = newNode(1);
 	root->left->right = newNode(3); 

	printf("%lld\n",lowestCommonAncestorInBST(root,,3));

	return 0;
}