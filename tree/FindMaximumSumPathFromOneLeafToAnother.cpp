/*
Find the maximum path sum between two leaves of a binary tree
Given a binary tree in which each node element contains a number. Find the maximum possible sum from one leaf node to another.
The maximum sum path may or may not go through root. For example, in the following binary tree, the maximum sum is 27(3 + 6 + 9 + 0 – 1 + 10). Expected time complexity is O(n).

tree

A simple solution is to traverse the tree and do following for every traversed node X.
1) Find maximum sum from leaf to root in left subtree of X (we can use this post for this and next steps)
2) Find maximum sum from leaf to root in right subtree of X.
3) Add the above two calculated values and X->data and compare the sum with the maximum value obtained so far and update the maximum value.
4) Return the maximum value.
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

int maxTillNow=0;

int calculateMaxSum(binaryTree *root)
{
	if(!root)
		return 0;

	int lMaxSum = calculateMaxSum(root->left);
	int rmaxSum = calculateMaxSum(root->right);

	int currentMaxSum = lMaxSum + rmaxSum + root->value;
	
	if(currentMaxSum  > maxTillNow)
		maxTillNow = currentMaxSum;
	if(lMaxSum > rmaxSum)
		currentMaxSum = currentMaxSum - rmaxSum;
	else
		currentMaxSum = currentMaxSum - lMaxSum;
	return currentMaxSum;
}

int maxPathSum(binaryTree *root)
{
	calculateMaxSum(root);
	return maxTillNow;

}

int main()
{
    binaryTree *root = newNode(-15);
    root->left = newNode(5);
    root->right = newNode(6);
    root->left->left = newNode(-8);
    root->left->right = newNode(1);
    root->left->left->left = newNode(2);
    root->left->left->right = newNode(6);
    root->right->left = newNode(3);
    root->right->right = newNode(9);
    root->right->right->right= newNode(0);
    root->right->right->right->left= newNode(4);
    root->right->right->right->right= newNode(-1);
    root->right->right->right->right->left= newNode(10);
    cout << "Max pathSum of the given binary tree is " << maxPathSum(root);
    return 0;
}