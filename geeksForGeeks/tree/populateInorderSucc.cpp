/*
Given a Binary Tree where each node has following structure, write a function to populate next pointer for all nodes. The next pointer for every node should be set to point to inorder successor.

struct node
{
  int data;
  struct node* left;
  struct node* right;
  struct node* next;
}
Initially, all next pointers have NULL values. Your function should fill these next pointers so that they point to inorder successor.
*/


#include<stdio.h>
#include<malloc.h>
#include<vector>
#include <limits.h>
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

void populateNext(struct node* p)
{
    // The first visited node will be the rightmost node
    // next of the rightmost node will be NULL
    static struct node *next = NULL;
 
    if (p)
    {
        // First set the next pointer in right subtree
        populateNext(p->right);
 
        // Set the next as previously visited node in reverse Inorder
        p->next = next;
 
        // Change the prev for subsequent node
        next = p;
 
        // Finally, set the next pointer in left subtree
        populateNext(p->left);
    }
}

int main()
{
 
    /* Constructed binary tree is
              10
            /   \
          8      12
        /
      3
    */
    binaryTree *root = newnode(10);
    root->left        = newnode(8);
    root->right       = newnode(12);
    root->left->left  = newnode(3);
 
    // Populates nextRight pointer in all nodes
    populateNext(root);
 
    // Let us see the populated values
    binaryTree *ptr = root->left->left;
    while(ptr)
    {
        // -1 is printed if there is no successor
        printf("Next of %d is %d \n", ptr->data, ptr->next? ptr->next->data: -1);
        ptr = ptr->next;
    }
 
    return 0;
}