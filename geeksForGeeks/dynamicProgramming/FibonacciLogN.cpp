/*
 * FibonacciLogN.cpp
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

int m[2][2] = { { 1, 1 }, { 1, 0 } };

void multiply(int a[2][2], int b[2][2]) {
	int c[2][2];
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			c[i][j] = b[i][j];

	int temp = a[0][0];
	a[0][0] = a[0][0] * c[0][0] + a[0][1] * c[1][0];
	a[0][1] = temp * c[0][1] + a[0][1] * c[1][1];

	temp = a[1][0];
	a[1][0] = a[1][0] * c[0][0] + a[1][1] * c[1][0];
	a[1][1] = temp * c[0][1] + a[1][1] * c[1][1];
}

void power(int F[2][2], int n) {
	if (n == 0 || n == 1)
		return;
	int M[2][2] = { { 1, 1 }, { 1, 0 } };

	power(F, n / 2);
	multiply(F, F);

	if (n % 2 != 0)
		multiply(F, M);
}

int fib(int n) {

	int o[2][2] = { { 1, 1 }, { 1, 0 } };

	//power(o, n);

	while (n != 0 && n != 1) {
		multiply(o, o);
		if (n % 2 == 1)
			multiply(o, m);
		n /= 2;
	}

	return o[0][1];
}

int main() {
	int n = 9;
	printf("%d", fib(10));
	getchar();
	return 0;
}
