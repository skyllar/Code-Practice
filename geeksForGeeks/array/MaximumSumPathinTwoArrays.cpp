/*
 * MaximumSumPathinTwoArrays.cpp
 *
 *  Created on: Nov 6, 2014
 *      Author: Apratim
 */
/*
Maximum Sum Path in Two Arrays
Given two sorted arrays such the arrays may have some common elements. Find the sum of the maximum sum path to reach from beginning of any array to end of any of the two arrays. We can switch from one array to another array only at common elements.

Expected time complexity is O(m+n) where m is the number of elements in ar1[] and n is the number of elements in ar2[].
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
int max(int x, int y) {
	return (x > y) ? x : y;
}

int maxPathSum(int *ar1, int *ar2, int size1, int size2) {

	int i = 0;
	int j = 0;
	int sum1 = 0, sum2 = 0, result = 0;
	while (i < size1 && j < size2) {
		if (ar1[i] < ar2[j])
			sum1 += ar1[i++];
		else if (ar1[i] > ar2[j])
			sum2 += ar2[j++];
		else {
			i++;
			j++;
			result += max(sum1, sum2);
			sum1 = 0;
			sum2 = 0;

//			while (i < size1 && j < size2 && ar1[i] == ar2[j]) {
//				result = result + ar1[i++];
//				j++;
//			}
		}
	}

	while (i < size1)
		sum1 += ar1[i++];
	while (j < size2)
		sum2 += ar2[j++];

	result += max(sum1, sum2);
	//cout<<result<<"---";
	return result;
}

// Driver program to test above function
int main() {
	int ar1[] = { 2, 3, 7, 10, 12, 15, 30, 34 };
	int ar2[] = { 1, 5, 7, 8, 10, 15, 16, 19 };
	int m = sizeof(ar1) / sizeof(ar1[0]);
	int n = sizeof(ar2) / sizeof(ar2[0]);
	cout << maxPathSum(ar1, ar2, m, n);
	return 0;
}
