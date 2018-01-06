/*
 * Candies.cpp
 *
 *  Created on: Oct 5, 2014
 *      Author: Apratim
 */

/*
 Children Candies
 There is children standing in a line. Initially the -th child has candies. Some of the children have more candies than others.
 You have to make sure that every student has the same number of candies.
 In one operation you can tell one of the chirdren to give a single candy to the left neighbour, or to the right one. How many
 operations do you need to make sure every student has same number of candies? Print the minimal possible number of
 operations.
 Input Format
 The first line contains a single integer . The next line contains space separated integers .
 Constraints
 It's guaranteed that .
 Output Format
 Print a single integer the minimal number of operations.
 Sample Input
 3
 1 2 3
 Sample Output
 2
 Explanation
 Let's denote , an operation of giving candy from -th child to -th one. You need two operations: , .
 Timelimits
 Timelimits are listed here
 n i ai
 n n a , ,…, 1 a2 an
 1 ≤ n ≤ 3 ⋅ 10
 5
 0 ≤ ai ≤ 10
 6
 ∑ai ≡ 0 (mod n)
 −
 x → y x y 3 → 2 2 → 1
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

int main(int argc, char * argv[]) {

	long int n, i, j, k;
	long int candies[500000];
	long long int totalCandies = 0, candiesPerPerson, currentTotalCandies = 0,
			currentCandiesPerPerson, currentScarceCandies;
	long long int minMoves = 0, extraCandies;
	long long int currentExtraCandiesForRight, currentExtraCandiesForLeft;
	long long int lastPersonWithLessCandies = -1;
	scanf("%ld", &n);

	for (i = 0; i < n; i++) {
		scanf("%ld", &candies[i]);
		totalCandies += candies[i];
	}

	candiesPerPerson = totalCandies / n;

	for (i = 0; i < n; i++) {

		currentTotalCandies += candies[i];
		currentCandiesPerPerson = currentTotalCandies / (i + 1);

		if (currentCandiesPerPerson >= candiesPerPerson) {
			currentExtraCandiesForRight = currentTotalCandies
					- candiesPerPerson * (i + 1);
			candies[i] -= currentExtraCandiesForRight;

			//trace1(currentExtraCandiesForRight);

			if (i != n - 1) {
				currentTotalCandies -= currentExtraCandiesForRight;
				candies[i + 1] += currentExtraCandiesForRight;
				minMoves += currentExtraCandiesForRight;
			}
			if (lastPersonWithLessCandies != -1) {
				for (j = i; j >= lastPersonWithLessCandies; j--) {
					currentExtraCandiesForLeft = candies[j] - candiesPerPerson;
					candies[j] = candiesPerPerson;
					if (j != 0)
						candies[j - 1] += currentExtraCandiesForLeft;
					minMoves += currentExtraCandiesForLeft;

					//trace3(j,currentExtraCandiesForLeft,minMoves);
				}

				lastPersonWithLessCandies = -1;
			}
		} else {
			if (lastPersonWithLessCandies == -1)
				lastPersonWithLessCandies = i;
		}

	}

	printf("%lld\n", minMoves);

	return 0;
}
