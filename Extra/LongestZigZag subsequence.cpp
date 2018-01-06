/*

 * LongestZigZag subsequence.cpp
 *
 *  Created on: Nov 30, 2014
 *      Author: Apratim
 */

/*
 Longest ZigZag subsequence
 A sequence of numbers is called a zig­zag sequence if the differences between successive
 numbers strictly alternate between positive and negative. The first difference (if one exists)
 may be either positive or negative. A sequence with fewer than two elements is trivially a
 zig­zag sequence.
 For example, 1,7,4,9,2,5 is a zig­zag sequence because the differences (6,­3,5,­7,3) are
 alternately positive and negative. In contrast, 1,4,7,2,5 and 1,7,4,5,5 are not zig­zag
 sequences, the first because its first two differences are positive and the second because its
 last difference is zero.
 Given a sequence of integers, sequence, return the length of the longest subsequence of
 sequence that is a zig­zag sequence. A subsequence is obtained by deleting some number of
 elements (possibly zero) from the original sequence, leaving the remaining elements in their
 original order.
 ex: 1,7,4,9,2,5 output = 6
 */

#include <cstdio>
#include <iostream>
#include<string.h>

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

int getLongestPath(int a[], int length) {

	int maxZigZagSequence = 0;

	int asPeak[length];
	int asNonPeak[length];

	for (int i = 0; i < length; i++) {
		asNonPeak[i] = 1;
		asPeak[i] = 1;
	}

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < i; j++) {

			//checking as non-peak
			if (a[i] < a[j] && asPeak[j] + 1 > asNonPeak[i])
				asNonPeak[i] = asPeak[j] + 1;

			//checking as peak
			if (a[i] > a[j] && asNonPeak[j] + 1 > asPeak[i])
				asPeak[i] = asNonPeak[j] + 1;

		}

		if (maxZigZagSequence < asNonPeak[i])
			maxZigZagSequence = asNonPeak[i];
		if (maxZigZagSequence < asPeak[i])
			maxZigZagSequence = asPeak[i];
	}

	return maxZigZagSequence;
}

int main(int argc, char * argv[]) {

	int a[] = { 1, 1, 1, 1, 1, 1 };

	cout << getLongestPath(a, sizeof(a) / sizeof(int)) << "\n";

	return 0;
}
