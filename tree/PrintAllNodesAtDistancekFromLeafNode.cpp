/*
Print all nodes that are at distance k from a leaf node
Given a Binary Tree and a positive integer k, print all nodes that are distance k from a leaf node.

Here the meaning of distance is different from previous post. Here k distance from a leaf means k levels higher than a leaf node. For example if k is more than height of Binary Tree, then nothing should be printed. Expected time complexity is O(n) where n is the number nodes in the given Binary Tree.
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


int findDistance(binaryTree *root,int myLevel,int distance)
{
	//if(root == NULL)
	//	return myLevel;

	int leftLastLevel=-1,rightLastLevel=-1;

	if(root->left)
		leftLastLevel=findDistance(root->left,myLevel+1,distance) - myLevel;
	if(root->right)
		rightLastLevel=findDistance(root->right,myLevel+1,distance) -myLevel;

	printf("\nleftLastLevel:%d,rightLastLevel:%d,root:%d\n",leftLastLevel,rightLastLevel,root->value);

	if(leftLastLevel == distance || rightLastLevel == distance)
		printf("***%d \n",root->value);

	return myLevel;
}

void printKDistantfromLeaf(binaryTree *root,int distance)
{
	findDistance(root,0,distance);
}

int main()
{
    // Let us create binary tree given in the above example
    binaryTree * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
 
    cout << "Nodes at distance 2 are: ";
    printKDistantfromLeaf(root, 2);
 
    return 0;
}
