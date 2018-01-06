/*
 * Try.cpp
 *
 *  Created on: Sep 23, 2014
 *      Author: Apratim
 */
/*
 10/2/2014 Valid Integrals : Challenge | NPL-Round2 | HackerRank
 https://www.hackerrank.com/contests/npl-round-2/challenges/valid-integrals 1/1
 All Contests NPL-Round2 Valid Integrals
 Domains ?
 Contests ?
 Leaderboard
 ?
 Submissions ?
 ? ?
 1 arpitbhayani
 ? ?
 You are given two points in the Cartesian coordinate system P1(x1, y1) and P2(x2, y2). A
 point is said to be valid if its coordinates are integers. Given points, P1 and P2 are valid
 points. Find the no of valid points on the line segment joining P1 and P2 excluding P1 and
 P2. For example P1 = (0, 0) and P2 = (5, 5) the number of valid points are 4 (1, 1), (2, 2),
 (3, 3) and (4, 4).
 Input:
 First Line Contains T: no of test cases.
 Next T lines contains 4 values x1, y1, x2, and y2 on each line.
 Output:
 Output the number of valid points corresponding to each test input, on a separate line.
 Constraints:
 T <= 10^5
 -10^9 <= x1, y1, x2, y2 <= 10^9
 Sample Test Case:
 2
 0 0 5 5
 0 2 0 3
 Sample Output:
 4
 0
 Valid Integrals
 */
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>

int main() {
	long long int t;
	scanf("%lld", &t);
	long long int x1, x2, y1, y2, lx, ux, ly, uy, count, m;
	long long int x, y;
	long long denoM, numM;
	long long int yU, yL, xU, xL, dx, dy;

	while (t--) {
		scanf("%lld", &x1);
		scanf("%lld", &y1);
		scanf("%lld", &x2);
		scanf("%lld", &y2);

		if (x1 > x2) {
			lx = x2;
			ux = x1;
		} else {
			lx = x1;
			ux = x2;
		}

		if (y1 > y2) {
			ly = y2;
			uy = y1;
		} else {
			ly = y1;
			uy = y2;
		}

		count = 0;
		dx = x2 - x1;
		dy = y2 - y1;

		if (x1 == x2) {
			printf("%lld\n", uy - ly - 1);
			continue;
		}

		if (y1 == y2) {
			printf("%lld\n", ux - lx - 1);
			continue;
		}
		if (dy == dx) {
			printf("%lld\n", ux - lx - 1);
			continue;
		}

		if (ux - lx < uy - ly) {
			for (x = lx + 1; x < ux; x++) {
				yU = (x - x1) * dy;
				yL = dx;
				y = (long long) (yU / yL + y1);
				if (yU % yL == 0 && y < uy && y > ly)
					count++;
			}
		} else {
			for (y = ly + 1; y < uy; y++) {
				xU = (y - y1) * dx;
				xL = dy;
				x = (long long) (xU / xL + x1);
				if (xU % xL == 0 && x < ux && x > lx)
					count++;
			}
		}
		printf("%lld\n", count);
	}

	return 0;
}
