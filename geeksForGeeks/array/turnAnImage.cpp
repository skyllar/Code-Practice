/*
 * turnAnImage.cpp
 *
 *  Created on: Sep 24, 2014
 *      Author: Apratim
 */

#include <stdio.h>
#include <stdlib.h>

void displayMatrix(int const *p, int row, int col);
void rotate(int *pS, int *pD, int row, int col);

int main() {
	// declarations
	int image[][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };
	int *pSource;
	int *pDestination;
	int m, n;

	// setting initial values and memory allocation
	m = 3, n = 4, pSource = (int *) image;
	pDestination = (int *) malloc(sizeof(int) * m * n);

	// process each buffer
	displayMatrix(pSource, m, n);

	rotate(pSource, pDestination, m, n);

	displayMatrix(pDestination, n, m);

	free(pDestination);

	getchar();
	return 0;
}

void displayMatrix(int const *p, int r, int c) {
	int row, col;
	printf("\n\n");

	for (row = 0; row < r; row++) {
		for (col = 0; col < c; col++) {
			printf("%d\t", *(p + row * c + col));
		}
		printf("\n");
	}

	printf("\n\n");
}

void rotate(int *pS, int *pD, int row, int col) {
	int r, c;
	for (r = 0; r < row; r++) {
		for (c = 0; c < col; c++) {
			 *(pD + c * row + (row - r - 1)) = *(pS + r * col + c);
		}
	}
}
