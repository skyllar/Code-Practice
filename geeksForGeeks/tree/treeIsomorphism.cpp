/*
Tree Isomorphism Problem
Write a function to detect if two trees are isomorphic. Two trees are called isomorphic if one of them can be obtained from other by a series of flips, i.e. by swapping left and right children of a number of nodes. Any number of nodes at any level can have their children swapped. Two empty trees are isomorphic.

For example, following two trees are isomorphic with following sub-trees flipped: 2 and 3, NULL and 6, 7 and 8.
ISomorphicTrees


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

bool isomorphic(binaryTree *root1,binaryTree *root2)
{
	if(root1 == NULL && root2 == NULL)
		return true;
	if(root1== NULL || root2 == NULL)
		return false;
	if(root1->value !=root2->value)
		return false;
	else
	{
		return ((isomorphic(root1->left,root2->left) && isomorphic(root1->right,root2->right)) || (isomorphic(root1->left,root2->right) && isomorphic(root1->right,root2->left)));
	}
}

int main()
{
    // Let us create trees shown in above diagram
    binaryTree *n1 = newNode(1);
    n1->left        = newNode(2);
    n1->right       = newNode(3);
    n1->left->left  = newNode(4);
    n1->left->right = newNode(5);
    n1->right->left  = newNode(6);
    n1->left->right->left = newNode(7);
    n1->left->right->right = newNode(8);
 
    binaryTree *n2 = newNode(1);
    n2->left         = newNode(3);
    n2->right        = newNode(2);
    n2->right->left   = newNode(4);
    n2->right->right   = newNode(5);
    n2->left->right   = newNode(6);
    n2->right->right->left = newNode(8);
    n2->right->right->right = newNode(7);
 
    if ((isomorphic(n1,n2)) == true)
       cout << "Yes";
    else
      cout << "No";
 
    return 0;
}