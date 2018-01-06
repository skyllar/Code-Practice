/*
Find the largest BST subtree in a given Binary Tree
Given a Binary Tree, write a function that returns the size of the largest subtree which is also a Binary Search Tree (BST). If the complete Binary Tree is BST, then return the size of whole tree.

Examples:

Input: 
      5
    /  \
   2    4
 /  \
1    3

Output: 3 
The following subtree is the maximum size BST subtree 
   2  
 /  \
1    3
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

void utility(binaryTree *root,long long *min,long long *max,bool *isBST,long long *maxSize)
{
	if( root == NULL)
	{
		*isBST = true;
		*maxSize=0;
		return;
	}

	bool isLeft=false,isRight=false;

	long long maxSizeLeft=0;
	long long maxSizeRight=0;

	long long leftMinL=INT_MAX;
	long long rightMaxL=INT_MIN;

	long long leftMinR=INT_MAX;
	long long rightMaxR=INT_MIN;

	utility(root->left,&leftMinL,&rightMaxL,&isLeft,&maxSizeLeft);
	utility(root->right,&leftMinR,&rightMaxR,&isRight,&maxSizeRight);

	if(isLeft && isRight && root->value >= rightMaxL && root->value <= leftMinR)
	{
		*isBST= true;
		*min = root->left? leftMinL:root->value;
		*max = root->right? rightMaxR:root->value;
		*maxSize = maxSizeRight + maxSizeLeft + 1;
	}
	else
	{		
		*isBST =false;
		*maxSize = (maxSizeLeft > maxSizeRight) ? maxSizeLeft:maxSizeRight;
	}
}

long long findLargestBSTSubTreeInBinaryTree(binaryTree *root)
{
	long long min = INT_MAX;
	long long max = INT_MIN;
	bool isBST=false;
	long long maxSize=0;

	utility(root,&min,&max,&isBST,&maxSize);
	return maxSize;		
}

int main()
{
     /* Let us construct the following Tree
          50
       /      \
     10        60
    /  \       /  \
   5   20    55    70
            /     /  \
          45     65    80
  */
 
  binaryTree *root = newNode(50);
  root->left        = newNode(10);
  root->right       = newNode(60);
  root->left->left  = newNode(5);
  root->left->right = newNode(20);
  root->right->left  = newNode(55);
  root->right->left->left  = newNode(45);
  root->right->right = newNode(70);
  root->right->right->left = newNode(65);
  root->right->right->right = newNode(80);
 
  /* The complete tree is not BST as 45 is in right subtree of 50.
     The following subtree is the largest BST
        60
      /  \
    55    70
   /     /  \
  5     65    80
  */
  printf(" Size of the largest BST is %lld", findLargestBSTSubTreeInBinaryTree(root));
  return 0;
}