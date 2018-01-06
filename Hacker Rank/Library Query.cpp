/*
A giant library has just been inaugurated this week. It can be modeled as a sequence of N consecutive shelves with each shelf having some number of books. Now, being the geek that you are, you thought of the following two queries which can be performed on these shelves.

Change the number of books in one of the shelves.

Obtain the number of books on the shelf having the kth rank within the range of shelves.

A shelf is said to have the kth rank if its position is k when the shelves are sorted based on the number of the books they contain, in ascending order.

Can you write a program to simulate the above queries?

Input Format
The first line contains a single integer T, denoting the number of test cases.
The first line of each test case contains an integer N denoting the number of shelves in the library.
The next line contains N space separated integers where the ith integer represents the number of books on the ith shelf where 1<=i<=N.
The next line contains an integer Q denoting the number of queries to be performed. Q lines follow with each line representing a query.
Queries can be of two types:

1 x k - Update the number of books in the xth shelf to k (1 <= x <= N).
0 x y k - Find the number of books on the shelf between the shelves x and y (both inclusive) with the kth rank (1 <= x <= y <= N, 1 <= k <= y-x+1).
Output Format
For every test case, output the results of the queries in a new line.

Constraints
1 <= T <= 5
1 <= N <= 104
1 <= Q <= 104
The number of books on each shelf is always guaranteed to be between 1 and 1000.

Sample Input

2
2
1 2
2
0 1 2 1
0 1 2 2
4
4 3 2 1
4
0 1 1 1
1 1 1
0 1 1 1
0 1 4 3
Sample Output

1
2
4
1
2
Explanation

There are two test cases :

The first test case contains only two shelves which can be represented as [1, 2]. Two queries are to be processed :

i) The first query asks for smallest number of books between the 1st and 2nd shevles which is 1.

ii) The second query asks for the 2nd smallest number of books between the 1st and 2nd shevles which is 2.

The second test case contains four shelves which can be represented as [4, 3, 2, 1]. Four queries are to be processed :

i) The first query asks for the smallest number of books in the 1st shelf which is 4.

ii) The second query updates the number of books in the 1st shelf to 1. Hence the shelves now look like [1, 3, 2, 1].

iii) The third query asks for the smallest number of books in the 1st shelf which is now 1.

iv) The last query asks for the 3rd smallest number of books between the 1st and 4th shelves which is 2.
*/

#include<stdio.h>
#include<iostream>

using namespace std;

int bookShelve[10500];
int hashCount[10500];


int findKthSmallest(int shelve1,int shelve2,int findSmallest,int n)
{
	int i,k = 0;
	long maxCount=1,minCount=99999;

	for ( i = shelve1 ; i <= shelve2 ; i++ )
	{
		//printf("bookShelve[%d]=%d\n",i,bookShelve[i]);
	/*	if ( maxCount < bookShelve[i] )
			maxCount = bookShelve[i];
		if ( minCount > bookShelve[i] )
			minCount = bookShelve[i]; */

		hashCount[bookShelve[i]]++;
	}

	//printf("minCount:%ld,maxCount:%ld",minCount,maxCount);

	//for ( i = minCount ; i <=  maxCount; i++ )
	for ( i = 1 ;i <= 1000 ;i++)
	{
		k += hashCount[i];
		//printf("hashCount[%d] :%lld\n,k:%d\n",i,hashCount[i],k);
		hashCount[i] = 0;
		if ( k >=  findSmallest ) 
			break;
	}
	k =i;
	//for(;i<= maxCount;i++)
	for(;i<= 1000;i++)
		hashCount[i] = 0;
	
	return k;	
}

int main()
{
	int t,n,q,i;
	int queryType;
	int shelve1;
	int shelve2;
	int updateCount;
	int findSmallest;

	//cout <<"Enter Test Cases:\n";
	scanf("%d",&t);
	
	while((t--) > 0)
	{
		//cout <<"number of shelves in the library:\n";
		scanf("%d",&n);

		//cout<<"Enter space separated integers where the ith integer represents the number of books on the ith shelf where 1<=i<=N\n";
		for ( i=1 ; i <=n ; i++)
		{
			scanf("%d",&bookShelve[i]);
			//printf("Input ----bookShelve[%lld]=%lld\n",bookShelve[i]);
		}

		//cout<<"Enter The number of queries to be performed:\n";
		scanf("%d",&q);

		while ( ( q-- ) > 0 )
		{
			//cout<<"Your Query:\n";
			scanf("%d",&queryType);
			
			switch(queryType)
			{
				case 1:scanf("%d %d",&shelve1,&updateCount);
					   bookShelve[shelve1]=updateCount;
					   break;

				case 0:scanf("%d %d %d",&shelve1,&shelve2,&findSmallest);
					   cout<<findKthSmallest(shelve1,shelve2,findSmallest,n)<<"\n";
					   break;
			}
		}

	}

	return 0; 
}
