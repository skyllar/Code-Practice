/*
 * Matrix Chain Multiplication.cpp
 *
 *  Created on: Nov 14, 2014
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

int MatrixChainOrder(int *arr, int n) {

	int a[n][n];
	int numberOfMatrix = n - 1;
	int i, j, k, l;
	//matrix count start from 1
	for (i = 1; i <= numberOfMatrix; i++)
		a[i][i] = 0;

	for (l = 2; l <= numberOfMatrix; l++) {
		for (i = 1; i < numberOfMatrix - l + 2; i++) {
			j = i + l - 1;

			a[i][j] = INT_MAX;

			for (k = i; k < j; k++) {

				int temp = a[i][k] + a[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
				if (a[i][j] > temp)
					a[i][j] = temp;
			}
		}
	}

	return a[1][numberOfMatrix];

}
int main() {
	int arr[] = { 1, 2, 3, 4 };
	int size = sizeof(arr) / sizeof(arr[0]);

	printf("Minimum number of multiplications is %d ",
			MatrixChainOrder(arr, size));

	getchar();
	return 0;
}
