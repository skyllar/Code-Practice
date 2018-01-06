/*
Remove all nodes which don’t lie in any path with sum>= k
Given a binary tree, a complete path is defined as a path from root to a leaf. The sum of all nodes on that path is defined as the sum of that path. Given a number K, you have to remove (prune the tree) all nodes which don’t lie in any path with sum>=k.

Note: A node can be part of multiple paths. So we have to delete it only in case when all paths from it have sum less than K.

Consider the following Binary Tree
          1 
      /      \
     2        3
   /   \     /  \
  4     5   6    7
 / \    /       /
8   9  12      10
   / \           \
  13  14         11
      / 
     15 

For input k = 20, the tree should be changed to following
(Nodes with values 6 and 8 are deleted)
          1 
      /      \
     2        3
   /   \        \
  4     5        7
   \    /       /
    9  12      10
   / \           \
  13  14         11
      / 
     15 

For input k = 45, the tree should be changed to following.
      1 
    / 
   2   
  / 
 4  
  \   
   9    
    \   
     14 
     /
    15 


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

void print(binaryTree *root)
{
    if (root != NULL)
    {
        print(root->left);
        printf("%d ",root->value);
        print(root->right);
    }
}

void modifyTree(binaryTree *root,int sum,int sumTillNow,binaryTree **address)
{
	if(root == NULL)
		return;
	modifyTree(root->left,sum,sumTillNow+root->value,&root->left);
	modifyTree(root->right,sum,sumTillNow+root->value,&root->right);
	
	if(root->left == NULL && root->right ==NULL && sumTillNow + root->value < sum)
		(*address) = NULL;
}

void prune(binaryTree *root,int sum)
{
	modifyTree(root,sum,0,&root);
}

int main()
{
    int k = 20;
    binaryTree *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);
    root->left->right->left = newNode(12);
    root->right->right->left = newNode(10);
    root->right->right->left->right = newNode(11);
    root->left->left->right->left = newNode(13);
    root->left->left->right->right = newNode(14);
    root->left->left->right->right->left = newNode(15);
 
    printf("Tree before truncation\n");
    print(root);
 
    prune(root, k); // k is 45
 
    printf("\n\nTree after truncation\n");
    print(root);
 
    return 0;
}