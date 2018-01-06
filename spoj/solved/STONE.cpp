/*
SPOJ Problem Set (classical)

40. Lifting the Stone

Problem code: STONE



There are many secret openings in the floor which are covered by a big heavy stone. When the stone is lifted up, a special mechanism detects this and activates poisoned arrows that are shot near the opening. The only possibility is to lift the stone very slowly and carefully. The ACM team must connect a rope to the stone and then lift it using a pulley. Moreover, the stone must be lifted all at once; no side can rise before another. So it is very important to find the centre of gravity and connect the rope exactly to that point. The stone has a polygonal shape and its height is the same throughout the whole polygonal area. Your task is to find the centre of gravity for the given polygon.

Input

The input consists of T test cases (equal to about 500). The number of them (T) is given on the first line of the input file. Each test case begins with a line containing a single integer N (3 <= N <= 1000000) indicating the number of points that form the polygon. This is followed by N lines, each containing two integers Xi and Yi (|Xi|, |Yi| <= 20000). These numbers are the coordinates of the i-th point. When we connect the points in the given order, we get a polygon. You may assume that the edges never touch each other (except the neighbouring ones) and that they never cross. The area of the polygon is never zero, i.e. it cannot collapse into a single line.

Output

Print exactly one line for each test case. The line should contain exactly two numbers separated by one space. These numbers are the coordinates of the centre of gravity. Round the coordinates to the nearest number with exactly two digits after the decimal point (0.005 rounds up to 0.01). Note that the centre of gravity may be outside the polygon, if its shape is not convex. If there is such a case in the input data, print the centre anyway.

Example


Sample Input:
2
4
5 0
0 5
-5 0
0 -5
4
1 1
11 1
11 11
1 11

Sample output:

0.00 0.00
6.00 6.00
*/

#include<stdio.h>

double x[1111111],y[1111111];

int main()
{
	
	long long int i,testCases;
	long long int points;
	double A,Cx,Cy;
	double tempA;
	double x1,y1;

	scanf("%lld",&testCases);

	while( testCases-- )
	{
		scanf("%lld",&points);

		tempA = 0.0;
		Cx= 0.0;
		Cy= 0.0;
		A=0;
		for( i=0; i<points; i++ )
		{
			scanf("%lf %lf",&x[i],&y[i]);

		}
		x[points] = x[0];
		y[points] = y[0];
		for( i=0; i < points; i++ )
		{
			tempA = x[i]*y[i+1] - x[i+1]*y[i];
			A = A + tempA;
			Cx += tempA*(x[i] + x[i+1]);
			Cy += tempA*(y[i] + y[i+1]);
		}
		A /= 2.0;
		Cx /= 6.0*A;
		Cy /= 6.0*A;
		printf("%.2lF %.2lF\n", Cx,Cy); 
		//printf("%l %l",x1,y1);

	}

	return 0;
}
