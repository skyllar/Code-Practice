/*
Level order traversal in spiral form
*/

#include<stdio.h>
#include<malloc.h>
#include<vector>
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

vector<binaryTree*> myqueue;

void levelOrderTraversalInSpiralForm(binaryTree *root)
{
	unsigned int i;
	int myqueueFront=0;
	int myqueueRear=1;
	binaryTree *temp;
	myqueue.push_back(root);
	myqueue.push_back(newNode(-1));

	while(myqueueRear > myqueueFront)
	{	
		temp = myqueue[myqueueFront];
		myqueueFront ++;

		if( temp->value == -1 )
		{
			myqueueRear++;
			myqueue.push_back(newNode(-1));
		}

		if( temp ->left != NULL )
		{
			myqueue.push_back(temp->left);
			myqueueRear++;
		}
		if( temp ->right  != NULL)
		{
			myqueue.push_back(temp->right);
			myqueueRear++;
		}

	}

	for( i=0;i < myqueue.size(); i++)
	{
		printf("%lld ",(myqueue[i])->value);
	}
	printf("\n");

	// now we can USE FLAG to print in spiral from
}

int main()
{
	binaryTree *root= NULL;

	root = newNode(1);
 	root->left        = newNode(2);
 	root->right       = newNode(3);
 	root->left->left  = newNode(4);
 	root->left->right = newNode(5);  
 	root->right->left  = newNode(6);
 	root->right->right = newNode(7);  

	levelOrderTraversalInSpiralForm(root);

	return 0;
}