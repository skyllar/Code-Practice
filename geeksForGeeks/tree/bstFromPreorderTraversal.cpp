/*
Construct BST from given preorder traversal | Set 1
Given preorder traversal of a binary search tree, construct the BST.

For example, if the given traversal is {10, 5, 1, 7, 40, 50}, then the output should be root of following tree.

     10
   /   \
  5     40
 /  \      \
1    7      50

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
	int value;
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

binaryTree* helper(int *pre,int *currentIndex,int min,int max,int size)
{
	if(*currentIndex >= size)
		return NULL;

	binaryTree *temp = NULL;
	int key = pre[*currentIndex]; 
	
	if( key >= min && key <= max)
	{
		temp = newNode(pre[*currentIndex]);
		(*currentIndex)++;
		temp->left = helper(pre,currentIndex,min,temp->value,size);
		temp->right = helper(pre,currentIndex,temp->value,max,size);
	}
	return temp;
}

binaryTree* constructTree(int *pre,int size)
{
	int currentIndex = 0;
	int min = INT_MIN;
	int max = INT_MAX;
	return helper(pre,&currentIndex,min,max,size);
}

void printInorder (binaryTree* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->value);
    printInorder(node->right);
}

int main ()
{
    int pre[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof( pre ) / sizeof( pre[0] );
 
    binaryTree* root = constructTree(pre, size);
 
    printf("Inorder traversal of the constructed tree: \n");
    printInorder(root);
 
    return 0;
}