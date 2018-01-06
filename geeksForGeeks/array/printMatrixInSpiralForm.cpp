/*
 Print a given matrix in spiral form
 Given a 2D array, print it in spiral form. See the following examples.

 Input:
 1    2   3   4
 5    6   7   8
 9   10  11  12
 13  14  15  16
 Output:
 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10


 Input:


 ***********TH**************
 * 	1   2   3   4  5   6   *
 LV	7   8   9  10  11  12  RV
 *	13  14  15 16  17  18  *
 ***********BH**************


 Output:
 1 2 3 4 5 6 12 18 17 16 15 14 13 7 8 9 10 11
 */

/* Driver program to test above functions */
#include<stdio.h>
#include<iostream>

using namespace std;
#define R 3
#define C 6

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

void spiralPrint(int row, int col, int a[R][C]) {

	// declaring parameters for top-horizontal row
	int THCurrentRow, THColStart, THColEnd;

	THCurrentRow = 0;
	THColStart = 0;
	THColEnd = col - 1;

	// declaring parameters for right-vertical col
	int RVCurrentCol, RVRowStart, RVRowEnd;

	RVCurrentCol = col - 1;
	RVRowStart = 1;
	RVRowEnd = row - 1;

	// declaring parameters for bottom-horizontal row
	int BHCurrentRow, BHColStart, BHColEnd;

	BHCurrentRow = row - 1;
	BHColStart = col - 2;
	BHColEnd = 0;

	// declaring parameters for left-vertical col
	int LVCurrentCol, LVRowStart, LVRowEnd;

	LVCurrentCol = 0;
	LVRowStart = row - 2;
	LVRowEnd = 1;

	int stop = 0;
	int i;

	while (stop == 0) {
		stop = 1;

		if (THCurrentRow <= BHCurrentRow)
			for (i = THColStart; i <= THColEnd; i++) {
				printf("%d ", a[THCurrentRow][i]);
				stop = 0;
			}

		if (RVCurrentCol >= LVCurrentCol)
			for (i = RVRowStart; i <= RVRowEnd; i++) {
				printf("%d ", a[i][RVCurrentCol]);
			}

		if (BHCurrentRow > THCurrentRow) {
			for (i = BHColStart; i >= BHColEnd; i--) {
				printf("%d ", a[BHCurrentRow][i]);
			}
			BHCurrentRow--;
			BHColStart--;
			BHColEnd++;
		}

		if (LVCurrentCol < RVCurrentCol) {
			for (i = LVRowStart; i >= LVRowEnd; i--) {
				printf("%d ", a[i][LVCurrentCol]);
			}
			LVCurrentCol++;
			LVRowStart--;
			LVRowEnd++;
		}

//		trace3(THCurrentRow, THColStart, THColEnd);
//		trace3(RVCurrentCol, RVRowStart, RVRowEnd);
//		trace3(BHCurrentRow, BHColStart, BHColEnd);
//		trace3(LVCurrentCol, LVRowStart, LVRowEnd);

		THCurrentRow++;
		THColStart++;
		THColEnd--;

		RVCurrentCol--;
		RVRowStart++;
		RVRowEnd--;

		printf("--------------\n");

	}

	printf("\n");
}

int main() {
	int a[R][C] = { { 1, 2, 3, 4, 5, 6 }, { 7, 8, 9, 10, 11, 12 }, { 13, 14, 15,
			16, 17, 18 } };

	spiralPrint(R, C, a);
	return 0;
}

/* OUTPUT:
 1 2 3 4 5 6 12 18 17 16 15 14 13 7 8 9 10 11
 */
