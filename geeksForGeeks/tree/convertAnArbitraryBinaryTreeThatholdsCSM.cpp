/*
Convert an arbitrary Binary Tree to a tree that holds Children Sum Property
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

void recursivelyIncrement( binaryTree *root)
{
	if( root->left == NULL && root -> right == NULL )
		return;
	if( root->left == NULL && root -> right != NULL )
	{	
		root->right->value  = root ->value;
		return recursivelyIncrement(root->right);
	}
	if( root->left != NULL && root -> right == NULL )
	{	
		root->left->value  = root ->value;
		return recursivelyIncrement(root->left);
	}	

	if( root)
	root->left->value = root->value - root->right->value;
	return recursivelyIncrement(root->left);

}

void covertBinaryTreeIntoCSM(binaryTree *root)
{

	if( root == NULL || ( root->left == NULL && root->right == NULL ) )
		return ;

	covertBinaryTreeIntoCSM(root->left);
	covertBinaryTreeIntoCSM(root->right);
	long long sum = 0;

	if( root->left != NULL)
		sum += root->left->value;
	if( root->right != NULL)
		sum += root->right->value;

	if( sum > root->value)
		root->value = sum;
	else
	{	
		recursivelyIncrement(root);
	}
}

void printInorder(binaryTree *root)
{
	if( root == NULL)
		return ;
	printInorder(root->left);
	printf("%lld ",root->value);
	printInorder(root->right);
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

	covertBinaryTreeIntoCSM(root);

	printInorder(root);

	return 0;
}