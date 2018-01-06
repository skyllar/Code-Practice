/*
 * UglyNumbers.cpp
 *
 *  Created on: Nov 12, 2014
 *      Author: Apratim
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

#include<stdlib.h>

unsigned min(unsigned a, unsigned b, unsigned c) {
	if (a <= b) {
		if (a <= c)
			return a;
		else
			return c;
	}
	if (b <= c)
		return b;
	else
		return c;
}

unsigned getNthUglyNo(unsigned n) {

	unsigned *uglyArray = (unsigned *) malloc(sizeof(unsigned) * (n + 1));
	unsigned i2 = 0, i3 = 0, i5 = 0;
	uglyArray[0] = 1;

	unsigned nextMul2 = 2;
	unsigned nextMul3 = 3;
	unsigned nextMul5 = 5;

	unsigned cur;

	for (unsigned i = 1; i < n + 1; i++) {
		cur = min(nextMul2, nextMul3, nextMul5);
		uglyArray[i] = cur;

		if (cur == nextMul2) {
			i2++;
			nextMul2 = uglyArray[i2] * 2;
		}
		if (cur == nextMul3) {
			i3++;
			nextMul3 = uglyArray[i3] * 3;
		}

		if (cur == nextMul5) {
			i5++;
			nextMul5 = uglyArray[i5] * 5;
		}

	}

	return uglyArray[n - 1];
}

int main(int argc, char * argv[]) {

	unsigned no = getNthUglyNo(150);
	printf("%dth ugly no. is %d ", 150, no);
	getchar();
	return 0;
}
