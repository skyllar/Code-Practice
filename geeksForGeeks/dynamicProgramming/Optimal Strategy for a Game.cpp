/*
 * Optimal Strategy for a Game.cpp
 *
 *  Created on: Nov 16, 2014
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

// C program to find out maximum value from a given sequence of coins
#include <stdio.h>
#include <limits.h>

// Utility functions to get maximum and minimum of two intgers
int max(int a, int b) {
	return a > b ? a : b;
}
int min(int a, int b) {
	return a < b ? a : b;
}

// Returns optimal value possible that a player can collect from
// an array of coins of size n. Note than n must be even
int optimalStrategyOfGame(int* arr, int n) {

	int dp[n][n];

	for (int i = 0; i < n; i++)
		dp[i][i] = arr[i];

	for (int i = 0; i < n - 1; i++)
		dp[i][i + 1] = max(arr[i], arr[i + 1]);

	for (int gap = 2; gap < n; gap++) {

		for (int i = 0; i < n - gap; i++) {
			int j = i + gap;

			//			x = ((i + 2) <= j) ? dp[i + 2][j] : 0;
			//			y = ((i + 1) <= (j - 1)) ? dp[i + 1][j - 1] : 0;
			//			z = (i <= (j - 2)) ? dp[i][j - 2] : 0;
			//
			//			dp[i][j] = max(arr[i] + min(x, y), arr[j] + min(y, z));

			int s1 = min(dp[i + 2][j], dp[i + 1][j - 1]) + arr[i];
			int s2 = min(dp[i][j - 2], dp[i + 1][j - 1]) + arr[j];
			dp[i][j] = max(s1, s2);
		}
	}

	return dp[0][n - 1];
}
// Driver program to test above function
int main() {
	int arr1[] = { 8, 15, 3, 7 };
	int n = sizeof(arr1) / sizeof(arr1[0]);
	printf("%d\n", optimalStrategyOfGame(arr1, n));

	int arr2[] = { 2, 2, 2, 2 };
	n = sizeof(arr2) / sizeof(arr2[0]);
	printf("%d\n", optimalStrategyOfGame(arr2, n));

	int arr3[] = { 20, 30, 2, 2, 2, 10 };
	n = sizeof(arr3) / sizeof(arr3[0]);
	printf("%d\n", optimalStrategyOfGame(arr3, n));

	return 0;
}
