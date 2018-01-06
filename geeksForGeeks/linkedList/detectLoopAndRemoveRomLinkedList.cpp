/*
Detect and Remove Loop in a Linked List
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
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}

void printList(struct node *node)
{
    while(node != NULL)
    {
        printf("%d  ", node->data);
        node = node->next;
    }
}

linkedList *detectLoop(linkedList *head)
{
    linkedList *slow=head,*fast=head;

    while(fast && fast->next )
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            printf("Found Loop at %d\n",slow->data);
            return slow;
        }
    }

    return NULL;
}

int countNoOfLoopNodes(linkedList *loopNode)
{
    int count  = 1 ;
    linkedList *ptr = loopNode->next;

    while(loopNode != ptr)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}
 
void detectAndRemoveLoop(linkedList *head)
{
    linkedList*loopNode = detectLoop(head);

    int totalLoopNodes = countNoOfLoopNodes(loopNode);

    linkedList *a=head,*b=head;

    for(int i = 0 ; i< totalLoopNodes; i++)
        b = b->next;
    
    linkedList *prev = NULL;

    while(a!=b)
    {
        a=a->next;
        prev = b;
        b=b->next;
    }

    if(prev)
        prev->next = NULL;
}


/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
 
    push(&head, 10);
    push(&head, 4);
    push(&head, 15);
    push(&head, 20);
    push(&head, 50);
 
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;
 
    detectAndRemoveLoop(head);
 
    printf("Linked List after removing loop \n");
    printList(head);
 
    getchar();
    return 0;
}