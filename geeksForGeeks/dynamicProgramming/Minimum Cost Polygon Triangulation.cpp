/*
 * Minimum Cost Polygon Triangulation.cpp
 *
 *  Created on: Nov 13, 2014
 *      Author: Apratim
 */

#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

#define TRACE
#define DEBUG
#ifdef TRACE
#define trace1(x)                cerr <<"\n"<< #x << ": " << x << endl;
#define trace2(x, y)             cerr<<"\n" << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr<<"\n" << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr <<"\n"<< #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr <<"\n"<< #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr <<"\n"<< #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif

#define si(x) scanf("%d" , &x)
#define sl(x) scanf("%ld" , &x)
#define sll(x) scanf("%lld" , &x)
#define sc(x) scanf("%c" , &x)
#define ss(x) scanf("%s" , &x)

#define pi(x) printf("%d\n" , x)
#define pl(x) printf("%ld\n" , x)
#define pll(x) printf("%lld\n" , x)
#define pc(x) printf("%c\n" , x)
#define ps(x) printf("%s\n" , x)

#define fup(i,a,b) for(int i=a;i<b;i++)
#define fdn(i,a,b) for(int i=a;i>=b;i--)

#define gc getchar
#define ll long long

#define MAX 1000000.0

struct Point {
	int x, y;
};

// Utility function to find minimum of two double values
double min(double x, double y) {
	return (x <= y) ? x : y;
}

// A utility function to find distance between two points in a plane
double dist(Point p1, Point p2) {
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// A utility function to find cost of a triangle. The cost is considered
// as perimeter (sum of lengths of all edges) of the triangle
double cost(Point points[], int i, int j, int k) {
	Point p1 = points[i], p2 = points[j], p3 = points[k];
	return dist(p1, p2) + dist(p2, p3) + dist(p3, p1);
}

double mTC(Point points[], int startPoint, int endPoint) {

	if (endPoint < startPoint + 2) {
		return 0;
	} else {
		double temp = MAX;

		for (int breakPoint = startPoint + 1; breakPoint < endPoint; breakPoint++) {
			temp = min(
					mTC(points, startPoint, breakPoint) + mTC(points,
							breakPoint, endPoint) + cost(points, startPoint,
							breakPoint, endPoint), temp);
		}
		return temp;
	}

}

double mTCIterative(Point points[], int startPoint, int endPoint) {

	double dp[100][100];


}

// Driver program to test above functions
int main() {
	Point points[] = { { 0, 0 }, { 1, 0 }, { 2, 1 }, { 1, 2 }, { 0, 2 } };
	int n = sizeof(points) / sizeof(points[0]);
	cout << mTC(points, 0, n - 1);

	cout << mTCIterative(points, 0, n - 1);

	return 0;
}
