/*
Dynamic Programming | Set 26 (Largest Independent Set Problem)
Given a Binary Tree, find size of the Largest Independent Set(LIS) in it. A subset of all tree nodes is an independent set if there is no edge between any two nodes of the subset.
For example, consider the following binary tree. The largest independent set(LIS) is {10, 40, 60, 70, 80} and size of the LIS is 5.
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
	int liss;
	int value;
} binaryTree;

binaryTree* newNode(int data) 
{
  binaryTree* node = (binaryTree*)malloc(sizeof(binaryTree));
  node->value = data;
  node->left = NULL;
  node->right = NULL;
  node->liss == 0;
   
  return(node);
}



int largestIndependentSetInTree(binaryTree *root)
{
	if(!root)
		return 0;
	if( root->liss )
		return root->liss;

	int maxIncludingRoot=1;
	int maxExcludingRoot=0;

	maxExcludingRoot  = largestIndependentSetInTree(root->left) +largestIndependentSetInTree(root->right);
	
	if(root->left)
		maxIncludingRoot += largestIndependentSetInTree(root->left->left) + largestIndependentSetInTree(root->left->right);
	if(root->right)
		maxIncludingRoot += largestIndependentSetInTree(root->right->left) + largestIndependentSetInTree(root->right->right);

	return (root->liss = ((maxIncludingRoot > maxExcludingRoot)?maxIncludingRoot:maxExcludingRoot));
}

int main()
{
    // Let us construct the tree given in the above diagram
    binaryTree *root         = newNode(20);
    root->left                = newNode(8);
    root->left->left          = newNode(4);
    root->left->right         = newNode(12);
    root->left->right->left   = newNode(10);
    root->left->right->right  = newNode(14);
    root->right               = newNode(22);
    root->right->right        = newNode(25);
 
    printf ("Size of the Largest Independent Set is %d ", largestIndependentSetInTree(root));
 
    return 0;
}