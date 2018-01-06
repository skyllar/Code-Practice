/*
 * Phoenix vs Edgeworth.cpp
 *
 *  Created on: Nov 15, 2014
 *      Author: Apratim
 */

/*
 Phoenix and Edgeworth are playing a game. They have a grid of cells with R rows and C columns. The rows are numbered 1 to R from top to bottom. The columns are numbered 1 to C from left to right. On each cell, there is at most 1 coin. Phoenix and Edgeworth take turns alternately and Phoenix goes first.

 In his turn, the player must choose a row, say r. Then, he must choose a cell in row r, which must have a coin, with heads facing up. Let us say he chose the coin at cell (r,c). The player must flip this coin - so that it is now tails facing up. Now, the player can flip as many coins as he likes (including none at all), that lie strictly to the left of the coin he just flipped. That is, he may flip a coin at cell (r,c') for any c' < c. Note that he may flip a coin from tails to heads as well, but the rightmost coin he flipped - at (r,c) - must be flipped from heads to tails. Note that a player cannot cause any change at a cell that has no coins.

 The game ends when a player encounters the situation where there are no coins in the grid with heads facing up. The player who makes the last move wins.

 We can see that the game will always terminate; since the rightmost coin being flipped must always turn from heads to tails. In fact, if both Phoenix and Edgeworth play optimally, the starting position is sufficient to determine who will win. Given the initial state of the grid, determine who will win.
 Input

 The first line of input contains the number T, the number of test cases. Then follows the description of each test case. The first line of each test case contains two integers R and C, respectively, separated by a single space. Then follows R lines with C characters in each line. Each character may be either one of - 'H': means there is a coin in this cell with heads facing up, 'T': means there is a coin in this cell with tails facing up or '_' (underscore character): means this cell is empty and there is no coin in this cell. There are no empty lines between test cases.
 Output

 Output a single line for each test case. Output "Phoenix wins" - without the quotes and note that the 'P' is in upper case - if Phoenix can force a victory for the given initial grid. Otherwise, output "Edgeworth wins" - without the quotes and note that the 'E' is in upper case.
 Constraints

 1 ≤ T ≤ 100
 1 ≤ R ≤ 100
 1 ≤ C ≤ 100
 Each character is from the set { 'H', 'T', '_' }

 Sample Input

 3
 1 7
 H_T_H_H
 2 2
 HT
 HH
 2 3
 _HT
 H_T

 Sample Output

 Phoenix wins
 Phoenix wins
 Edgeworth wins


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

char pos[101][101];
bool callRecur(int, int, int);

bool createRandom(int row, int currentStart, int end, int originalStart, int r,
		int c, int turn) {

	//printf("Current Start:%d...End=%d\n", currentStart, end);
	//printf("-----I am Here-----\n");
	if (currentStart >= end + 1) {
		//printf("$$$$$$$$$$$$$$$$$$$$$\n");

		//		for (int i = originalStart; i <= end; i++)
		//			printf("%c", pos[row][i]);
		//		printf("\n");
		return ((callRecur((turn + 1) % 2, r, c) == true) ? false : true);
	}

	if (pos[row][currentStart] == '_') {
		return createRandom(row, currentStart + 1, end, originalStart, r, c,
				turn);
	} else {
		if (createRandom(row, currentStart + 1, end, originalStart, r, c, turn)
				== true) {
			return true;
		}
		pos[row][currentStart] = (pos[row][currentStart] == 'H') ? 'T' : 'H';
		if (createRandom(row, currentStart + 1, end, originalStart, r, c, turn)
				== true) {
			pos[row][currentStart] = (pos[row][currentStart] == 'H') ? 'T'
					: 'H';
			return true;
		}
		pos[row][currentStart] = (pos[row][currentStart] == 'H') ? 'T' : 'H';
		return false;
	}
}

bool callRecur(int turn, int r, int c) {

	int i, j, k;

	int flag = 0;

	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			if (pos[i][j] == 'H') {
				flag = 1;
				break;
			}
		}
	}

	if (flag == 0)
		return false;

	for (i = 0; i < r; i++) {
		for (j = c - 1; j >= 0; j--) {
			if (pos[i][j] == 'H') {
				pos[i][j] = 'T';
				if (createRandom(i, 0, j - 1, 0, r, c, turn) == true) {
					pos[i][j] = 'H';
					return true;
				}

				pos[i][j] = 'H';
				//printf(
				//	"*********************************************************************************************\n");
			}
		}
	}

	return false;
}

void whoWins(int r, int c) {

	int i, j;

	//printf("WhoWins\n");

	//	for (i = 0; i < r; i++) {
	//		printf("%s\n", pos[i]);
	//	}

	//	for (i = 0; i < r; i++) {
	//		for (j = 0; j < c; j++) {
	//			printf("%c", pos[i][j]);
	//		}
	//		printf("\n");
	//	}

	///printf("c = %d\n", c);
	if (callRecur(0, r, c) == true)
		cout << "Phoenix wins\n";
	else
		cout << "Edgeworth wins";
}

int main(int argc, char * argv[]) {

	int testCases;
	int r, c, i;

	scanf("%d", &testCases);

	while (testCases--) {
		scanf("%d", &r);
		scanf("%d", &c);

		for (i = 0; i < r; i++)
			scanf("%s", pos[i]);

		whoWins(r, c);

	}
	return 0;
}
