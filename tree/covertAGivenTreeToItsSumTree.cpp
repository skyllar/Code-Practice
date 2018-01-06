/*
Convert a given tree to its Sum Tree
Given a Binary Tree where each node has positive and negative values. Convert this to a tree where each node contains the sum of the left and right sub trees in the original tree. The values of leaf nodes are changed to 0.
For example, the following tree

                  10
               /      \
	     -2        6
           /   \      /  \ 
	 8     -4    7    5
should be changed to

                 20(4-2+12+6)
               /      \
	   4(8-4)      12(7+5)
           /   \      /  \ 
	 0      0    0    0
*/

#include<stdio.h>
#include<malloc.h>
#include<vector>
#include <limits.h>
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

long long convertGivenTreeToItsSumTree(binaryTree *root)
{
	if( root == NULL )
		return 0;
	long long temp = root->value;
	if( root ->left == NULL && root->right == NULL)
	{
		root->value = 0;
		return temp;
	}

	long long tempR = convertGivenTreeToItsSumTree(root->left);
	long long tempL =convertGivenTreeToItsSumTree(root->right);
	root->value = tempL+tempR;
	return temp+root->value;
}
void printInorder(binaryTree *node)
{
     if (node == NULL)
          return;
     printInorder(node->left);
     printf("%lld ", node->value);
     printInorder(node->right);
}
 

int main()
{
  binaryTree *root = NULL;
 
  /* Constructing tree given in the above figure */
  root = newNode(10);
  root->left = newNode(-2);
  root->right = newNode(6);
  root->left->left = newNode(8);
  root->left->right = newNode(-4);
  root->right->left = newNode(7);
  root->right->right = newNode(5);
 
  convertGivenTreeToItsSumTree(root);
 
  // Print inorder traversal of the converted tree to test result of toSumTree()
  printf("Inorder Traversal of the resultant tree is: \n");
  printInorder(root);
 
  getchar();
  return 0;
}