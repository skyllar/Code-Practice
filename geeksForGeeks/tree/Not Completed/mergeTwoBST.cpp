/*
Merge two BSTs with limited extra space

Given two Binary Search Trees(BST), 
print the elements of both BSTs in sorted form. 
The expected time complexity is O(m+n) where m is the number of nodes in first tree and n is the number
of nodes in second tree. Maximum allowed auxiliary space is O(height of the first tree + height of the second tree).
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

void printInorder(binaryTree *root)
{
	if(root == NULL)
		return ;
	printInorder(root->left);
	printf("%lld ",root->value);
	printInorder(root->right);

}	

void mergeTwoBST(binaryTree *root1,binaryTree *root2)
{
	if( root1 == NULL )
		return printInorder(root2);
	if(root2 == NULL)
		return printInorder(root1);

	if( root1->value < root2->value)
	{
		//printInorder(root1->left);
		mergeTwoBST(root1,root2->left,0);
		printf("%lld ",root2->value);
		if(root1->right->value < root2->value)
		{
			printf("%lld ", root1->right->value);
			return mergeTwoBST(root1->right,root2);
		}
	}
	else
	{
		mergeTwoBST(root1->left,root2);
		//printInorder(root2->left);
		printf("%lld ",root1->value);
		//return mergeTwoBST(root1->right,root2->right);
	}
}

///wrong.................................
void mergeTwoBSTNew(binaryTree *root1,binaryTree *root2)
{
	if( root1 == NULL )
		return printInorder(root2);
	if( root2 == NULL)
		return printInorder(root1);

	mergeTwoBST(root1->left,root2->left);
		if( root1->value > root2->value )
		{
			printf("%lld ", root2->value);
		}
	mergeTwoBST(root1->right,root2->right);

}

int main()
{
    binaryTree  *root1 = NULL, *root2 = NULL;

    /* Let us create the following tree as first tree
            3
          /  \
         1    5
     */
    root1 = newNode(3);
    root1->left = newNode(1);
    root1->right = newNode(5);

    /* Let us create the following tree as second tree
            4
          /  \
         2    6
     */
    root2 = newNode(4);
    root2->left = newNode(2);
    root2->right = newNode(6);

 	mergeTwoBST(root1,root2);

	return 0;
}