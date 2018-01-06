
#include <stdio.h>
#include <stdlib.h>

int partition(int *a,int low,int mid,int high)
{
	int inversions = 0;
	int *temp = (int *)malloc(sizeof(int)*(high-low+1));
	int i,j,k;

	for(i = low,j=mid+1,k=0;i<=mid && j<=high;k++)
	{	
		if(a[i] > a[j])
		{
			temp[k] = a[j++];
			inversions += (mid - i + 1);//high-j+1;
		}
		else
			temp[k] = a[i++];
	}

	for(;i<=mid;i++,k++)
		temp[k] = a[i];

	for(;j<=high;j++,k++)
			temp[k] = a[j];

	for(i=low,k=0; i<=high; i++,k++)
		a[i] = temp[k];

	return inversions;
}

int mergeSort(int *a,int low,int high)
{
	if(low < high)
	{
		int mid = (low + high)/2;

		int a1 = mergeSort(a,low,mid);
		int b1 = mergeSort(a,mid+1,high);

		return (a1+b1+partition(a,low,mid,high));
	}
	else
		return 0;
}


int main(int argv, char** args)
{
  int arr[] = {1, 20, 6, 4, 5};
  printf(" Number of inversions are %d \n", mergeSort(arr, 0,4));
  for(int i=0;i<=4;i++)
  {
  	printf("*%d\n",arr[i]);
  }
  getchar();
  return 0;
}