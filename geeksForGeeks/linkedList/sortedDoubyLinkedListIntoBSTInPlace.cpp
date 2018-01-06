/*
In-place conversion of Sorted DLL to Balanced BST
Given a Doubly Linked List which has data members sorted in ascending order. Construct a Balanced Binary Search Tree which has same data members as the given Doubly Linked List. The tree must be constructed in-place (No new node should be allocated for tree conversion)

Examples:

Input:  Doubly Linked List 1 <--> 2 <--> 3
Output: A Balanced BST 
     2   
   /  \  
  1    3 


Input: Doubly Linked List 1 <--> 2 <-->3 <--> 4 <-->5 <--> 6 <--> 7
Output: A Balanced BST
        4
      /   \
     2     6
   /  \   / \
  1   3  4   7  

Input: Doubly Linked List 1 <--> 2 <--> 3 <--> 4
Output: A Balanced BST
      3   
    /  \  
   2    4 
 / 
1

Input:  Doubly Linked List 1 <--> 2 <--> 3 <--> 4 <--> 5 <--> 6
Output: A Balanced BST
      4   
    /   \  
   2     6 
 /  \   / 
1   3  5   
The Doubly Linked List conversion is very much similar to this Singly Linked List problem and the method 1 is exactly same as the method 1 of previous post. Method 2 is also almost same. The only difference in method 2 is, instead of allocating new nodes for BST, we reuse same DLL nodes. We use prev pointer as left and next pointer as right.
*/
#include<stdio.h>
#include<stdlib.h>
 
/* A Doubly Linked List node that will also be used as a tree node */
struct Node
{
    int data;
 
    // For tree, next pointer can be used as right subtree pointer
    struct Node* next;
 
    // For tree, prev pointer can be used as left subtree pointer
    struct Node* prev;
};
 
 
// A utility function to count nodes in a Linked List
int countNodes(struct Node *head);
 
struct Node* sortedListToBSTRecur(struct Node **head_ref, int n);
 
/* This function counts the number of nodes in Linked List and then calls
   sortedListToBSTRecur() to construct BST */
struct Node* sortedListToBST(struct Node *head)
{
    /*Count the number of nodes in Linked List */
    int n = countNodes(head);
 
    /* Construct BST */
    return sortedListToBSTRecur(&head, n);
}
 
/* The main function that constructs balanced BST and returns root of it.
       head_ref -->  Pointer to pointer to head node of Doubly linked list
       n  --> No. of nodes in the Doubly Linked List */
struct Node* sortedListToBSTRecur(struct Node **head, int n)
{
    if(n <= 0)
		return NULL;
	
	struct Node *prev = sortedListToBSTRecur(head,n/2);
	///struct Node *root = newNode((*head)->data);
	(*head)->prev = prev;
	struct Node *temp = *head;
	*head = (*head)->next;
	temp->next = sortedListToBSTRecur(head,n-(n/2)-1);

	return temp;
}
 
/* UTILITY FUNCTIONS */
/* A utility function that returns count of nodes in a given Linked List */
int countNodes(struct Node *head)
{
    int count = 0;
    struct Node *temp = head;
    while(temp)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
 
/* Function to insert a node at the beginging of the Doubly Linked List */
void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node =
            (struct Node*) malloc(sizeof(struct Node));
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* since we are adding at the begining,
      prev is always NULL */
    new_node->prev = NULL;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* change prev of head node to new node */
    if((*head_ref) !=  NULL)
      (*head_ref)->prev = new_node ;
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while(node!=NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
 
/* A utility function to print preorder traversal of BST */
void preOrder(struct Node* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->prev);
    preOrder(node->next);
}
 
/* Drier program to test above functions*/
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;
 
    /* Let us create a sorted linked list to test the functions
     Created linked list will be 7->6->5->4->3->2->1 */
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
 
    printf("\n Given Linked List ");
    printList(head);
 
    /* Convert List to BST */
    struct Node *root = sortedListToBST(head);
    printf("\n PreOrder Traversal of constructed BST ");
    preOrder(root);
 
    return 0;
}