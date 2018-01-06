/*
Deepest left leaf node in a binary tree
Given a Binary Tree, find the deepest leaf node that is left child of its parent. For example, consider the following tree. The deepest left leaf node is the node with value 9.

       1
     /   \
    2     3
  /      /  \  
 4      5    6
        \     \
         7     8
        /       \
       9         10

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

binaryTree * deepestLeftChild=NULL;
int deepestHeight=0;

void findDeepestLeft(binaryTree *root,int currentHeight,bool isLeft)
{
	if(root == NULL)
		return ;
	if(root->left == NULL && root->right == NULL && isLeft)
	{
		if(currentHeight > deepestHeight)
		{
			deepestHeight = currentHeight;
			deepestLeftChild = root;
		}
	}
	findDeepestLeft(root->left,currentHeight+1,true);
	findDeepestLeft(root->right,currentHeight+1,false);

}

binaryTree* deepestLeftLeaf(binaryTree *root)
{
	findDeepestLeft(root,0,true);
	return deepestLeftChild;
}

int main()
{
    binaryTree* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->left->right = newNode(7);
    root->right->right->right = newNode(8);
    root->right->left->right->left = newNode(9);
    root->right->right->right->right = newNode(10);
 
    binaryTree *result = deepestLeftLeaf(root);
    if (result)
        cout << "The deepest left child is " << result-> value;
    else
        cout << "There is no left leaf in the given tree";
 
    return 0;
}