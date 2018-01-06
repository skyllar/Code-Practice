/*
 * Longest Monotonically Increasing Subsequence Size (N log N).cpp
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
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])

/* Function to get index of ceiling of x in arr[low..high]*/
int ceilSearch(int arr[], int low, int high, int x) {
	int mid;

	/* If x is smaller than or equal to the first element,
	 then return the first element */
	if (x <= arr[low])
		return low;

	/* If x is greater than the last element, then return -1 */
	if (x > arr[high])
		return -1;

	/* get the index of middle element of arr[low..high]*/
	mid = (low + high) / 2; /* low + (high - low)/2 */

	/* If x is same as middle element, then return mid */
	if (arr[mid] == x)
		return mid;

	/* If x is greater than arr[mid], then either arr[mid + 1]
	 is ceiling of x or ceiling lies in arr[mid+1...high] */
	else if (arr[mid] < x) {
		if (mid + 1 <= high && x <= arr[mid + 1])
			return mid + 1;
		else
			return ceilSearch(arr, mid + 1, high, x);
	}

	/* If x is smaller than arr[mid], then either arr[mid]
	 is ceiling of x or ceiling lies in arr[mid-1...high] */
	else {
		if (mid - 1 >= low && x > arr[mid - 1])
			return mid;
		else
			return ceilSearch(arr, low, mid - 1, x);
	}
}

int findCeil(int key, int start, int end, int *temp) {
	int mid;

	while (start <= end) {
		if (start == end) {
			return start;
		} else if (start == end - 1) {
			if (key < temp[start])
				return start;
			else
				return end;
		} else {
			mid = (start + end) / 2;
			if (temp[mid] <= key)
				start = mid + 1;
			else
				end = mid;
		}
	}
}

int CeilIndex(int A[], int l, int r, int key) {
	int m;

	while (r - l > 1) {
		m = l + (r - l) / 2;
		(A[m] >= key ? r : l) = m; // ternary expression returns an l-value
	}

	return r;
}

int fitBinary(int value, int *temp, int last) {

	if (value < temp[0]) {
		temp[0] = value;
		return last + 1;
	} else if (value >= temp[last]) {
		temp[last + 1] = value;
		return last + 2;
	} else {
		int index;
		//index = findCeil(value, 0, last, temp);
		//index = ceilSearch(temp, 0, last, value);
		index = CeilIndex(temp, -1, last, value);
		temp[index] = value;
		return last + 1;
	}

}

int LongestIncreasingSubsequenceLength(int *a, int n) {
	int temp[100];
	int tempLen = 1;
	temp[0] = a[0];

	for (int i = 1; i < n; i++) {
		tempLen = fitBinary(a[i], temp, tempLen - 1);
	}

	return tempLen;

}
int main() {
	int A[] = { 2, 5, 3, 7, 11, 8, 10, 13, 6 };
	int n = ARRAY_SIZE(A);

	printf("Length of Longest Increasing Subsequence is %d\n",
			LongestIncreasingSubsequenceLength(A, n));

	return 0;
}
