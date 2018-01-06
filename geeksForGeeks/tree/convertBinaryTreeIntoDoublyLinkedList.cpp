/*
Convert a given Binary Tree to Doubly Linked List | Set 1
Given a Binary Tree (Bt), convert it to a Doubly Linked List(DLL). The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL. The order of nodes in DLL must be same as Inorder of the given Binary Tree. The first node of Inorder traversal (left most node in BT) must be head node of the DLL.
*/


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


binaryTree *prev = NULL;
binaryTree *dll = NULL;

binaryTree* newNode(int data) 
{
  binaryTree* node = (binaryTree*)
                       malloc(sizeof(binaryTree));
  node->value = data;
  node->left = NULL;
  node->right = NULL;
   
  return(node);
}

void printList(binaryTree *node)
{
    while (node!=NULL)
    {
        printf("%d ", node->value);
        node = node->right;
    }
}

void binaryTree2List(binaryTree *root)
{
	if(root)
	{
		binaryTree2List(root->left);
		if(prev)	
			prev->right = root;
		else
			dll = root;
		root->left = prev;
		prev = root;
		binaryTree2List(root->right);
	}
} 

/* Driver program to test above functions*/
int main()
{
    // Let us create the tree shown in above diagram
    binaryTree *root        = newNode(10);
    root->left        = newNode(12);
    root->right       = newNode(15);
    root->left->left  = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);
 
    // Convert to DLL
    binaryTree2List(root);
 
    // Print the converted list
    printList(dll);
 
    return 0;
}