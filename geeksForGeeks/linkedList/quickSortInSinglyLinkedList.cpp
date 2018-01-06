/*
QuickSort on Singly Linked List
*/

#include <iostream>
#include <cstdio>
using namespace std;
 
/* a node of the singly linked list */
struct node
{
    int data;
    struct node *next;
};
 
/* A utility function to insert a node at the beginning of linked list */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node = new node;
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* A utility function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d  ", node->data);
        node = node->next;
    }
    printf("\n");
}
 
// Returns the last node of the list
struct node *getTail(struct node *head,struct node *end)
{   
    struct node *cur = head;
    while (cur != NULL && cur->next != end)
        cur = cur->next;
    return cur;
}

void swap(struct node *i,struct node *j)
{
    int temp = i->data;
    i->data = j->data;
    j->data = temp;
}
 
// Partitions the list taking the last element as the pivot
struct node *partition(struct node *head, struct node *end)
{
    int x = end->data;
    struct node *i = NULL;
    for(struct node *j=head;j!=end;j=j->next)
    {
        if(x>=j->data)
        {
            i = (i==NULL)?head:i->next;
            swap(i,j);
        }
    }
    i = (i==NULL)?head:i->next;
    swap(i,end);
    return i;
}
 
 
//here the sorting happens exclusive of the end node
void quickSortRecur(struct node *head, struct node *end)
{
    //if(!head || !end)
      //  return;
     if (end != NULL && end != head && head != end->next){
    struct node *pivot = partition(head,end);
    struct node *prev = getTail(head,pivot);
  
    quickSortRecur(head,prev);
    quickSortRecur(pivot->next,end);
    }   
}
 
// The main function for quick sort. This is a wrapper over recursive
// function quickSortRecur()
void quickSort(struct node **headRef)
{
    quickSortRecur(*headRef, getTail(*headRef,NULL));
}
 
// Driver program to test above functions
int main()
{
    struct node *a = NULL;
    push(&a, 5);
    push(&a, 20);
    push(&a, 4);
    push(&a, 3);
    push(&a, 30);
 
    cout << "Linked List before sorting \n";
    printList(a);
 
    quickSort(&a);
 
    cout << "Linked List after sorting \n";
    printList(a);
 
    return 0;
}