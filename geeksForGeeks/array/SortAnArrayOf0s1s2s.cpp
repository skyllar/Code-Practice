#include<stdio.h>
 
/* Function to swap *a and *b */
void swap(int *a, int *b);
 
void sort012(int a[], int arr_size)
{
  int low = 0, mid = 0, high = arr_size-1;

  for(int i=0; i<arr_size; i++)
  {
    switch(a[mid])
    {
      Case 0: swap(&a[mid++],&a[low++]);
              break;
      Case 1: mid++;
              break;
      Case 2:swap(&a[mid++],&a[high--])
    }
  }
}

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}
 
/* Utility function to print array arr[] */
void printArray(int arr[], int arr_size)
{
  int i;
  for (i = 0; i < arr_size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}
 
/* driver program to test */
int main()
{
  int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
  int arr_size = sizeof(arr)/sizeof(arr[0]);
  int i;
 
  sort012(arr, arr_size);
 
  printf("array after segregation ");
  printArray(arr, arr_size);
 
  getchar();
  return 0;
}