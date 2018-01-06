/*
 * Find the largest multiple of 3.cpp
 *
 *  Created on: Nov 18, 2014
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

#include<deque>

#include<algorithm>

class MyComp {
public:
	bool operator()(int a, int b) {
		return a > b;
	}
};

struct MyCompStruct {
	bool operator()(int a, int b) {
		return a > b;
	}
};

int fixCase1(deque<int>& q1, deque<int>& q2, int& sum) {

	int flag = 0;
	int x;

	if (q1.size() == 0) {
		if (q2.size() < 2) {
			q2.clear();
			return 1;
		} else {
			x = q2.front();
			sum = sum - x;
			q2.pop_front();
			x = q2.front();
			sum = sum - x;
			q2.pop_front();
			return 0;
		}
	} else {
		x = q1.front();
		sum = sum - x;
		q1.pop_front();
		return 0;
	}
}
int fixCase2(deque<int>& q1, deque<int>& q2, int& sum) {

	int flag = 0;
	int x;

	if (q2.size() == 0) {
		if (q1.size() < 2) {
			q1.clear();
			return 1;
		} else {
			x = q1.front();
			sum = sum - x;
			q1.pop_front();
			x = q1.front();
			sum = sum - x;
			q1.pop_front();
			return 0;
		}
	} else {
		x = q2.front();
		sum = sum - x;
		q2.pop_front();
		return 0;
	}
}

int printElements(deque<int>& q0, deque<int>& q1, deque<int>& q2) {

	int a[100];
	int i = 0;

	while (!q0.empty()) {
		int x = q0.front();
		q0.pop_front();
		a[i++] = x;
	}
	while (!q1.empty()) {
		int x = q1.front();
		q1.pop_front();
		a[i++] = x;
	}
	while (!q2.empty()) {
		int x = q2.front();
		q2.pop_front();
		a[i++] = x;
	}

	sort(a, a + i, MyCompStruct());
	for (int j = 0; j < i; j++)
		printf("%d", a[j]);

	printf("\n");
}
int findMaxMultupleOf3(int *a, int size) {

	sort(a, a + size);

	deque<int> q0;
	deque<int> q1;
	deque<int> q2;

	int sum = 0;

	for (int i = 0; i < size; i++) {
		int rem = a[i] % 3;
		sum += a[i];

		switch (rem) {
		case 0:
			q0.push_back(a[i]);
			break;
		case 1:
			q1.push_back(a[i]);
			break;
		case 2:
			q2.push_back(a[i]);
			break;
		}
	}
	int stop = 0;
	while (stop == 0) {

		int rem = sum % 3;
		switch (rem) {
		case 0:
			stop = 1;
			break;
		case 1:
			stop = fixCase1(q1, q2, sum);
			break;
		case 2:
			stop = fixCase2(q1, q2, sum);
			break;

		}
	}

	printElements(q0, q1, q2);
}

// Driver program to test above functions
int main() {
	int arr[] = { 8, 1, 7, 6, 0 };
	int size = sizeof(arr) / sizeof(arr[0]);

	if (findMaxMultupleOf3(arr, size) == 0)
		printf("Not Possible");

	return 0;
}
