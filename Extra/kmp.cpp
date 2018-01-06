/*
 * kmp.cpp
 *
 *  Created on: Dec 1, 2014
 *      Author: Apratim
 */
/*
 Searching for Patterns | Set 2 (KMP Algorithm)
 Given a text txt[0..n-1] and a pattern pat[0..m-1], write a function search(char pat[], char txt[]) that prints all occurrences of pat[] in txt[]. You may assume that n > m.

 Examples:
 1) Input:

 txt[] =  "THIS IS A TEST TEXT"
 pat[] = "TEST"
 Output:

 Pattern found at index 10
 2) Input:

 txt[] =  "AABAACAADAABAAABAA"
 pat[] = "AABA"
 Output:

 Pattern found at index 0
 Pattern found at index 9
 Pattern found at index 13
 */

#include <cstdio>
#include <iostream>
#include<string.h>
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

void lpsCompute(int *lps, char *pat, int patternLength) {

	lps[0] = 0;
	int len = 0;
	int i = 1;

	while (i < patternLength) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		} else {
			if (len != 0) {
				len = lps[len - 1];
			} else {
				lps[i] = 0;
				i++;
			}
		}
	}
}

void KMPSearch(char *pat, char *txt) {
	int patternLength = strlen(pat);
	int testLength = strlen(txt);
	int lps[patternLength];
	lpsCompute(lps, pat, patternLength);

	int t = 0;
	int p = 0;
	while (t < testLength) {
		if (txt[t] == pat[p]) {
			p++;
			t++;
			if (p == patternLength) {
				printf("Found At:%d\n", t - p);
				p = lps[p - 1];
			}
		} else {
			if (p != 0) {
				p = lps[p - 1];
			} else {
				t++;
			}
		}

	}

}

// Driver program to test above function
int main() {
	char *txt = "ABABDABACDABABCABAB";
	char *pat = "AB";
	KMPSearch(pat, txt);
	return 0;
}
