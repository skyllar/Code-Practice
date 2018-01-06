/*
Check for Identical BSTs without building the trees
Given two arrays which represent a sequence of keys. Imagine we make a Binary Search Tree (BST) from each array. We need to tell whether two BSTs will be identical or not without actually constructing the tree.

Examples
For example, the input arrays are {2, 4, 3, 1} and {2, 1, 4, 3} will construct the same tree

 Let the input arrays be a[] and b[]

Example 1:
a[] = {2, 4, 1, 3} will construct following tree.
   2
 /  \
1    4
    /
   3
b[] = {2, 4, 3, 1} will also also construct the same tree.
   2
 /  \
1    4
    /
   3 
So the output is "True"

Example 2:
a[] = {8, 3, 6, 1, 4, 7, 10, 14, 13}
b[] = {8, 10, 14, 3, 6, 4, 1, 7, 13}

They both construct the same following BST, so output is "True"
            8
         /    \
       3       10
     /  \        \
    1     6       14
        /   \     /
       4     7   13  
*/

#include<stdio.h>
#include<malloc.h>
#include<vector>
#include<iostream>
using namespace std;
#include<limits.h>

bool check(int *a,int *b,int start1,int start2,int end,int min,int max)
{
	int i,j;
	for(i=start1;i<end;i++)
		if(a[i]>=min && a[i]<=max)
			break;
	for(j=start2;j<end;j++)
		if(b[j]>=min &&b[j]<=max)
			break;
	if(j==end && i==end)
		return true;
	if(j==end || i==end || a[i] != b[j])
		return false;
	return (check(a,b,i+1,j+1,end,a[i],max) + check(a,b,i+1,j+1,end,min,a[i]));		
			
}

bool isSameBST(int *a,int*b,int size)
{
	return check(a,b,0,0,size,INT_MIN,INT_MAX);
}
int main()
{
   int a[] = {8, 3, 6, 1, 4, 7, 10, 14, 13};
   int b[] = {8, 10, 14, 3, 6, 4, 1, 7, 13};
   int n=sizeof(a)/sizeof(a[0]);
   printf("%s\n", isSameBST(a, b, n)?
             "BSTs are same":"BSTs not same");
   return 0;
}