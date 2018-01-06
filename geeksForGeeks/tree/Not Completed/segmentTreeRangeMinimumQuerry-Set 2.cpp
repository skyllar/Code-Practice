/*
Segment Tree | Set 2 (Range Minimum Query)
*/


#include<stdio.h>
#include<malloc.h>
#include <limits.h>
using namespace std;
#include <math.h>

int minVal(int x, int y) { return (x < y)? x: y; }

void constructTree(givenTree,segmentTree,beg,end,currentIndex,currSegmentTreeIndex)
{
	if(beg==mid)
	{
		return (segmentTree[currSegmentTreeIndex] = givenTree[currentIndex]) ;
	}


	int mid = beg + (end-beg)/2;

	int min1= constructTree(givenTree,segmentTree,beg,mid,2*currentIndex +1,2*currSegmentTreeIndex+1);
	int min2 = constructTree(givenTree,segmentTree,mid+1,end,2*currentIndex +2,2*currSegmentTreeInde
	segmentTree[currSegmentTreeIndex] = getMid(min1,min2);
	 
	return min;
}

int* constructST(int *givenTree,int size)
{
	int height = (int)ceil(log2(size));
	int segmentTreeSize = 2*(int)pow(2,x) - 1;
	int segmentTree = new int[segmentTreeSize];
	constructTree(givenTree,segmentTree,0,size-1,0,0);
}

int main()
{
    int arr[] = {1, 3, 2, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    // Build segment tree from given array
    int *st = constructST(arr, n);
 
    int qs = 1;  // Starting index of query range
    int qe = 5;  // Ending index of query range
 
    // Print minimum value in arr[qs..qe]
    printf("Minimum of values in range [%d, %d] is = %d\n",
                           qs, qe, RMQ(st, n, qs, qe));
 
    return 0;
}