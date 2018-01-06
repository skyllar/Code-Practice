#include <stdio.h>

void swap(char *str,int i,int j)
{
	char temp = str[i];
	str[i] = str[j];
	str[j] = temp;
}

void rotate(char *str,int i,int j,int length)
{
	char temp;
	char carryForward = str[j];
	
	for ( int k = i ;  k <= j ; k++)
	{
		temp = str[k];
		str[k] = carryForward;
		carryForward = temp;
	}
}

void revRotate(char *str,int i,int j,int length)
{
	char temp;
	char carryForward = str[i];
	
	for ( int k = j ;  k >= i ; k--)
	{
		temp = str[k];
		str[k] = carryForward;
		carryForward = temp;
	}
}

void sortedRecur(char *str,int currentIndex,int length)
{
	if( currentIndex == length)
	{
		for( int i=0; i<length; i++)
		{
			printf("%c",str[i]);
		}
		printf("\n");
	}
	else
	{
		for(int i=currentIndex; i < length; i++)
		{
			//swap(str,currentIndex,i);
			rotate(str,currentIndex,i,length);

			sortedRecur(str,currentIndex+1,length);
			//swap(str,currentIndex,i);
			revRotate(str,currentIndex,i,length);
		}
	}
}

void sortedPermutations(char *str,int length)
{
	sortedRecur(str,0,length);
}

/// Driver program to test above function
int main()
{
    char str[] = "ABCD";
    sortedPermutations( str ,(sizeof(str)/sizeof(char)) -1);
    return 0;
}