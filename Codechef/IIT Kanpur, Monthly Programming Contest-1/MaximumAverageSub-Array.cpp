/*
 * MaximumAverageSub-Array.cpp
 *
 *  Created on: Oct 1, 2014
 *      Author: Apratim
 */

/*
 Maximum Average Sub-Array
 Problem code: IITK1P05

 ALL SUBMISSIONS
 All submissions for this problem are available.

 You are given a sequence of N integers, a[1], a[2], , , , a[N].


 Find out the maximum possible average value of sub-sequences of array a.
 Input

 First line of the input contains a single integer T denoting number of test cases
 For each test case, first line contains a single integer denoting N, the number of elements of array a.


 Next line contains N space separated integers denoting the array a.
 Output

 Print T lines each line containing the maximum possible average value. Your answer will be considered correct if it's absolute or relative error is less than 10 -6.
 Constraints

 1 ≤ T ≤ 10
 2 ≤ N ≤ 1000
 1 ≤ A[i] ≤ 10^5
 Example

 Input:
 1
 5
 1 3 2 1 3
 Output:
 3
 */
#include <map>
#include <set>
#include <cstring>
#include <stack>
#include <vector>
#include <queue>
#include <list>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <climits>

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

void scanint(ll int &x) {
	register ll int c = gc();
	x = 0;
	for (; (c < 48 || c > 57); c = gc())
		;
	for (; c > 47 && c < 58; c = gc()) {
		x = (x << 1) + (x << 3) + c - 48;
	}
}

int readline(char * str) {

	int i = 0;
	char ch;
	while ((ch = getchar()) != '\n') {
		str[i++] = ch;
	}
	str[i] = '\0';
	return i;
}

#define ASIZE 10
#define N 1010

int main(int argc, char * argv[]) {

	int t;
	int arraySize;

	scanf("%d", &t);
	ll int a[N];
	ll max;

	while (t--) {
		sll(arraySize);
		max = LLONG_MIN;
		for (ll i = 0; i < arraySize; i++) {
			sll(a[i]);
			if (a[i] > max)
				max = a[i];
		}

		pll(max);
	}
	return 0;
}
