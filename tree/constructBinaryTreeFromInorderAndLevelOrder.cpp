/*
Construct a tree from Inorder and Level order traversals
Given inorder and level-order traversals of a Binary Tree, construct the Binary Tree. Following is an example to illustrate the problem.
*/


#include<stdio.h>
#include<malloc.h>
#include<vector>
#include<iostream>
using namespace std;

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

void printInorder(binaryTree* node)
{
    if (node == NULL)
       return;
    printInorder(node->left);
    cout << node->value << " ";
    printInorder(node->right);
}

int findIndex(int *levelOrder,int *inorder,int start,int end,int size)
{
	for(int j = 0 ; j<size;j++)
	{
		for(int i=start;i<=end;i++)
			if(inorder[i] == levelOrder[j])
				return i;
	}		
	return -1;
}

binaryTree *build(int *inorder,int *levelOrder,int start,int end,int size)
{
	if(start > end)
		return NULL;


	int mid  = findIndex(levelOrder ,inorder,start,end,size);
	binaryTree *root = newNode(inorder[mid]);
	root->left = build(inorder,levelOrder,start,mid-1,size);
	root->right = build(inorder,levelOrder,mid+1,end,size);

	return root;
}

binaryTree* buildTree(int *inorder,int *levelOrder,int start,int end,int size)
{
	return build(inorder,levelOrder,start,end,size);
}

int main()
{
    int in[]    = {4, 8, 10, 12, 14, 20, 22};
    int level[] = {20, 8, 22, 4, 12, 10, 14};
    int n = sizeof(in)/sizeof(in[0]);
    binaryTree *root = buildTree(in, level, 0, n - 1, n);
 
    /* Let us test the built tree by printing Insorder traversal */
    cout << "Inorder traversal of the constructed tree is \n";
    printInorder(root);
 
    return 0;
}