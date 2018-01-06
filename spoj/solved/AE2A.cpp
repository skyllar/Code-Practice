/*
SPOJ Problem Set (classical)

4303. Dice

Problem code: AE2A



Jack claims that he has telekinetic powers. He has made a bet with Mike that he would throw a die n times and would get exactly k pips in total. Jack's die has 6 faces with numbers from 1 to 6 written on them and is perfectly symmetric. Mike does not believe in Jack's telekinetic powers (in general, being a tenacious rationalist, he does not believe in telekinesis), but he is concerned that Jack could win the bet simply by luck. Therefore, he would like to know what is the chance (in percent) of such an unlucky event, and asked you to write a program that would help him solve this problem.

Input

The first line of the standard input contains a single integer t (1 ≤ t ≤ 20) denoting the number of test cases. Each of the following t lines contains a description of one test case in the form of two integers ni and ki (1 ≤ ni, ki ≤ 106) separated by a single space.

Output

To the standard output t lines should be written, containing the answers to respective test cases. The answer to one test case is the probability (in percent) that Jack wins the bet, rounded down to the nearest integer.

Example

For the input data:

1
1 6
the correct result is:

16
*/
#include<stdio.h>
#include<stdlib.h>
#include <math.h>       /* floor */


int main()
{
	long double **dp;
	long long int n[30],k[30];
	long long int maxN=0,maxK=0,testCases,i,j;

	scanf("%lld",&testCases);

	for( i=0; i<testCases; i++)
	{
		scanf("%lld %lld",&n[i],&k[i]);
		if(maxN<n[i])
			maxN = n[i];
		if(maxK<k[i])
			maxK = k[i];
	}

	dp = (long double **)malloc((maxN+1)*sizeof(long double *));
	
	for( i=0; i<=maxN; i++)
	{
		 dp[i] = (long double *)calloc(maxK+1,sizeof(long double));

		 if( i<= maxK && i!= 0)
		 {
		 	if( i== 1)
		 	{
		 		//dp[1][1] = 1.0;
		 		dp[1][1] = 100.0/6.0;
		 	}
		 	else
		 	{
		 		//dp[i][i] = 1.0;
		 		dp[i][i] = dp[i-1][i-1]/6.0;
		 	}
		 }
	}

	//dp[1][6]=dp[1][5]=dp[1][4]=dp[1][3]=dp[1][2]=1.0;
	dp[1][6]=dp[1][5]=dp[1][4]=dp[1][3]=dp[1][2]=100.0/6.0;
	//printf("MaxK:%d,MaxN:%d\n",maxK,maxN);

	for( i=2; i<=maxN; i++)
	{
		for( j=i+1; j<=maxK && j <= i*6; j++)
		{
			//printf("$$Start,i:%d,j:%d\n",i,j);
			if( j <= (6*i -5) )
			{
				//dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
				dp[i][j] = dp[i][j-1] + dp[i-1][j-1]/6.0;
				//dp[i][j] = (dp[i][j-1]*6 + dp[i-1][j-1])/6.0;
				//printf("If Sum = %d,Then Times=%f\n",j,dp[i][j]);
			}
			else
			{
				dp[i][j] = dp[i][12*i - 10 -j];
				//printf("If Sum = %d,Then Times=%f,12*i - 10 -j:%d\n",j,dp[i][12*i - 10 -j],12*i - 10 -j);

			}
		}
	}

	/*for( i=1; i<=maxN; i++)
	{
		printf("For Dice Count N:%d---------->\n",i);
		for( j=0; j<=maxK; j++)
		{
			printf("If dp[%d][%d] = %d\n",i,j,(int)dp[i][j]);

		}
		printf("\n");
	}*/
	for( i=0; i<testCases; i++)
	{
		long long int a = (long long int)(floorl(dp[n[i]][k[i]]));

		printf ("%lld\n", a);
	}

	return 0;
}