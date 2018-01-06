/*
 * Word Wrap Problem.cpp
 *
 *  Created on: Nov 15, 2014
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
#include<limits.h>

int min(int i, int j) {
	return (i < j ? i : j);
}

int solveWordWrap(int *wordSize, int totalWidth, int totalWord) {

	int lc[totalWord][totalWord];
	int c[totalWord];
	int p[totalWord];
	int i, j;

	for (i = 0; i < totalWord; i++)
		c[i] = INT_MAX;

	for (i = 0; i < totalWord; i++) {
		for (j = i; j < totalWord; j++) {

			if (i == j)
				lc[i][j] = totalWidth - wordSize[i];
			else {
				if (lc[i][j - 1] == INT_MAX)
					lc[i][j] = INT_MAX;
				else {
					if (wordSize[j] <= lc[i][j - 1] - 1)
						lc[i][j] = lc[i][j - 1] - 1 - wordSize[j];
					else {
						lc[i][j] = INT_MAX;
					}
				}
			}
		}
	}

	c[0] = totalWidth - wordSize[0];

	for (i = 1; i < totalWord; i++) {
		for (j = 1; j <= i; j++) {

			if (lc[j][i] != INT_MAX) {
				if (lc[j][i] + c[j - 1] < c[i]) {
					c[i] = lc[j][i] + c[j - 1];
					p[i] = j;
				}
			}
		}
	}

	p[0] = 0;

	for (int k = 0; k < totalWord; k++) {
		printf("%d ", p[k]);
	}
	printf("\n");
	for (int k = 0; k < totalWord; k++) {
		printf("%d ", k);
	}
	printf("\n");

	//int printSolution(int *, int);

	//printSolution(p, totalWord + 1);
	printf("Answer: %d\n", c[totalWord - 1]);
}

int printSolution(int p[], int n) {
	int k;
	if (p[n] == 1)
		k = 1;
	else
		k = printSolution(p, p[n] - 1) + 1;
	printf("Line number %d: From word no. %d to %d \n", k, p[n], n);
	return k;
}

// Driver program to test above functions
int main() {
	int l[] = { 3, 2, 2, 5 };
	int n = sizeof(l) / sizeof(l[0]);
	int M = 6;
	solveWordWrap(l, M, n);
	return 0;
}
