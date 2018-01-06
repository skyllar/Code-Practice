/*
Sorted Linked List to Balanced BST
Given a Singly Linked List which has data members sorted in ascending order. Construct a Balanced Binary Search Tree which has same data members as the given Linked List.

Examples:

Input:  Linked List 1->2->3
Output: A Balanced BST 
     2   
   /  \  
  1    3 


Input: Linked List 1->2->3->4->5->6->7
Output: A Balanced BST
        4
      /   \
     2     6
   /  \   / \
  1   3  4   7  

Input: Linked List 1->2->3->4
Output: A Balanced BST
      3   
    /  \  
   2    4 
 / 
1

Input:  Linked List 1->2->3->4->5->6
Output: A Balanced BST
      4   
    /   \  
   2     6 
 /  \   / 
1   3  5   
*/

#include<stdio.h>
#include<stdlib.h>
 
/* Link list node */
typedef struct LNode
{
    int data;
    struct LNode* next;
}LNode;
 
/* A Binary Tree node */
typedef struct TNode
{
    int data;
    struct TNode* left;
    struct TNode* right;
}TNode;

int countLNodes(struct LNode *head)
{
    int count = 0;
    struct LNode *temp = head;
    while(temp)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

void push(struct LNode** head_ref, int new_data)
{
    /* allocate node */
    struct LNode* new_node =
        (struct LNode*) malloc(sizeof(struct LNode));
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* Function to print nodes in a given linked list */
void printList(struct LNode *node)
{
    while(node!=NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
 
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct TNode* newNode(int data)
{
    struct TNode* node = (struct TNode*)
                         malloc(sizeof(struct TNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return node;
}
 
/* A utility function to print preorder traversal of BST */
void preOrder(struct TNode* node)
{
    if (node == NULL)
        return;
    preOrder(node->left);
    printf("%d ", node->data);
    preOrder(node->right);
}

TNode *sortedListToBST(LNode **head,int n)
{
	if(n <= 0)
		return NULL;
	
	TNode *left = sortedListToBST(head,n/2);
	TNode *root = newNode((*head)->data);
	root->left = left;
	*head = (*head)->next;
	root->right = sortedListToBST(head,n-n/2-1);
	return root;
}
 
/* Drier program to test above functions*/
int main()
{
    /* Start with the empty list */
    struct LNode* head = NULL;
 
    /* Let us create a sorted linked list to test the functions
     Created linked list will be 1->2->3->4->5->6->7 */
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
 
    printf("\n Given Linked List ");
    printList(head);
 	int n = countLNodes(head);
    /* Convert List to BST */
    struct TNode *root = sortedListToBST(&head,n);
    printf("\n PreOrder Traversal of constructed BST ");
    preOrder(root);
 
    return 0;
}