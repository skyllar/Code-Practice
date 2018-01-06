/*
 * c.cpp
 6 2
 10 10 100 0 0 0
 0 0 50 0 0 0
 *
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

#define ASIZE 10

int row = 0;
int col = 0;
ll int ** array123 = NULL;

int compar(const void * a, const void * b) {

	int i = 0;
	ll int ** aa = ( ll int **) a;
	ll int ** bb = ( ll int **) b;

	for (i = 0; i < col; i++) {

		if ((*aa)[i] != (*bb)[i])
			break;
	}

	if (i == col) {
		return 0;
	}

	return (*aa)[i] > (*bb)[i];

}

ll int *rangeAssigned;
ll int globalMinima = LLONG_MAX;

void checkThisPossibleSubset(ll int **array123, ll int *rangeAssigned) {

	for (int i = 0; i < row; i++) {
		printf(":: %lld ", rangeAssigned[i]);
	}
	printf("\n");

	int localMinima = 0;

	ll int low = 0;
	ll int high = 0;
	ll int temp;
	for (ll int i = 0; i < row; i++) {

		if (rangeAssigned[i] == 0)
			continue;
		temp = high;
		high += (rangeAssigned[i] - 1LL);

		//printf(
		//	"Current ROW->%lld,low = %lld,high = %lld,RangeAssigned[i]=%lld\n",
		//i, low, high, rangeAssigned[i]);

		if (low == 0) {
			localMinima += array123[i][high];
			///printf("Current Sum=%lld\n", array123[i][high]);
		} else {
			localMinima += (array123[i][high] - array123[i][low - 1]);
			//printf("Current Sum=%lld\n",
			//array123[i][high] - array123[i][low - 1]
			//);
		}
		low = high + 1;
		high++;
	}
	if (localMinima < globalMinima)
		globalMinima = localMinima;

}

void findAllPossibleSubsets(ll int **array123, ll int row, ll int col,
ll int rangeLeft,
ll int rowsCovered) {

	ll int rangeCovered;

	if (rowsCovered == row) {

		if (rangeLeft == 0LL) {
			checkThisPossibleSubset(array123, rangeAssigned);
		}

		return;
	}

//if (rangeLeft == 0LL)
//return;

	for (rangeCovered = 0; rangeCovered <= col; rangeCovered++) {

		rangeAssigned[rowsCovered] = rangeCovered;
		findAllPossibleSubsets(array123, row, col, rangeLeft - rangeCovered,
				rowsCovered + 1LL);
	}

}

int main(int argc, char * argv[]) {

	ll int n, k;
	sll(n);
	sll(k);
	row = k;
	col = n;

	array123 = (ll int **) malloc(sizeof( ll int *) * 30);

	for (int i = 0; i < 30; i++) {
		array123[i] = ( ll int *) malloc(sizeof(ll int) * 30);
	}

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			sll(array123[i][j]);
		}
	}

	rangeAssigned = (ll int *) malloc(sizeof(ll int) * (row + 1));

	for (ll int i = 0; i < row; i++) {
		for (ll int j = 1; j < col; j++) {
			array123[i][j] = array123[i][j - 1] + array123[i][j];
		}
	}

	findAllPossibleSubsets(array123, row, col, col, 0);
	printf("%lld\n", globalMinima);

	return 0;
}
