/*
 * NQueenProblem.cpp
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

#define N 8
#define N 8

bool isSafe(int board[N][N], int row, int col) {
	int i, j;

	/* Check this row on left side */
	for (i = 0; i < col; i++) {
		if (board[row][i])
			return false;
	}

	/* Check upper diagonal on left side */
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
		if (board[i][j])
			return false;
	}

	/* Check lower diagonal on left side */
	for (i = row, j = col; j >= 0 && i < N; i++, j--) {
		if (board[i][j])
			return false;
	}

	return true;
}

bool solveNQUtil(int board[N][N], int col) {

	if (col == N)
		return true;

	for (int row = 0; row < 8; row++) {
		if (isSafe(board, row, col)) {
			board[row][col] = 1;
			if (solveNQUtil(board, col + 1))
				return true;
			else
				board[row][col] = 0;
		}
	}
	return false;
}
void printSolution(int board[N][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf(" %d ", board[i][j]);
		printf("\n");
	}
}
bool solveNQ() {
	int board[N][N] = { { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0,
			0, 0 } };

	if (solveNQUtil(board, 0) == false) {
		printf("Solution does not exist");
		return false;
	}

	printSolution(board);
	return true;
}

// driver program to test above function
int main() {
	solveNQ();

	getchar();
	return 0;
}
