/*
Level Order Tree Traversal (BFS)
*/

#include<stdio.h>
#include<malloc.h>
#include<queue>
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
queue<binaryTree*> myqueue;

void levelOrderTraversal(binaryTree *root)
{
	binaryTree *temp ;
	myqueue.push(root);

	while( !myqueue.empty() )
	{
		temp = myqueue.front();
		myqueue.pop();
		printf("%lld ",temp->value);

		if( temp -> left != NULL)
			myqueue.push(temp->left);
		if( temp -> right != NULL)
			myqueue.push(temp->right);
		
	}
}  

int main()
{
	binaryTree *root= NULL;

	root = newNode(1);
 	root->left        = newNode(2);
 	root->right       = newNode(3);
 	root->left->left  = newNode(4);
 	root->left->right = newNode(5);  

	levelOrderTraversal(root);

	return 0;
}