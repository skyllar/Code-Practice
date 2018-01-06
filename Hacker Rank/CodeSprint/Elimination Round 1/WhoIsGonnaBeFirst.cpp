/*
 * a.cpp
 *
 *  Created on: Sep 27, 2014
 *      Author: Apratim
 */
/*
 You are given a string s that contains lowercase letters only.

 Its length is N. Find lexicographically smallest Good string for the given string s.

 A Good string is defined as follows:

 Good string contains only lowercase letters.
 Good string does not exist as sub-string in the s.
 Input Format
 Input contains the string s.

 Output Format
 Print in a line, the smallest Good string for the given string s.

 Constraints
 1≤N≤105
 Sample Input

 bb
 Sample Output

 a
 Explanation
 "a" is not a sub-string of "bb", and hence is the smallest Good String.
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

int countCharacters(char * str, int *hash) {

	int i = 0;
	char ch;
	int j = 25;

	while (j > -1)
		hash[j--] = 0;

	while ((ch = str[i]) != '\0') {
		hash[ch - 'a']++;
		i++;
	}

	return i;
}

#define ASIZE 10

int main(int argc, char * argv[]) {

	char inputString[100010];
	int hash[26];
	char a = 'a';
	long long int maxContinuousGlobal = 0;
	long long int maxContinuousInCurrentWindow = 0;

	scanf("%s", inputString);

	//printf("fsfsd :%s\n",inputString);

	int length = countCharacters(inputString, hash);

	for (long long int i = 0; i < length; i++) {
		if (inputString[i] != 'a') {
			if (maxContinuousGlobal < maxContinuousInCurrentWindow)
				maxContinuousGlobal = maxContinuousInCurrentWindow;
			maxContinuousInCurrentWindow = 0;
		} else
			maxContinuousInCurrentWindow++;
	}

	if (maxContinuousGlobal < maxContinuousInCurrentWindow)
		maxContinuousGlobal = maxContinuousInCurrentWindow;

	for (long long int i = 0; i <= maxContinuousGlobal; i++)
		printf("%c", 'a');
	printf("\n");

	return 0;
}
