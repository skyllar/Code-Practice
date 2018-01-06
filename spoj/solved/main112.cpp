/*
SPOJ Problem Set (classical)

9387. Special String

Problem code: MAIN113



A string of letters X, Y, Z is special if there are three consecutive letters from which one is X, one is Y, and one is Z. For example, XYZXYZ is special, while XXYYZ is not. Your task is to calculate how many such strings of length n are not special.

Input

First line contains an integer T(1 <= T <= 30) which denotes the total number of test cases. Each test case contains an integer N(1 <= N <= 30) in a single line.

Output

For each test case print total number of strings which have a length N and are not special.

Example

Input:
1
2

Output:
9
*/

#include<stdio.h>

int main()
{
	int t,n,i;
	long long int ans[31];
	ans[0] = 0;
	ans[1] = 3;
	ans[2] = 9;
	for( i=3 ;i<31 ; i++)
		ans[i] = 2*(ans[i-1])+ans[i-2];

	scanf("%d",&t);
	

	while( t-- )
	{
		scanf("%d",&n);
		printf("%lld\n",ans[n]);
	}

	return 0;
}