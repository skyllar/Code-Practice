/*
Check whether a given Binary Tree is Complete or not
Given a Binary Tree, write a function to check whether the given Binary Tree is Complete Binary Tree or not.

A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible. See following examples.

The following trees are examples of Complete Binary Trees
    1
  /   \
 2     3
  
       1
    /    \
   2       3
  /
 4

       1
    /    \
   2      3
  /  \    /
 4    5  6
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


queue<binaryTree *> myQueue;

bool isCompleteBT(binaryTree *root)
{
	myQueue.push(root);
	int flag = 0;

	while( !myQueue.empty() )
	{
		binaryTree *temp = myQueue.front();
		myQueue.pop();
		if(temp -> left == NULL && temp->right != NULL)
			return false;
		else
		{			
			if(flag == 0)
			{
				if(temp -> left == NULL && temp->right == NULL)
					flag == 1;
			}
			else
			{
				if(temp -> left != NULL && temp->right != NULL)
					return false;	
			}
			if(temp->left != NULL)
				myQueue.push(temp->left);
			if(temp->right != NULL)
			myQueue.push(temp->right);
		}
	}
	return true;
}	

int main()
{
   /* Let us construct the following Binary Tree which
      is not a complete Binary Tree
            1
          /   \
         2     3
        / \     \
       4   5     6
    */
 
  binaryTree *root  = newNode(1);
  root->left         = newNode(2);
  root->right        = newNode(3);
  root->left->left   = newNode(4);
  //root->left->right  = newNode(5);
  root->right->right = newNode(6);
 
  if ( isCompleteBT(root) == true )
      printf ("Complete Binary Tree");
  else
      printf ("NOT Complete Binary Tree");
 
  return 0;
}