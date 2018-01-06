/*
Flatten a multilevel linked list
Given a linked list where in addition to the next pointer, each node has a child pointer, which may or may not point to a separate list. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure, as shown in below figure.You are given the head of the first level of the list. Flatten the list so that all the nodes appear in a single-level linked list. You need to flatten the list in way that all nodes at first level should come first, then nodes of second level, and so on.

Each node is a C struct with the following definition.

struct list
{
    int data;
    struct list *next;
    struct list *child;
};
*/

// Program to flatten list with next and child pointers
#include <stdio.h>
#include <stdlib.h>
#include<queue>

using namespace std;
// Macro to find number of elements in array
#define SIZE(arr) (sizeof(arr)/sizeof(arr[0]))
 
// A linked list node has data, next pointer and child pointer
typedef struct node
{
    int data;
    struct node *next;
    struct node *child;
}node;
 
// A utility function to create a linked list with n nodes. The data
// of nodes is taken from arr[].  All child pointers are set as NULL
struct node *createList(int *arr, int n)
{
    struct node *head = NULL;
    struct node *p;
 
    int i;
    for (i = 0; i < n; ++i) {
        if (head == NULL)
            head = p = (struct node *)malloc(sizeof(*p));
        else {
            p->next = (struct node *)malloc(sizeof(*p));
            p = p->next;
        }
        p->data = arr[i];
        p->next = p->child = NULL;
    }
    return head;
}
 
// A utility function to print all nodes of a linked list
void printList(struct node *head)
{
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
 
// This function creates the input list.  The created list is same
// as shown in the above figure
struct node *createList(void)
{
    int arr1[] = {10, 5, 12, 7, 11};
    int arr2[] = {4, 20, 13};
    int arr3[] = {17, 6};
    int arr4[] = {9, 8};
    int arr5[] = {19, 15};
    int arr6[] = {2};
    int arr7[] = {16};
    int arr8[] = {3};
 
    /* create 8 linked lists */
    struct node *head1 = createList(arr1, SIZE(arr1));
    struct node *head2 = createList(arr2, SIZE(arr2));
    struct node *head3 = createList(arr3, SIZE(arr3));
    struct node *head4 = createList(arr4, SIZE(arr4));
    struct node *head5 = createList(arr5, SIZE(arr5));
    struct node *head6 = createList(arr6, SIZE(arr6));
    struct node *head7 = createList(arr7, SIZE(arr7));
    struct node *head8 = createList(arr8, SIZE(arr8));
 
 
    /* modify child pointers to create the list shown above */
    head1->child = head2;
    head1->next->next->next->child = head3;
    head3->child = head4;
    head4->child = head5;
    head2->next->child = head6;
    head2->next->next->child = head7;
    head7->child = head8;
 
 
    /* Return head pointer of first linked list.  Note that all nodes are
       reachable from head1 */
    return head1;
}
 
/* The main function that flattens a multilevel linked list */
void flattenList(struct node *head)
{
    struct node *last = head,*ptr= head,*temp;
    while(last->next)
    {
        last = last->next;
    }
    
    while(ptr)
    {
        if(ptr->child)
        {
            temp = ptr->child;
            while(temp)
            {
                last->next = temp;
                last = temp;
                temp = temp->next;
                last->next = NULL;
            }
        }
        ptr = ptr->next;
    }

}
 
// A driver program to test above functions
int main(void)
{
    struct node *head = NULL;
    head = createList();
    flattenList(head);
    printList(head);
    return 0;
}