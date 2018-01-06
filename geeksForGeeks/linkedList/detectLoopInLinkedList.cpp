/*
Write a C function to detect loop in a linked list
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  int data;
  struct node* next;
}linkedList;
 
void push(struct node** head_ref, int new_data)
{
  /* allocate node */
  struct node* new_node =
  (struct node*) malloc(sizeof(struct node));
 
  /* put in the data  */
  new_node->data  = new_data;
 
  /* link the old list off the new node */
  new_node->next = (*head_ref);
 
  /* move the head to point to the new node */
  (*head_ref)    = new_node;
}

int detectloop(linkedList *head)
{
	linkedList *slow=head,*fast=head;

	while(slow && fast && fast->next)
	{
		slow = slow->next;
		head = head ->next->next;
		if(slow == fast)
		{
			printf("Found Loop at %d\n",slow->data);
			return 1;
		}
	}
	return 0;

} 

int main()
{
  /* Start with the empty list */
  struct node* head = NULL;
 
  push(&head, 20);
  push(&head, 4);
  push(&head, 15);
  push(&head, 10);
 
  /* Create a loop for testing */
  head->next->next->next->next = head;
  detectloop(head);
 
  getchar();
}