/*
Segment Tree | Set 1 (Sum of given range)
*/


#include<stdio.h>
#include<malloc.h>
#include <limits.h>
using namespace std;
#include <math.h>

int minVal(int x, int y) { return (x < y)? x: y; }

int constructTree(int *givenTree,int * segmentTree,int beg,int end,int currSegmentTreeIndex)
{
	if(beg==end)
	{
		return (segmentTree[currSegmentTreeIndex] = givenTree[beg]) ;
	}


	int mid = beg + (end-beg)/2;

	segmentTree[currSegmentTreeIndex] = constructTree(givenTree,segmentTree,beg,mid,2*currSegmentTreeIndex+1);
	segmentTree[currSegmentTreeIndex] += constructTree(givenTree,segmentTree,mid+1,end,2*currSegmentTreeIndex+2);

	return segmentTree[currSegmentTreeIndex];
}

int* constructST(int *givenTree,int size)
{
	int height = (int)ceil(log2(size));
	int segmentTreeSize =  (int)(2*(int)pow(2,height)) - 1;
	int *segmentTree = new int[segmentTreeSize];
	constructTree(givenTree,segmentTree,0,size-1,0);
	return segmentTree;
}

int getSum(int *segmentTree,int beg,int end,int qeuryStart,int queryEnd,int currSegmentTreeIndex)
{
	if(beg>=qeuryStart && end <= queryEnd)
		return segmentTree[currSegmentTreeIndex];
	if(beg>queryEnd || end<qeuryStart)
		return 0;
	int mid = beg + (end-beg)/2;
	return getSum(segmentTree,beg,mid,qeuryStart,queryEnd,2*currSegmentTreeIndex+1) + getSum(segmentTree,mid+1,end,qeuryStart,queryEnd,2*currSegmentTreeIndex+2);
}

void updateSegementTree(int *givenTree,int *segmentTree,int size,int index,int value,int beg,int end)
{
	if(beg>=qeuryStart && end <= queryEnd)
		segmentTree[currSegmentTreeIndex]+=value;
	if(beg>queryEnd || end<qeuryStart)
		return;
	
	int mid = beg + (end-beg)/2;
	updateSegementTree(segmentTree,beg,mid,qeuryStart,queryEnd,2*currSegmentTreeIndex+1);
	updateSegementTree(segmentTree,mid+1,end,qeuryStart,queryEnd,2*currSegmentTreeIndex+2);

}

void updateValue(int *givenTree,int *segmentTree,int size,int index,int value)
{	
	givenTree[index] = value;
	updateSegementTree(givenTree,segmentTree,size,index,value,0,size-1);
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    // Build segment tree from given array
    int *st = constructST(arr, n);
 
    //Print sum of values in array from index 1 to 3
    printf("Sum of values in given range = %d\n", getSum(st,0, n-1, 1, 3,0));
 
    // Update: set arr[1] = 10 and update corresponding segment
    // tree nodes
    updateValue(arr, st, n, 1, 10);
 
    Find sum after the value is updated
    printf("Updated sum of values in given range = %d\n",getSum(st, n, 1, 3));
 
    return 0;
}