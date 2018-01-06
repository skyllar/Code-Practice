/*
Print ancestors of a given binary tree node without recursion
iven a Binary Tree and a key, write a function that prints all the ancestors of the key in the given binary tree.

For example, consider the following Binary Tree

            1
        /       \
       2         3
     /   \     /   \
    4     5    6    7 
   /       \       /
  8         9     10  
Following are different input keys and their ancestors in the above tree

Input Key    List of Ancestors 
-------------------------
 1            
 2            1
 3            1
 4            2 1
 5            2 1
 6            3 1
 7            3 1
 8            4 2 1
 9            5 2 1
10            7 3 1
*/


#include<stdio.h>
#include<malloc.h>
#include<vector>
#include<iostream>
using namespace std;


typedef struct binaryTree
{
	struct binaryTree * left;
	struct binaryTree *	right;
	int value;
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

vector<binaryTree *> myStack;

void printStack(vector<binaryTree*> v)
{
	vector<binaryTree*>::iterator it; 
	for(it = v.begin();it!=v.end();it++)
		printf("%d ",(*it)->value);
	printf("\n");
}

void printAncestors(binaryTree *root,int key)
{
	myStack.push_back(root);
	binaryTree *temp;

	if(root->value == key)
		return;

	while(!myStack.empty())
	{
		temp = myStack.at(myStack.size()-1);

		if(temp->left != NULL)
		{
			while(temp->left != NULL)
			{
				if(temp->left->value == key)
				{
					printStack(myStack);
					return;
				}
				else
					myStack.push_back(temp->left);
				binaryTree *temp1= temp;
				temp = temp ->left;
				temp1->left = NULL;
			}
		}
		else
		{
			if(temp->right != NULL)
			{
				binaryTree *temp1 =temp; 
				if(temp->right->value == key)
				{
					printStack(myStack);
					return;
				}
				else
					myStack.push_back(temp->right);
				temp1->right = NULL;
			}
			else
			{
				myStack.pop_back();
			}

		}
	}
}

int main()
{
    // Let us construct a binary tree
    binaryTree* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->left->right->right = newNode(9);
    root->right->right->left = newNode(10);
 
    printf("Following are all keys and their ancestors\n");
    for (int key = 1; key <= 10; key++)
    {
        printf("%d: ", key);
        printAncestors(root, key);
        printf("\n");
    }
 
    getchar();
    return 0;
}