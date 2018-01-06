#include <stdio.h>
#include <cstring>
#include <limits.h>

int dp[100][100];
int pal[100][100];

int usingMCMRec(char *str,int length,int start,int last)
{
	if(dp[start][last] != -1)
		return dp[start][last];

	if( start == last)
	{
		pal[start][last] = 1;
		dp[start][last] = 0;
		return 0;
	}

	if(start == last-1)
	{
		if(str[start] == str[last])
		{
			pal[start][last] = 1;
			dp[start][last] = 0;
			return 0;
		}
		else
		{
			pal[start][last] = 0;
			dp[start][last] = 1;
			return 1;
		}
	}


	int k;
	int minCuts = INT_MAX;
	int temp;

	for(k=start; k<last; k++)
	{
		if( dp[start][k] == -1 )
			dp[start][k] = usingMCMRec(str,length,start,k);

		if( dp[k+1][last] == -1 )
			dp[k+1][last] = usingMCMRec(str,length,k+1,last);

		temp = dp[start][k] + dp[k+1][last]+1;

		if( temp < minCuts )
				minCuts = temp;
	}

	if(str[start] == str[last] && pal[start+1][last-1] == 1)
	{
		pal[start][last] = 1;
		dp[start][last] = 0;
	}
	else
	{
		pal[start][last] = 0;
		dp[start][last] = minCuts;
	}
	return dp[start][last] ;
}

void minPalPartion(char *str)
{
	int length = strlen(str);

	for(int i =0 ; i < length; i++)
	{
		printf("%c ",str[i]);
	}

	printf("\n\n");

	for(int i =0 ; i < length; i++)
	{
		printf("%c[%d] ",str[i],i);
	}

	printf("\n\n");

	for( int i=0; i<100; i++)
	{

		for( int j=0; j<100; j++)
		{
			dp[i][j] = -1;
			pal[i][j] = -1;
		}
	}
	usingMCMRec(str,length,0,length -1);

	printf("Min cuts needed for Palindrome Partitioning is---> %d\n",dp[0][length-1]);


	printf("\n\nFollowing is DP Array..:\n");

	for( int i=0; i<length; i++)
	{
		printf("\n");
		for( int j=0; j<length; j++)
		{
			if(dp[i][j] > -1)
				printf(" ");
			printf("%d ",dp[i][j]);
		}
	}

	printf("\n\nFollowing is Palindrome Array..:\n");
	for( int i=0; i<length; i++)
	{
		printf("\n");
		for( int j=0; j<length; j++)
		{
			if(dp[i][j] > -1)
				printf(" ");
			printf("%d ",pal[i][j]);
		}
	}
}

// Driver program to test above function
int main()
{

   //char str[] = "ababbbabbababa";
   char str[] = "abccbab";
   minPalPartion(str);
   return 0;
}