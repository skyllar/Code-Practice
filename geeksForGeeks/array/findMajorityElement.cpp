/* Program for finding out majority element in an array */
# include<stdio.h>
# define bool int
  
int findCandidate(int *, int);
bool isMajority(int *, int, int);

void printMajority(int *a,int size)
{
	int majorityIndex = 0,count = 1;

	for(int i=1; i<size; i++)
	{
		if(a[majorityIndex] == a[i])
			count ++;
		else 
			count--;

		if(count == 0)
		{
			majorityIndex = i;
			count = 1;
		}
				
	}

	printf("%d\n", a[majorityIndex]);
}

/* Driver function to test above functions */
int main()
{
    int a[] = {1, 3, 3, 1, 2};
    printMajority(a, 5);
    getchar();
    return 0;
}