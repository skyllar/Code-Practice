/*
 * Print all possible words from phone digits.cpp
 *
 *  Created on: Nov 30, 2014
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

const char hashTable[10][5] = { "", "","abc", "def", "ghi", "jkl", "mno", "pqrs",
		"tuv", "wxyz" };

void printWordsUtil(int *number, int current, char *result, int total, int a) {
	if (current == total) {
		result[a] = '\0';
		printf("%s\n", result);
	} else {
		if (number[current] == 1 || number[current] == 0) {
			printWordsUtil(number, current + 1, result, total, a);
		} else {
			for (int i = 0; hashTable[number[current]][i] != '\0'; i++) {
				result[a] = hashTable[number[current]][i];
				printWordsUtil(number, current + 1, result, total, a + 1);
			}
		}
	}
}

void printWords(int number[], int n) {
	char result[n + 1];
	result[n] = '\0';
	printWordsUtil(number, 0, result, n, 0);
}

//Driver program
int main(void) {
	int number[] = { 2, 3, 4 };
	int n = sizeof(number) / sizeof(number[0]);
	printWords(number, n);
	return 0;
}
