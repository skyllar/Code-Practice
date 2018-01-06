/*
 * LargestSubarrayWithEqualNumberOf0sAnd1s.cpp
 *
 *  Created on: Oct 1, 2014
 *      Author: Apratim
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

void findSubArray(int *arr, int size) {

	int sumLeft[size];

	int max = arr[0];
	int min = arr[0];
	sumLeft[0] = (arr[0] == 0 ? -1 : 1);

	for (int i = 1; i < size; i++) {
		sumLeft[i] = sumLeft[i - 1] + (arr[i] == 0 ? -1 : 1);
		if (max < sumLeft[i])
			max = sumLeft[i];
		if (min > sumLeft[i])
			min = sumLeft[i];
	}

	int hash[max - min + 1];

	for (int i = 0; i < max - min + 1; i++) {
		hash[i] = -1;
	}

	max = -1;
	int lowIndex = -1;
	int highIndex = -1;
	for (int i = 0; i < size; i++) {

		if (sumLeft[i] == 0) {
			max = i + 1;
			lowIndex = 0;
			highIndex = i;
		}

		if (hash[sumLeft[i] - min] != -1) {
			if (max < i - hash[sumLeft[i] - min]) {
				max = i - hash[sumLeft[i] - min];
				lowIndex = hash[sumLeft[i] - min] + 1;
				highIndex = i;
			}
		} else
			hash[sumLeft[i] - min] = i;
	}

	trace3(max, lowIndex, highIndex);

}
/* Driver program to test above functions */
int main() {
	int arr[] = { 1, 0, 0, 1, 0, 1, 1 };
	int size = sizeof(arr) / sizeof(arr[0]);

	findSubArray(arr, size);
	return 0;
}
