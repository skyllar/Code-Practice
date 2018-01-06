/*
Copy a linked list with next and arbit pointer
You are given a Double Link List with one pointer of each node pointing to the next node just like in a single link list. The second pointer however CAN point to any node in the list and not just the previous node. Now write a program in O(n) time to duplicate this list. That is, write a program which will create a copy of this list.
*/


#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
  int data;
  struct node* next;
  struct node* arbit;
} linkedList;


void push(struct node** head_ref, int new_data)
{
  /* allocate node */
  struct node* new_node = (struct node*) malloc(sizeof(struct node));
 
  /* put in the data  */
  new_node->data  = new_data;
 
  /* link the old list off the new node */
  new_node->next = (*head_ref);
 
  /* move the head to point to the new node */
  (*head_ref)    = new_node;
}

void printList(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%d  ", temp->data);    
        temp = temp->next;  
    }
}    

linkedList *newNode(int data)
{
	struct node* new_node =(struct node*) malloc(sizeof(struct node));
	new_node -> data = data;
	new_node->arbit = NULL;
	new_node->next = NULL;
	return new_node;
}

linkedList *copyLinkedList(linkedList *head)
{
	linkedList *newHead = NULL,*temp1,*temp2;
	linkedList *ptr1,*ptr2=NULL;

	ptr1 = head;

	while(ptr1)
	{
		temp2 = newNode(ptr1->data);

		if(!ptr2)
		{
			newHead = temp2;
			ptr2 = temp2;
		}
		else
		{
			ptr2->next = temp2;
			ptr2 = ptr2->next;
		}

		temp1 = ptr1->next;
		ptr1 -> next = temp2;
		temp2->arbit = ptr1 ; 
		ptr1 = temp1;
	}

	//set arbiter pointer.......
	//call function
	
	return newHead;
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
  head->arbit = head->next->next;
  head->next->arbit = head->next->next->next;
  head->next->next->arbit = head->next;
  head->next->next->next->arbit = head;


  linkedList  *newHead =  copyLinkedList(head);
  printList(newHead);
  //getchar();
}
