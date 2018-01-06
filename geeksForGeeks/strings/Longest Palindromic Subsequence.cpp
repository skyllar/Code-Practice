#include <stdio.h>
#include <cstring>
#include <limits.h>

int dp[100][100];

int max(int t1, int t2, int t3)
{
	if( t1 > t2)
	{
		if( t1 > t3)
			return t1;
		else
			return t3;
	}
	else
	{
		if( t2 > t3)
			return t2;
		else
			return t3;
	}
}

int rec(char *str,int start,int last)
{
	//printf("\nstart = %d,last = %d\n",start,last);
	int i = start,j=last;
	if( start == last)
	{
		//pal[start][last] = 1;
		dp[start][last] = 1;
		printf("\n-------\n");
		return dp[start][last];
	}

	if(start == last-1)
	{
		if(str[start] == str[last])
		{
			//pal[start][last] = 1;
			dp[start][last] = 2;
			return dp[start][last];
		}
		else
		{
			//pal[start][last] = 0;
			dp[start][last] = 1;
			return dp[start][last];
		}
	}

	int temp1=0,temp2=0,temp3=0;


	if(dp[i+1][j] == -1)
		dp[i+1][j] = rec(str,i+1,j);
	temp2 = dp[i+1][j];

	if( str[i] == str[j] )
	{
		if(dp[i+1][j-1] == -1)
			dp[i+1][j-1] = rec(str,i+1,j-1);
		temp1 = dp[i+1][j-1]+2;
	}

	
	
	if(dp[i][j-1])
		dp[i][j-1] = rec(str,i,j-1);
	temp3 = dp[i][j-1];

	dp[i][j] = max(temp1,temp2,temp3);

	return dp[i][j] ;
}

int longestPalSubstr(char *str)
{
	int length = strlen(str);


	// for(int i =0 ; i < length; i++)
	// {
	// 	printf("%c ",str[i]);
	// }

	// printf("\n\n");

	// for(int i =0 ; i < length; i++)
	// {
	// 	printf("%c[%d] ",str[i],i);
	// }

	//printf("\n\n");

	for( int i=0; i<length; i++)
	{

		for( int j=0; j<length; j++)
		{
			dp[i][j] = -1;
			//pal[i][j] = -1;
		}
	}




	 rec(str,0,length -1);
	//printf("\n\n");

	for( int i=0; i<length; i++)
	{

		for( int j=0; j<length; j++)
		{
			printf("%d ",dp[i][j]);
			//pal[i][j] = -1;
		}
		printf("\n");
	}


	return dp[0][length-1];
}

// Driver program to test above function
// Driver program to test above functions
int main()
{
    //char str[] = "forgeeksskeegfor";
      char str[] = "forarbocfj";

    printf("\nLength is: %d\n", longestPalSubstr( str ) );
    return 0;
}