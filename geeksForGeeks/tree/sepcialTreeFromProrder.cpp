/*
Construct a special tree from given preorder traversal
Given an array ‘pre[]‘ that represents Preorder traversal of a spacial binary tree where every node has either 0 or 2 children. One more array ‘preLN[]‘ is given which has only two possible values ‘L’ and ‘N’. The value ‘L’ in ‘preLN[]‘ indicates that the corresponding node in Binary Tree is a leaf node and value ‘N’ indicates that the corresponding node is non-leaf node. Write a function to construct the tree from the given two arrays.

Source: Amazon long longerview Question

Example:

Input:  pre[] = {10, 30, 20, 5, 15},  preLN[] = {'N', 'N', 'L', 'L', 'L'}
Output: Root of following tree
          10
         /  \
        30   15
       /  \
      20   5
The first element in pre[] will always be root. So we can easily figure out root. If left subtree is empty, the right subtree must also be empty and preLN[] entry for root must be ‘L’. We can simply create a node and return it. If left and right subtrees are not empty, then recursively call for left and right subtrees and link the returned nodes to root.
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

binaryTree* newNode(long long data) 
{
  binaryTree* node = (binaryTree*)
                       malloc(sizeof(binaryTree));
  node->value = data;
  node->left = NULL;
  node->right = NULL;
   
  return(node);
}

binaryTree *constructTree(long long *preorder,char *preN,long long size,long long *index)
{
	if(*index == size)
		return NULL;

	binaryTree *root = newNode(preorder[*(index)]);
	(*index)++;
	if(preN[*(index)-1] == 'N')
	{
		root->left = constructTree(preorder,preN,size,index);
		root->right = constructTree(preorder,preN,size,index);
	}
	return root;
}

void printInorder (binaryTree* node)
{
    if (node == NULL)
        return;
 
    /* first recur on left child */
    printInorder (node->left);
 
    /* then print the data of node */
    printf("%lld ", node->value);
 
    /* now recur on right child */
    printInorder (node->right);
}

int main()
{
    binaryTree *root = NULL; 
 
    /* Constructing tree given in the above figure
          10
         /  \
        30   15
       /  \
      20   5 */
    long long pre[] = {10, 30, 20, 5, 15};
    char preN[] = {'N', 'N', 'L', 'L', 'L'};
    long long n = sizeof(pre)/sizeof(pre[0]);
 	long long index=0;
    // construct the above tree
    root = constructTree (pre, preN, n,&index);
 	
    // Test the constructed tree
    printf("Following is Inorder Traversal of the Constructed Binary Tree: \n");
    printInorder(root);
 
    return 0;
}