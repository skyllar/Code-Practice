/*
Print all permutations with repetition of characters
Given a string of length n, print all permutation of the given string. Repetition of characters is allowed. Print these permutations in lexicographically sorted order 
Examples:

Input: AB
Ouput: All permutations of AB with repetition are:
      AA
      AB
      BA
      BB

Input: ABC
Output: All permutations of ABC with repetition are:
       AAA
       AAB
       AAC
       ABA
       ...
       ...
       CCB
       CCC
*/

#include<stdio.h>
#include<cstring>

#include <stdlib.h>     /* qsort */


int compare(const void *a,const void *b)
{
	return (*(char *)a - *(char *)b);
}

void swap(char *a,int x,int y)
{
	char temp = a[x];
	a[x] = a[y];
	a[y] = temp;
}

void printOrder(int length,char *a,int offset,char *temp)
{
	if( length < offset )
		return;

	if( length == offset)
	{
		for(int i=0; i<length; i++ )
		{
			printf("%c",temp[i]);
		}
		printf("\n");
		return;
	}
	else
	{

		for(int i=0;i < length; i++)
		{
			temp[offset] = a[i];

			printOrder(length,a,offset+1,temp);
		}
	}

}


void allLexicographic(char *str)
{
	int length = strlen(str);
	char *temp = (char *)malloc(sizeof(char)*length);
	qsort(str,length,sizeof(char),compare);
	printOrder(length,str,0,temp);

}

 
// Driver program to test above functions
int main()
{
    char str[] = "ABC";
    printf("All permutations with repetition of %s are: \n", str);
    allLexicographic(str);
    //getchar();
    return 0;
}