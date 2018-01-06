/*
 * Longest Arithmetic Progression.cpp
 *
 *  Created on: Nov 13, 2014
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

int dp[100][100];

#include<stdlib.h>
#include<string.h>

int lenghtOfLongestAP(int *a, int n) {

	memset(dp, 0, sizeof(dp));

	int i, j, k;

	for (i = 0; i < n - 1; i++)
		dp[i][n - 1] = 2;

	for (j = n - 2; j > 0; j--) {

		i = j - 1;
		k = j + 1;

		while (i >= 0 && k < n) {
			if (a[i] + a[k] == 2 * a[j]) {
				dp[i][j] = dp[j][k] + 1;
				i--;
				k++;
				//break;
			} else {
				dp[i][j] = 2;
				if (a[i] + a[k] > 2 * a[j]) {
					i--;
				} else {
					k++;
				}
			}

		}

		while (i >= 0) {
			dp[i][j] = 2;
			i--;
		}

	}

	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (max < dp[i][j])
				max = dp[i][j];
		}
	}

	return max;
}

/* Drier program to test above function*/
int main() {
	int set1[] = { 1, 7, 10, 13, 14, 19 };
	int n1 = sizeof(set1) / sizeof(set1[0]);
	cout << lenghtOfLongestAP(set1, n1) << endl;

	int set2[] = { 1, 7, 10, 15, 27, 29 };
	int n2 = sizeof(set2) / sizeof(set2[0]);
	cout << lenghtOfLongestAP(set2, n2) << endl;

	int set3[] = { 2, 4, 6, 8, 10 };
	int n3 = sizeof(set3) / sizeof(set3[0]);
	cout << lenghtOfLongestAP(set3, n3) << endl;

	return 0;
}
