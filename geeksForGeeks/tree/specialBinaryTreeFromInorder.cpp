/*
Construct Special Binary Tree from given Inorder traversal
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

long long findMaxValue(long long *inorder,long long beg,long long end)
{
	if( end == beg)
		return end;
	else
	{
		long long maxIndex = beg;
		long long maxValue = inorder[beg];

		for( long long i = beg+1; i<=end; i++)
		{
			if( inorder[i]>maxValue)
			{
				maxIndex = i;
				maxValue = inorder[i];
			}
		}
		return maxIndex;
	}
}

binaryTree * specialBinaryTreeFromInorder(long long *inorder,long long beg,long long end)
{
	if( beg > end )
		return NULL;

	long long maxIndex = findMaxValue(inorder,beg,end);
	binaryTree *root = newNode(inorder[maxIndex]);
	root->left = specialBinaryTreeFromInorder(inorder,beg,maxIndex -1);
	root->right = specialBinaryTreeFromInorder(inorder,maxIndex+1,end);
	return root;
}

void printInorder(binaryTree *root)
{
	if(root == NULL)
		return ;
	printInorder(root->left);
	printf("%lld ",root->value);
	printInorder(root->right);

}	

int main()
{
	long long inorder[] = {5, 10, 40, 30, 28};
    long long int len = sizeof(inorder)/sizeof(inorder[0]);

  	binaryTree *root = specialBinaryTreeFromInorder(inorder,0,len-1);
  //printf("%lld\n",maxDiameter);
  	printInorder(root);
	return 0;
}