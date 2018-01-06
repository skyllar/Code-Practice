/*
 * Minimum number of jumps to reach end.cpp
 *
 *  Created on: Nov 14, 2014
 *      Author: Apratim
 */

/*
 Minimum number of jumps to reach end
 Given an array of integers where each element represents the max number of steps that can be made forward from that element. Write a function to return the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then cannot move through that element.

 Example:

 Input: arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
 Output: 3 (1-> 3 -> 8 ->9)
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
#include<string.h>

int minJumps(int *arr, int size) {
	int *minJumps = new int[size];

	//memset(minJumps, 1000, size);

	for (int i = 1; i < size; i++)
		minJumps[i] = 10000;

	minJumps[0] = 0;

	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j <= arr[i] + i && j < size; j++) {
			if (minJumps[j] > minJumps[i] + 1)
				minJumps[j] = minJumps[i] + 1;
		}
	}

	for (int i = 0; i < size; i++) {
		printf("a[%d] = %d\n", i, minJumps[i]);
	}

	return minJumps[size - 1];
}

// Driver program to test above function
int main() {
	int arr[] = { 1, 3, 6, 1, 0, 9 };
	int size = sizeof(arr) / sizeof(int);
	printf("Minimum number of jumps to reach end is %d ", minJumps(arr, size));
	return 0;
}
