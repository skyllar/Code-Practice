/*
Vertical Sum in a given Binary Tree
Given a Binary Tree, find vertical sum of the nodes that are in same vertical line. Print all sums through different vertical lines.

Examples:

      1
    /   \
  2      3
 / \    / \
4   5  6   7
The tree has 5 vertical lines

Vertical-Line-1 has only one node 4 => vertical sum is 4
Vertical-Line-2: has only one node 2=> vertical sum is 2
Vertical-Line-3: has three nodes: 1,5,6 => vertical sum is 1+5+6 = 12
Vertical-Line-4: has only one node 3 => vertical sum is 3
Vertical-Line-5: has only one node 7 => vertical sum is 7

So expected output is 4, 2, 12, 3 and 7


*/
#include<stdio.h>
#include<malloc.h>
#include<vector>
#include<map>
using namespace std;

map<long long,long long> hashMap;

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

void verticalSumInBinaryTree(binaryTree *root,long long horizontalDistance)
{
	if(root == NULL)
		return;
	long long temp = root->value;
	map<long long,long long>::iterator it = hashMap.find(horizontalDistance);


	if(it != hashMap.end())
		temp += hashMap.at(horizontalDistance);

	hashMap[horizontalDistance]= temp;

	verticalSumInBinaryTree(root->left,horizontalDistance -1);
	verticalSumInBinaryTree(root->right,horizontalDistance +1);
}

int main()
{
    binaryTree  *root;
     /* Create following Binary Tree
              1
            /    \
          2        3
         / \      / \
        4   5    6   7
  
        */
        root = newNode(1);
        root -> left = newNode(2);
        root -> right = newNode(3);
        root->left->left = newNode(4);
        root->left->right = newNode(5);
        root->right->left= newNode(6);
        root->right->right = newNode(7);

 	verticalSumInBinaryTree(root,0);
	map<long long,long long>::iterator it;

	for(it= hashMap.begin() ; it!=hashMap.end(); it++)
	{
		printf("%lld ",it->second);
	} 	

	return 0;
}