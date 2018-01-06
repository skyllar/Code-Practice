/*
 * Cube IV.cpp
 *
 *  Created on: Nov 9, 2014
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

#include <stdlib.h>
#include<stdio.h>

int a[1001][1001];
int dp[1001][1001];
int globalMax = -1;
int globalMaxLength = -1;

void calculate(int s) {
	int i;
	for (int k = 0; k < s; k++) {

		//printf("\n----Iteration Count:%d\n", k);
		for (int i = 0; i < s; i++) {

			for (int j = 0; j < s; j++) {

				if (i != 0 && a[i - 1][j] == a[i][j] + 1) {
					if (dp[i - 1][j] + 1 > dp[i][j])
						dp[i][j] = dp[i - 1][j] + 1;
				}

				if (i != s - 1 && a[i + 1][j] == a[i][j] + 1) {
					if (dp[i + 1][j] + 1 > dp[i][j])
						dp[i][j] = dp[i + 1][j] + 1;
				}
				if (j != s - 1 && a[i][j + 1] == a[i][j] + 1) {
					if (dp[i][j + 1] + 1 > dp[i][j])
						dp[i][j] = dp[i][j + 1] + 1;
				}
				if (j != 0 && a[i][j - 1] == a[i][j] + 1) {
					if (dp[i][j - 1] + 1 > dp[i][j])
						dp[i][j] = dp[i][j - 1] + 1;
				}

				if (globalMaxLength < dp[i][j]) {
					globalMaxLength = dp[i][j];
					globalMax = a[i][j];
				} else if (globalMaxLength == dp[i][j]) {
					if (globalMax > a[i][j]) {
						globalMax = a[i][j];
					}

				}
				//printf("%d ", dp[i][j]);
			}
			//printf("\n");
		}
	}
}

int main(int argc, char * argv[]) {

	int t, i, j;
	int s;

	scanf("%d", &t);

	for (int k = 0; k < t; k++) {

		globalMax = -1, globalMaxLength = -1;
		scanf("%d", &s);
		for (i = 0; i < s; i++) {
			for (j = 0; j < s; j++) {
				scanf("%d", &a[i][j]);
				dp[i][j] = 1;
			}
		}

		calculate(s);

		printf("Case #%d: %d %d\n", k + 1, globalMax, globalMaxLength);

	}
	return 0;
}
