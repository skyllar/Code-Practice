/*
Given a binary tree, print out all of its root-to-leaf paths one per line
*/

#include<stdio.h>
#include<malloc.h>
#include<queue>
using namespace std;
#include<vector>

int path[1000];


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

void printAllPathUptoLeaf(binaryTree *root,int index)
{
	int i;
	if ( root == NULL)
		return ;
	

	if( root->left == NULL && root -> right == NULL)
	{
		for( i = 0  ; i <= index ; i ++)
		{
			printf ( "%d ",path[i]);
		}
		printf ("\n");
	}
	else
	{	
		path[index] = root ->value;
		index ++;
		printAllPathUptoLeaf(root -> left,index);
		printAllPathUptoLeaf(root -> right,index);
	}
}

int main()
{
	binaryTree *root= NULL;


	root = newNode(1);
 	root->left        = newNode(2);
 	root->right       = newNode(3);
 	root->left->left  = newNode(4);
 	root->left->right = newNode(5); 

	printAllPathUptoLeaf(root,0);

	return 0;
}