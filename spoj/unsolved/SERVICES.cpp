/*
SPOJ Problem Set (classical)

703. Mobile Service

Problem code: SERVICE



A company provides service for its partners that are located in different towns. The company has three mobile service staff employees. If a request occurs at some location, an employee of the service staff must move from his current location to the location of the request (if no employee is there) in order to satisfy the request. Only one employee can move at any moment. They can move only on request and are not allowed to be at the same location. Moving an employee from location p to location q incurs a given cost C(p,q). The cost function is not necessarily symmetric, but the cost of not moving is 0, i.e. C(p,p)=0. The company must satisfy the received requests in a strict first-come, first-serve basis. The goal is to minimize the total cost of serving a given sequence of requests.

Task

You are to write a program that decides which employee of the service staff is to move for each request such that the total cost of serving the given sequence of requests is as small as possible.

Input

The first line of input contains the number of test cases - nTest. Each test case contains:

The first line of each test cases contains two integers, L and N. L (3 <= L <= 200) is the number of locations and N (1 <= N <= 1000) is the number of requests. Locations are identified by the integers from 1 to L. Each of the next L lines contains L non-negative integers. The jth number in the line i+1 is the cost C(i,j), and it is less than 2000.

The last of each test cases contains N integers, the list of the requests. A request is identified by the identifier of the location where the request occurs. Initially, the three service staff employees are located at location 1, 2 and 3, respectively.

Output

For each test case write the minimal total cost in a separate line.

Example

Input:
1
5 9
0 1 1 1 1
1 0 2 3 2
1 1 0 4 1
2 1 5 0 1
4 2 3 4 0
4 2 4 1 5 4 3 2 1
Output:
5
*/
#include<stdio.h>

long long int testCases,l,n;
long long int travelCost[202][202];
long long int requestFor[3002];

long long calculateMinCost(long long currentServiceLocation,long long int loc1,long long int loc2,long long int loc3)
{
	long long int a,b,c,min = 0;

	if( currentServiceLocation == l+1 )
		return 0;
	a = travelCost[loc1][currentServiceLocation] +calculateMinCost(currentServiceLocation+1,currentServiceLocation,loc2,loc3) ;
	b = travelCost[loc2][currentServiceLocation] +calculateMinCost(currentServiceLocation+1,loc1,currentServiceLocation,loc3) ;
	c = travelCost[loc2][currentServiceLocation] +calculateMinCost(currentServiceLocation+1,loc1,loc2,currentServiceLocation) ;
	if( a<b )
	{
		if( a<c )
			return a;
		else return c;
	}
	else
	{
		if( b<c )
			return b;
		else 
			return c;
	}
}
int main()
{
	
	long long int i,j;
	scanf("%lld",&testCases);
	while( testCases-- )
	{
		
		scanf("%lld %lld",&l,&n);
		for(i=1; i<=l; i++)
		{
			for(j=1; j<=l; j++)
			{
				scanf("%lld",&travelCost[i][j]);
			}
		}
		for(i=1; i<=n; i++)
		{
			scanf("%lld",&requestFor[i]);
		}
		
		printf("Ans---> %lld\n",calculateMinCost(1,1,2,3));
	}
	return 0;
}