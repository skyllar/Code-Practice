/*
 * medianInStreamOfIntegers.cpp
 *
 *  Created on: Sep 29, 2014
 *      Author: Apratim
 */

/*/
 * Given that integers are read from a data stream. Find median of elements read so for in efficient way. For simplicity assume there are no duplicates. For example, let us consider the stream 5, 15, 1, 3 …

 After reading 1st element of stream - 5 -> median - 5
 After reading 2nd element of stream - 5, 15 -> median - 10
 After reading 3rd element of stream - 5, 15, 1 -> median - 5
 After reading 4th element of stream - 5, 15, 1, 3 -> median - 4, so on...
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

#define DEBUG 0
#define gc getchar
#define ll long long

// Heap capacity
#define MAX_HEAP_SIZE (128)
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

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

inline
void Exch(int &a, int &b) {
	int aux = a;
	a = b;
	b = aux;
}

class Heap{
	public
};

void printMedian(int A[], int size) {
	int m = 0; // effective median
	Heap *left = new MaxHeap();
	Heap *right = new MinHeap();

	for (int i = 0; i < size; i++) {
		m = getMedian(A[i], m, *left, *right);

		cout << m << endl;
	}

	// C++ more flexible, ensure no leaks
	delete left;
	delete right;
}

int main() {
	int A[] = { 5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4 };
	int size = ARRAY_SIZE(A);

	// In lieu of A, we can also use data read from a stream
	printMedian(A, size);

	return 0;
}
