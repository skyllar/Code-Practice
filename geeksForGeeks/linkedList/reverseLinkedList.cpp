/*
Write a function to reverse a linked list
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
} linkedList;

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
 
/* Function to print linked list */
void printList(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%d  ", temp->data);    
        temp = temp->next;  
    }
} 

void reverse(struct node **head)
{
	linkedList *temp;
	linkedList *ptr = *head;
	linkedList *prev =NULL;

	while(ptr != NULL)
	{
		temp = ptr-> next;
		ptr->next = prev;
		prev = ptr;
		ptr = temp;
	}

	(*head) = prev;
}

int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
   
     push(&head, 20);
     push(&head, 4);
     push(&head, 15); 
     push(&head, 85);      
     
     printList(head);    
     reverse(&head);                      
     printf("\n Reversed Linked list \n");
     printList(head);    
     getchar();
}