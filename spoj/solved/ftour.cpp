/*
SPOJ Problem Set (classical)

944. Free Tour

Problem code: FTOUR



In order to celebrate the 2nd anniversary of Travel Agent SPOJ (Safe – Professional – hOspitable – Joyful), the management intend to hold free tours around cities for clients to make them more satisfied with SPOJ.

A tour is a simple cycle, starting at any city (called a source-city) visits some other cities (each city must be visited at most once) and then returns to the source-city. The number of roads in the tour should be an even number because we are celebrating a 2nd anniversary, and 2 is even! Since many tours in different areas of the country are planned, the cost of organising them could turn out quite high. Hence, the management of SPOJ hope to find at least one 'reasonable' tour, which should have as small a number of roads as possible.

You're given maps of the areas where SPOJ wants to hold free tours. For each map, help them figure out a reasonable tour.

Input

The first line of input contains an integer t, the number of maps (t <= 5). t maps follow.

For each map:

In the first line there are 2 integers N – number of cities in that area, M – number of roads (1 <= N <= 8000, 0 <= M <= 10000)
In the next M lines, the i-th line describes the i-th road: a line with two integers a b denotes a bidirectional road between city a and city b
There is one blank line between successive tests.

Output

For each map, if there is no tour satisfying the conditions, write "-1" (without quotes). Otherwise, write one integer representing the number of roads in a reasonable tour, and in the next line show out the tour with form "source-city a b c .. source-city", that means the tour is source-city -> city a -> city b -> … -> source-city. If there are many tours satisfy in each map, any of them will be accepted.

Example

Input:
2

3 3
1 2 
2 3
3 1

4 4
1 2
2 3
3 4
4 1


Output:
-1
4
1 2 3 4 1
*/

#include<stdio.h>

int adjacency[8010][8010];

bool calculateHamPath(int *path,int adjacency[][8010],int vertices,int position,int *range,int rangeStart)
{
	bool value;
	int i;
	int temp;

	for ( i=rangeStart; i<=vertices; i++ )
	{
		if(adjacency[range[i]][path[position]] == 1)
		{
			path[position+1] = range[i];

			temp = range[rangeStart];
			range[rangeStart] = range[i];
			range[i] = temp;
			
			if( position+1 == vertices)
			{	
				if(adjacency[path[position+1]][1] == 1)
					return true;
				else
					return false;
			}

			value = calculateHamPath(path,adjacency,vertices,position+1,range,rangeStart+1);
			
			temp = range[rangeStart];
			range[rangeStart] = range[i];
			range[i] = temp;
			
			if (value)
				return true;
			else
				path[position+1] = -1;
		}
	}
	return	false;
}

int main()
{
	int path[8010];
	int range[8010];
	int vertices,edges;
	int testCases;
	int a,b,j,i;
	//scanf("%d",&testCases);
	
	//while( testCases-- )
	//{
		scanf("%d %d",&vertices,&edges);

		for(i=1;i<vertices+1;i++)
		{
			//path[i]=0;
			range[i]=i;
			for(j=1;j<vertices+1;j++)
				adjacency[i][j]=0;
		}

		while( edges-- )
		{
			scanf("%d %d",&a,&b);
			adjacency[a][b]=1;
			adjacency[b][a]=1;
		}
		path[1] = 1;
		if(calculateHamPath(path,adjacency,vertices,1,range,2))
		{
			//printf("%d\n",vertices);
			for(i=1;i<=vertices;i++)
				printf("%d ",path[i]);
			printf("%d\n",path[1]);
		}
		else
			printf("-1\n");
	//}
	
	return 0;
}