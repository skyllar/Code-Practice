/*

If you are given two traversal sequences, can you construct the binary tree?

*/

#include<stdio.h>
#include<malloc.h>
#include<queue>
using namespace std;
#include<vector>

long long int path[1000];
long long size ;

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

//binary search can also be applied
long long search(long long value,long long int *arr,long long low, long long high)
{
	long long i;
	for( i= low; i<=high; i++ )
	{
		if( value == arr[i])
			return i;
	}
	return -9999;
}

binaryTree *fromInorderAndPreorderToTree(long long int *inorder,long long  int *preorder,long long  int i,long long int low,long long int high)
{
	if( i >= size)
		return NULL;
	
	binaryTree *root = (binaryTree *)malloc(sizeof(binaryTree));
	
	long long int mid = search(preorder[i],inorder,low,high);
	root->value = preorder[i];

	root->left = fromInorderAndPreorderToTree(inorder,preorder,i+1,low,mid-1);
	root->right = fromInorderAndPreorderToTree(inorder,preorder,i+1+mid-low,mid+1,high);

	return root;
}

int main()
{
	binaryTree *root= NULL;
	long long int inorder[1100] = {1,2,6,4,3,5};
	long long int preorder[1100] = {4,2,1,6,5,3};
 // root = newNode(1);
 // 	root->left        = newNode(2);
 // 	root->right       = newNode(3);
 // 	root->left->left  = newNode(4);
 // 	root->left->right = newNode(5); 
	size = 6;
	root = fromInorderAndPreorderToTree(inorder,preorder,0,0,5);

	return 0;
}
