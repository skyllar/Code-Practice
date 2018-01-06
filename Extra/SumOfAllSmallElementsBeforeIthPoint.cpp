/*
 * SumOfAllSmallElementsBeforeIthPoint.cpp
 *
 *  Created on: Nov 12, 2014
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

#include<stdlib.h>
#include<stdio.h>

#define MAX 100;

typedef struct valueMinSum {
	int value;
	int minSum;
	int actualIndex;
} valueMinSum;

int cumulative[100];

int applyModifiedMergePartition(valueMinSum **vMSTemp, valueMinSum **vMS,
		int *a, int start, int mid, int end) {

	//	printf(
	//			"\nEntered In applyModifiedMergePartition..........................\n");
	int i1, i2, i3;

	cumulative[0] = vMS[start]->value;

	for (int i = start + 1; i <= mid; i++)
		cumulative[i - start] = vMS[i]->value + cumulative[i - start - 1];

	for (i1 = start, i2 = mid + 1, i3 = 0; i1 <= mid && i2 <= end; i3++) {
		if (vMS[i1]->value < vMS[i2]->value) {
			vMSTemp[i3] = vMS[i1];
			i1++;
		} else {
			vMSTemp[i3] = vMS[i2];
			if (i1 - 1 >= start) {
				//vMSTemp[i3]->minSum += vMS[i1 - 1]->minSum + vMS[i1 - 1]->value;
				vMSTemp[i3]->minSum += cumulative[i1 - 1 - start];
			}
			i2++;
		}
	}

	while (i1 <= mid) {
		vMSTemp[i3] = vMS[i1];
		i1++;
		i3++;
	}
	while (i2 <= end) {
		vMSTemp[i3] = vMS[i2];
		if (i1 - 1 >= start) {
			//vMSTemp[i3]->minSum += vMS[i1 - 1]->minSum + vMS[i1 - 1]->value;
			vMSTemp[i3]->minSum += cumulative[i1 - 1 - start];
		}
		i2++;
		i3++;
	}

	for (int i = start; i <= end; i++) {
		vMS[i] = vMSTemp[i - start];
	}

	//	printf(
	//			"\n*Exited In applyModifiedMergePartition..........................\n");

}

void applyModifiedMerge(valueMinSum **vMSTemp, valueMinSum **vMS, int *a,
		int start, int end) {

	if (start < end) {
		int mid = (start + end) / 2;
		applyModifiedMerge(vMSTemp, vMS, a, start, mid);
		applyModifiedMerge(vMSTemp, vMS, a, mid + 1, end);
		applyModifiedMergePartition(vMSTemp, vMS, a, start, mid, end);
	}
}

void findMinimumSum(int *a, int n) {

	valueMinSum **vMS = (valueMinSum **) malloc(sizeof(valueMinSum *) * n);
	valueMinSum **vMSTemp = (valueMinSum **) malloc(sizeof(valueMinSum *) * n);
	int *minSumArray = new int[n];

	for (int i = 0; i < n; i++) {
		vMS[i] = (valueMinSum *) malloc(sizeof(valueMinSum));
		vMS[i]->value = a[i];
		vMS[i]->minSum = 0;
		vMS[i]->actualIndex = i;
	}
	applyModifiedMerge(vMSTemp, vMS, a, 0, n - 1);

	//printf("\nI am Writing MinSum.............\n");
	for (int i = 0; i < n; i++) {
		//printf("vMS[%d]->actualIndex =%d\n", i, vMS[i]->actualIndex);
		minSumArray[vMS[i]->actualIndex] = vMS[i]->minSum;
	}

	printf("\n-------Printing MinSumValue--------\n");
	for (int i = 0; i < n; i++) {
		printf("For i=%d,minSum = %d\n", i, minSumArray[i]);
	}
	printf("\n");
}

int main(int argc, char * argv[]) {

	//int a[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//int a[9] = { 9, 8, 7, 6, 5, 4, 3, 2, 10 };
	int a[8] = { 3, 8, 7, 6, 5, 1, 2, 4 };


	findMinimumSum(a, (sizeof(a) / sizeof(int)));
	
	//printf("\n###Size=%d\n", sizeof(a) / sizeof(int));
	return 0;
}
