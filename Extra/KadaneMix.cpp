/*
 * KadaneMix.cpp
 *
 *  Created on: Dec 2, 2014
 *      Author: Apratim
 */
/*
 Given an array of 0s and 1s. You can choose two indices i and j and flip all the
 elements between them (ie 0­>1 and 1­>0). Find maximum sum of the array which can
 be   produced after the flip.
 eg For [0,1,0,0,1,0], output is 4…. flip from index 2 to 3. use kadane’s algo
 */
#include <cstdio>
#include <iostream>

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

void kadane(int *a, int size) {

	int b[size];

	int maxSumTillHere = 0;
	int curSumTillHere = 0;

	int curStartPoint = 0;

	int globalStartPoint;
	int globalEndPoint;

	for (int i = 0; i < size; i++) {
		if (a[i] == 0)
			b[i] = 1;
		else
			b[i] = -1;
	}

	for (int i = 0; i < size; i++) {
		curSumTillHere += b[i];

		if (curSumTillHere <= 0) {
			curSumTillHere = 0;
			curStartPoint = i + 1;
		} else {
			if (maxSumTillHere < curSumTillHere) {
				maxSumTillHere = curStartPoint;
				globalStartPoint = curStartPoint;
				globalEndPoint = i;
			}
		}
	}

	printf("StartPoint:%d,End Point:%d\n", globalStartPoint, globalEndPoint);
}

int main(int argc, char * argv[]) {

	int a[] = { 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1 };

	kadane(a, sizeof(a) / sizeof(int));
	return 0;
}
