/*
 * Palindromize.cpp
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
#include<string>
#include<algorithm>

int countPalindromize(string s) {

	int count = 0;

	int len = s.length();
	char pal[len + 1];

	int aux[26] = { 0 };

	//sort(s, s + len);

	for (int i = 0; i < len; i++)
		aux[s[i] - 'a']++;

	for (int i = 0; i < len; i++) {
		printf("%c: %d\n", i + 'a', aux[i]);
	}

	int start = 0;
	int end = len - 1;

	int i = 25;

	while (i > -1) {
		if (aux[i] >= 2) {
			aux[i]--;
			aux[i]--;
			pal[start++] = i + 'a';
			pal[end--] = i + 'a';
		} else
			i--;

		//printf("-------\n");
	}

	i = 25;
	while (i > -1) {
		if (aux[i] % 2 == 1) {
			aux[i]--;
			pal[start++] = i + 'a';
		}
		i--;
	}

	pal[len] = '\0';

	//cout << s << "\n";
	cout << pal << "\n";

	return count;

}

int main(int argc, char * argv[]) {

	char s[100];

	cin >> s;
	cout << s << "\n";
	int length = 0;
	while (s[length++] != '\0')
		;
	cout << next_permutation(s, s + length-1) << "\n";
	cout << s << "\n";
	//cout << countPalindromize(s);
	return 0;
}
