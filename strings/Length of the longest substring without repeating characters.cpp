/*
Length of the longest substring without repeating characters
*/


#include<stdio.h>
#include<cstring>
#include<string.h>
using namespace std;
#include <string>

int longestUniqueSubsttr(string str)
{
	int maxLength=0;
	int currentStart = 0;
	int i;
	int d[256],temp;

	for(int j = 0 ; j < 256; j++)
				d[j] = -1;	

	for(int i=0; str[i]!='\0'; i++)
	{
		// printf("-----------------Current iteration :%d\n",i);
		// for(int j=0; j < 26; j++)
		// {
		// 	printf("%d ",d[str[i]-'a']);
		// }
		// printf("\n");
		// for(int j=0; j < 26; j++)
		// {
		// 	printf("%c ",j+'a');
		// }
		// printf("\n");

		if(d[str[i]-'a'] != -1)
		{
			//printf("Caught RedHanded:%d,",i);
			if( (i-currentStart) > maxLength )
				maxLength = i-currentStart;

			currentStart = d[str[i]-'a']+1;

			for(int j = 0 ; j < 256; j++)
				d[j] = -1;	

			for( int j = currentStart ; j < i;j++ )
				d[str[j]-'a'] = j;	

		}
		
		//printf("currentStart:%d,maxLength:%d,i:%d\n",currentStart,maxLength,i);
		d[str[i]-'a'] = i;
	}

	return maxLength;
}

/* A utility function to get the minimum of two integers */
 
/* Driver program to test above function */
int main()
{
    string str ("[][]]");
   // printf("The input string is %s \n", str);
    int len =  longestUniqueSubsttr(str);
    printf("The length of the longest non-repeating character substring is %d", len);
 
    //getchar();
    return 0;
}