/*
Merge Sort for Linked Lists
*/

#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
  int data;
  struct node* next;
  struct node* arbit;
} linkedList;


void printList(struct node *node)
{
  while(node!=NULL)
  {
   printf("%d ", node->data);
   node = node->next;
  }
}

/* Function to insert a node at the beginging of the linked list */
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

void splitFromMid(linkedList *root,linkedList **a,linkedList **b)
{
	//printf(".");
	linkedList *slow = root,*fast = root;
    if(fast )
      {
          fast = fast->next;
      }
	while(fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}


	if(slow)
	{
		*b = slow->next;
		slow->next = NULL;
	}
	*a  = root;

	//printf("*");

}

linkedList *mergePartition(linkedList *a,linkedList *b)
{
	linkedList *head = NULL;
	linkedList *ptrA=a,*ptrB=b,*ptrHead = NULL,*temp;

	while( ptrA && ptrB)
	{
		if(ptrA->data > ptrB->data)
		{
			temp = ptrB;
			ptrB = ptrB->next;
		}
		else
		{
			temp = ptrA;
			ptrA = ptrA -> next;
		}

		if(!head)
		{
			ptrHead = temp;
			head = temp;
		}
		else
		{
			ptrHead->next = temp;
			ptrHead = ptrHead->next;
		}
	}

	if(ptrHead){
	if(ptrA)
		ptrHead->next = ptrA;
	else
		ptrHead->next = ptrB;
	}
	return head;
}

void MergeSort(linkedList **root)
{
	if(!(*root) || !((*root)->next))
		return;

	linkedList *a=NULL,*b=NULL;
	splitFromMid(*root,&a,&b);
	MergeSort(&a);
	MergeSort(&b);

	*root = mergePartition(a,b);

}

/* Drier program to test above functions*/
int main()
{
  /* Start with the empty list */
  //struct node* res = NULL;
  struct node* a = NULL;

  /* Let us create a unsorted linked lists to test the functions
   Created lists shall be a: 2->3->20->5->10->15 */
  push(&a, 15);
  push(&a, 10);
  push(&a, 5);
  push(&a, 20);
  push(&a, 3);
  push(&a, 2);

  /* Sort the above created Linked List */
  MergeSort(&a);

  printf("\n Sorted Linked List is: \n");
  printList(a);


  getchar();
  return 0;
}
