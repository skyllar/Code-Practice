/*
The Great Tree-List Recursion Problem.

Question:
Write a recursive function treeToList(Node root) that takes an ordered binary tree and rearranges the internal pointers to make a circular doubly linked list out of the tree nodes. The”previous” pointers should be stored in the “small” field and the “next” pointers should be stored in the “large” field. The list should be arranged so that the nodes are in increasing order. Return the head pointer to the new list.
*/

#include<stdio.h>
#include<malloc.h>
#include<queue>
using namespace std;

typedef struct binaryTree
{
	struct binaryTree * left;
	struct binaryTree *	right;
	long long value;
} binaryTree;

typedef struct doublyLinkedList
{
	struct doublyLinkedList * prev;
	struct doublyLinkedList * next;
	long long value;
} doublyLinkedList;


binaryTree* newNode(int data) 
{
  binaryTree* node = (binaryTree*)
                       malloc(sizeof(binaryTree));
  node->value = data;
  node->left = NULL;
  node->right = NULL;
   
  return(node);
}

doublyLinkedList * convertBSTIntoDoubleLL(treeRoot)
{
	if ( treeRoot -> left == NULL && tree -->right == NULL )
	{
		return treeRoot->value;
	}

	convertBSTIntoDoubleLL(treeRoot -> left);

	//--------------------------------

	convertBSTIntoDoubleLL(treeRoot -> right);
}

void printDoublyLinkedList(doublyLinkedList *doublyRoot)
{
	while( doublyRoot != NULL)
	{
		printf("%lld ",doublyRoot->value);
		doublyRoot = doublyRoot -> next;
	}
}

int main()
{
	binaryTree *treeRoot= NULL;
	doublyLinkedList *doublyRoot=NULL;

	treeRoot = newNode(4);
 	treeRoot->left        = newNode(2);
 	treeRoot->right       = newNode(5);
 	treeRoot->left->left  = newNode(1);
 	treeRoot->left->right = newNode(3); 

	doublyRoot = convertBSTIntoDoubleLL(treeRoot);

	printDoublyLinkedList(doublyRoot);

	return 0;
}