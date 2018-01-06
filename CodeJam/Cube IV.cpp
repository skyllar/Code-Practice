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

int visited[1001][1001];
int a[1001][1001];
int dp[1001][1001];
int globalMax = -1;
int globalMaxLength = -1;

int rec(int s, int i, int j) {

	//printf("i=%d j=%d\n", i, j);

	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	int temp;
	visited[i][j] = 1;
	int maxLength = 1;

	if (i != 0 && a[i - 1][j] == a[i][j] + 1 && visited[i - 1][j] == 0) {
		if (dp[i - 1][j] == -1)
			temp = rec(s, i - 1, j);
		else
			temp = dp[i - 1][j];
		if (maxLength < temp + 1)
			maxLength = temp + 1;
	}

	if (i != s - 1 && a[i + 1][j] == a[i][j] + 1 && visited[i + 1][j] == 0) {
		if (dp[i + 1][j] == -1)
			temp = rec(s, i + 1, j);
		else
			temp = dp[i + 1][j];
		if (maxLength < temp + 1)
			maxLength = temp + 1;
	}
	if (j != s - 1 && a[i][j + 1] == a[i][j] + 1 && visited[i][j + 1] == 0) {
		if (dp[i][j + 1] == -1)
			temp = rec(s, i, j + 1);
		else
			temp = dp[i][j + 1];
		if (maxLength < temp + 1)
			maxLength = temp + 1;
	}
	if (j != 0 && a[i][j - 1] == a[i][j] + 1 && visited[i][j - 1] == 0) {
		if (dp[i][j - 1] == -1)
			temp = rec(s, i, j - 1);
		else
			temp = dp[i][j - 1];
		if (maxLength < temp + 1)
			maxLength = temp + 1;
	}

	//dp[i][j] = maxLength;
	if (globalMaxLength < maxLength) {
		globalMaxLength = maxLength;
		globalMax = a[i][j];
	} else if (globalMaxLength == maxLength) {
		if (globalMax > a[i][j]) {
			globalMax = a[i][j];
		}
	}

	visited[i][j] = 0;
	return maxLength;
}

void calculate(int s) {
	int i;

	for (int i = 0; i < s; i++) {

		for (int j = 0; j < s; j++) {

			if (dp[i][j] == -1)
				dp[i][j] = rec(s, i, j);

			//break;
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
				dp[i][j] = -1;
				visited[i][j] = 0;
			}
		}

		calculate(s);

		printf("Case #%d: %d %d\n", k + 1, globalMax, globalMaxLength);

		printf("\n______________________\n");
		for (int i = 0; i < s; i++) {
			printf("\n");
			for (j = 0; j < s; j++) {
				printf("%d ", dp[i][j]);
			}
		}
		printf("\n_____________________\n");
	}
	return 0;
}
