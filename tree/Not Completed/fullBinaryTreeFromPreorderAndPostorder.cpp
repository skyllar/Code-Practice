/*
Construct Full Binary Tree from given preorder and postorder traversals
Given two arrays that represent preorder and postorder traversals of a full binary tree, construct the binary tree.

A Full Binary Tree is a binary tree where every node has either 0 or 2 children

Following are examples of Full Trees.

        1
      /   \
    2       3
  /  \     /  \
 4    5   6    7


       1
     /   \
   2      3
        /   \  
       4     5
           /   \  
          6    7
                  

          1
        /   \
      2       3
    /  \     /  \
   4    5   6    7
 /  \  
8    9 

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
  binaryTree* node = (binaryTree*)malloc(sizeof(binaryTree));
  node->value = data;
  node->left = NULL;
  node->right = NULL;
   
  return(node);
}


binaryTree *fullBinaryTreeFromPreorderAndPostorder(int *pre,int *post,int size,int beg,int end,int *index)
{
	if(*index >= size)
		return NULL;

	binaryTree *root = NULL;
	
	if(beg <= end)
	{
		 root = newNode(pre[*index]);
		 (*index) ++;
		 int i;
		for(i=beg;i<=end;i++)
		{
			if(pre[*index] == post[i])
				break;
		}

		

		root->left = fullBinaryTreeFromPreorderAndPostorder(pre,post,size,beg,i-1,index);
		root->right = fullBinaryTreeFromPreorderAndPostorder(pre,post,size,i+1,end,index);
	}
	return root;
}

binaryTree* leader(int *pre,int *post, int size)
{
	int index = 0;
	return fullBinaryTreeFromPreorderAndPostorder(pre,post,size,0,size-1,&index);
}


void printInorder (binaryTree* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->value);
    printInorder(node->right);
}
 
// Driver program to test above functions
int main ()
{
    int pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};
    int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
    int size = sizeof( pre ) / sizeof( pre[0] );
 
    binaryTree *root = leader(pre, post, size);
 
    printf("Inorder traversal of the constructed tree: \n");
    printInorder(root);
 
    return 0;
}