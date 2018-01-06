/*
 * Given a number, find the next smallest palindrome.cpp
 *
 *  Created on: Dec 4, 2014
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

int AreAll9s(int *, int);

void propogate(num, int left, int right, carry) {


}

void generateNextPalindrome(int *num, int n) {

	int left;
	int right;

	int mid = n / 2;

	if (n % 2 == 0) {
		left = n / 2 - 1;
		right = n / 2;
	} else {
		left = n / 2 - 1;
		right = n / 2 + 1;
	}

	while (num[left--] == num[right++])
		;

	if (left < 0) {
		if (n % 2 == 0) {
			propogate(num, n / 2 - 1, n / 2, carry);
		} else {
			if (num[n / 2] == 9) {
				carry = 1;
				num[n / 2] = 0;

			} else {
				carry = 1;
				num[n / 2]++;
			}

			propogate(num, n / 2 - 1, n / 2 + 1, carry);

		}
	}
}

// A utility function to check if num has all 9s
int AreAll9s(int* num, int n) {
	int i;
	for (i = 0; i < n; ++i)
		if (num[i] != 9)
			return 0;
	return 1;
}

/* Utility that prints out an array on a line */
void printArray(int arr[], int n) {
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// Driver Program to test above function
int main() {
	int num[] = { 9, 4, 1, 8, 7, 9, 7, 8, 3, 2, 2 };

	int n = sizeof(num) / sizeof(num[0]);

	generateNextPalindrome(num, n);

	return 0;
}
