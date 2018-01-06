/*
Remove BST keys outside the given range
Given a Binary Search Tree (BST) and a range [min, max], remove all keys which are outside the given range. The modified tree should also be BST. For example, consider the following BST and range [-10, 13]. 
*/


#include<iostream>
#include<stdio.h>
#include<malloc.h>
#include<queue>
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

void inorderTraversal(binaryTree* root)
{
    if (root)
    {
        inorderTraversal( root->left );
        cout << root->value<< " ";
        inorderTraversal( root->right );
    }
}

void removeOutsideRange(binaryTree **root,int low,int high)
{
	if(*root)
	{
		if((*root)->value <=high && (*root)->value >= low)
		{	
			removeOutsideRange(&((*root)->left),low,high);
			removeOutsideRange(&((*root)->right),low,high);	
		}
		else
		{
			if((*root)->value > high)
			{
				(*root)->right = NULL;
				(*root) = (*root)->left;
			}
			else
			{
				(*root)->left = NULL;
				(*root) = (*root)->right;
			}
			removeOutsideRange(root,low,high);
		}
	}
}
binaryTree* insert(binaryTree* root, int key)
{
    if (root == NULL)
       return newNode(key);
    if (root->value > key)
       root->left = insert(root->left, key);
    else
       root->right = insert(root->right, key);
    return root;
}

int main()
{
    binaryTree* root = NULL;
    root = insert(root, 6);
    root = insert(root, -13);
    root = insert(root, 14);
    root = insert(root, -8);
    root = insert(root, 15);
    root = insert(root, 13);
    root = insert(root, 7);
 
    cout << "Inorder traversal of the given tree is: ";
    inorderTraversal(root);
    removeOutsideRange(&root, -20, -17);
 
    cout << "\nInorder traversal of the modified tree is: ";
    inorderTraversal(root);
 
    return 0;
}