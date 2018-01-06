/*
Add all greater values to every node in a given BST
Given a Binary Search Tree (BST), modify it so that all greater values in the given BST are added to every node. For example, consider the following BST.

              50
           /      \
         30        70
        /   \      /  \
      20    40    60   80 

The above tree should be modified to following 

              260
           /      \
         330        150
        /   \       /  \
      350   300    210   80

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

binaryTree* insert(binaryTree* node, int data)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(data);
 
    /* Otherwise, recur down the tree */
    if (data <= node->value)
        node->left  = insert(node->left, data);
    else
        node->right = insert(node->right, data);
 
    /* return the (unchanged) node pointer */
    return node;
}

void inorder(binaryTree *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->value);
        inorder(root->right);
    }
}

void modify(binaryTree *root,int rootSum)
{
	if(root == NULL)
		return ;

	if(root->right!= NULL)
	{
		modify(root->right,0);	
		root->value += root->right->value;
	}

	root->value  += rootSum;

	modify(root->left,root->value);
}

void modifyBST(binaryTree *root)
{
	modify(root,0);	
}

int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    binaryTree *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
 
    modifyBST(root);
 
    // print inoder tarversal of the modified BST
    inorder(root);
 
    return 0;
}


