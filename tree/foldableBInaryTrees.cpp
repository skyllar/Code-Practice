#include<stdio.h>
#include<malloc.h>

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

long long checkFoldableOrNot(binaryTree *ptr1,binaryTree *ptr2)
{
	if( ptr2 == NULL && ptr1 == NULL )
		return 1;
	if( ptr1 == NULL || ptr2 == NULL )
		return 0;
	return (checkFoldableOrNot(ptr1->right ,ptr2 -> left) && checkFoldableOrNot(ptr1->left,ptr2->right));
}

int main()
{
	binaryTree *root= NULL;


	root = newNode(4);
 	root->left        = newNode(2);
 	root->right       = newNode(5);
 	//root->left->left  = newNode(1);
 	//root->left->right = newNode(3); 
 	//root->right->right = newNode(3); 
	printf("%lld\n",checkFoldableOrNot(root->left,root->right));

	return 0;
}