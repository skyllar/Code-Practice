/*
 * RearrangeArrayInAlternatingPositiveNegative.cpp
 *
 *  Created on: Nov 6, 2014
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

// A utility function to print an array 'arr[]' of size 'n'
void printArray(int arr[], int n) {
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int swap(int *a, int i, int j) {
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
int rearrange(int *a, int size) {
	int i = 0, j = 1, k;

	while (i < size && j < size) {
		if (a[i] < 0)
			i += 2;
		if (a[j] > 0)
			j += 2;

		if (i < size && a[i] > 0) {
			while (j < size && a[j] > 0) {
				j += 2;
			}

			if (j < size) {
				swap(a, i, j);
				i += 2;
				j += 2;
			} else {
				k = i;
				while (i < size) {
					if (a[i] < 0) {
						swap(a, i, k);
						k = k + 2;
					}
					i += 2;
				}
			}
		}
		if (j < size && a[j] < 0) {
			while (i < size && a[i] < 0) {
				i += 2;
			}
			if (i < size) {
				swap(a, i, j);
				i += 2;
				j += 2;
			} else {
				k = j;
				while (j < size) {
					if (a[j] > 0) {
						swap(a, j, k);
						k = k + 2;
					}
					j += 2;
				}
			}
		}

	}
}

// Driver program to test abive function
int main() {
	//int arr[n] = {-5, 3, 4, 5, -6, -2, 8, 9, -1, -4};
	//int arr[] = {-5, -3, -4, -5, -6, 2 , 8, 9, 1 , 4};
	//int arr[] = {5, 3, 4, 2, 1, -2 , -8, -9, -1 , -4};
	//int arr[] = {-5, 3, -4, -7, -1, -2 , -8, -9, 1 , -4};
	int arr[] = { -5, -2, 5, 2, 4, 7, 1, 8, 0, -8 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Given array is \n";
	printArray(arr, n);

	rearrange(arr, n);

	cout << "Rearranged array is \n";
	printArray(arr, n);

	return 0;
}
