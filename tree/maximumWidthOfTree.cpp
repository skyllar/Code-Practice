/*
Maximum width of a binary tree
*/

#include<stdio.h>
#include<malloc.h>
#include<queue>
using namespace std;
#include<vector>


typedef struct binaryTree
{
	struct binaryTree * left;
	struct binaryTree *	right;
	long long value;
} binaryTree;


vector<binaryTree*> myqueue;

binaryTree* newNode(int data) 
{
  binaryTree* node = (binaryTree*)
                       malloc(sizeof(binaryTree));
  node->value = data;
  node->left = NULL;
  node->right = NULL;
   
  return(node);
}

long long maximumWidthOfTree(binaryTree *root)
{
	long long globalMaxWidth = 0;
	long long currentMaxWidth = 1;
	binaryTree *temp=NULL;

	myqueue.push_back(root);
	myqueue.push_back(newNode(-1));

	while( (myqueue.front())->value != -1 )
	{
		temp = myqueue.front();
		myqueue.pop_back();

		if(temp->value == -1)
		{
			if( globalMaxWidth < currentMaxWidth )
				globalMaxWidth = currentMaxWidth;
			currentMaxWidth = 0;
			myqueue.push_back(newNode(-1));
		}
		else
		{
		if(temp->left != NULL)
		{
			myqueue.push_back(temp->left);
			currentMaxWidth++;
		}
		if( root->right != NULL)
		{
			myqueue.push_back(temp->right);
			currentMaxWidth++;
		}
		}
	}
	return globalMaxWidth;
}

int main()
{
	binaryTree *treeRoot= NULL;
	long long maxHeight;
	

	treeRoot = newNode(4);
 	treeRoot->left        = newNode(2);
 	treeRoot->right       = newNode(5);
 	treeRoot->left->left  = newNode(1);
 	treeRoot->left->right = newNode(3); 

	
	maxHeight =  maximumWidthOfTree(treeRoot);
	printf("%lld",maxHeight);

	return 0;
}