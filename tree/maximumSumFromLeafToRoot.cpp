/*
Given a Binary Tree, find the maximum sum path from a leaf to root. For example, in the following tree, there are three leaf to root paths 8->-2->10, -4->-2->10 and 7->10. The sums of these three paths are 16, 4 and 17 respectively. The maximum of them is 17 and the path for maximum is 7->10.

                  10
               /      \
	     -2        7
           /   \     
	 8     -4    
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

long long maxSumLeafToRoot(binaryTree *root)
{
	if( root == NULL )
		return 0;

	long long leftMaxSum = maxSumLeafToRoot(root->left);
	long long rightMaxSum = maxSumLeafToRoot(root->right);

	if( leftMaxSum > rightMaxSum )
		return root->value + leftMaxSum;
	else
		return root->value + rightMaxSum;
}

int main()
{
	binaryTree *root= NULL;

   root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(7);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);

  printf("%lld\n",maxSumLeafToRoot(root));

	return 0;
}
