/*
Median of two sorted arrays
Question: There are 2 sorted arrays A and B of size n each. Write an algorithm to find the median of the array obtained after merging the above 2 arrays(i.e. array of length 2n). The complexity should be O(log(n))
*/

/* Function to get median of a sorted array */


#include<stdio.h>
int max(int, int); /* to get maximum of two integers */
int min(int, int); /* to get minimum of two integers */
int median(int arr[], int n)
{
    if (n%2 == 0)
        return (arr[n/2] + arr[n/2-1])/2;
    else
        return arr[n/2];
}
 
int getMedianUtil(int *ar1,int n1,int *ar2,int n2)
{
    int m1 = median(ar1,n1);
    int m2 = median(ar2,n2);

    if (n1 <= 0)
        return -1;
 
    if (n2 == 1)
        return (ar1[0] + ar2[0])/2;
 
    if (n2 == 2)
      return (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1])) / 2;

    if( m1 == m2 )
        return m1;
    else if( m1 < m2)
    {
        if(n1 %2 == 0)
            return getMedianUtil(ar1 + n1/2-1, n1 - n1/2+1,ar2,n2/2+1);
        else
            return getMedianUtil(ar1 + n1/2, n1- n1/2,ar2,n2/2+1);

    }
    else
    {
        if(n1 %2 == 0)
            return getMedianUtil(ar1, n1/2+1,ar2+n2/2-1,n2-n2/2+1);
        else
            return getMedianUtil(ar1, n1/2+1,ar2+n2/2,n2 -n2/2);
    }

}

int getMedian(int  *ar1,int *ar2,int n)
{
    return getMedianUtil(ar1,n,ar2,n);
} 
/* Driver program to test above function */
int main()
{
    int ar2[] = {1, 2, 3, 6};
    int ar1[] = {4, 6, 8, 10};
    int n1 = sizeof(ar1)/sizeof(ar1[0]);
    int n2 = sizeof(ar2)/sizeof(ar2[0]);
    if (n1 == n2)
      printf("Median is %d", getMedian(ar1, ar2, n1));
    else
     printf("Doesn't work for arrays of unequal size");
 
    getchar();
    return 0;
}
 
/* Utility functions */
int max(int x, int y)
{
    return x > y? x : y;
}
 
int min(int x, int y)
{
    return x > y? y : x;
}
