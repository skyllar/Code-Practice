#include<stdio.h>
 
int maxSubArraySum(int *a,int n)
{
	int maxTillHere=0,globalMax = 0;
	for(int i=0; i<n; i++)
	{
		maxTillHere += a[i];
		if(maxTillHere < 0)
			maxTillHere = 0;
		else if(globalMax < maxTillHere)
			globalMax = maxTillHere;
	}
	return globalMax;
}

/* Driver program to test maxSubArraySum */
int main()
{
   int a[] =  {-2, -3, 4, -1, -2, 1, 5, -3};
   int n = sizeof(a)/sizeof(a[0]);
   int max_sum = maxSubArraySum(a, n);
   printf("Maximum contiguous sum is %d\n", max_sum);
   return 0;
}