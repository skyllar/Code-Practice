#include<stdio.h>
#include<limits.h>
#include <deque>
using namespace std;
#include<iostream>

void printKMax(int *arr, int n, int k) {

	int i;
	deque<int> dQ(k);

	for(i=0; i<k; i++)
	{
		while(!dQ.empty() && arr[i] >= arr[dQ.back()])
			dQ.pop_back();

		dQ.push_back(i);
	}

	for( ; i<n; i++)
	{
		printf("%d ",arr[dQ.front()]);

		while(!dQ.empty() && dQ.front() <= i-k)
			dQ.pop_front();

		while(!dQ.empty() && arr[i] >= arr[dQ.back()])
					dQ.pop_back();

		dQ.push_back(i);
	}

	cout << arr[dQ.front()];
}

// Driver program to test above functions
int main() {
	int arr[] = { 12, 1, 78, 90, 57, 89, 56 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 3;
	printKMax(arr, n, k);
	return 0;
}
