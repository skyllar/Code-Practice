/*
Roy's Rectangle
Problem
Submissions
Leaderboard
Discussions
Roy is standing on a lattice point ( point with integer co-ordinates ) (x,y) inside an axis-parallel rectangle. The lower left corner of the rectangle is (x1,y1) and the upper right corner is (x2,y2). If Roy walks only along the grid lines, what is the minimum euclidean distance he needs to travel to reach the rectangle's border.

Input Format 
The first line of input contains T, the number of test cases. Each of the next T lines contains 6 space separated integers x,y,x1,y1,x2,y2.
*/

#include<stdio.h>


#define llu long long int
#define sllu(x) scanf("%llu",&x)
#define pllu(y) printf("%llu\n",y)

llu min(llu x, llu y)
{
	if(x > y)
		return y;
	else
		return x;
}

int main()
{
	int testCases;
			llu x,y,x1,y1,x2,y2;

	scanf("%d",&testCases);

	while( testCases-- )
	{
		sllu(x);
		sllu(y);
		sllu(x1);
		sllu(y1);
		sllu(x2);
		sllu(y2);
		
		x = min(x - x1,x2 - x);
		y = min(y2 - y,y - y1);
		pllu(min(x,y));
	}
	return 0;
}