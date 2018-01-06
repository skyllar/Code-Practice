/*
10239. Between the Mountains

Problem code: ACPC11B



 

Did you try to ride a telepherique (cable car)? It is a lot of fun. Our company is trying tobuild a new telepherique line between two high mountains and you will be invited for a freeride. The trick to get your free ride is to help the company in building the telepherique line.The company wants to build two platforms, one on each mountain. The line will extendbetween these two platforms. The suitable points for holding a platform in each mountainwere determined, and the altitudes of these points were reported.One of the talented engineers suggested that the company can save a lot of energy if the twostations have the same altitude or at least have altitudes which are as close to each other aspossible. Your job is to select two points, one at each mountain, from those suitable points,so that the altitude difference between the two points is as little as possible.InputYour program will be tested on one or more test cases. The first line of the input will be asingle integer T , the number of test cases (1 ≤ T ≤ 100). Follows 2T lines containing thetest cases, each on a pair of lines.Each of the two lines in a case describe the altitudes of suitable points to build a platformon one mountain. Each line starts with an integer N , the number of reported altitudes(1 ≤ N ≤ 1, 000), followed by N integers, which represent the altitudes reported from thismountain. Any altitude value will be between 1 and 1, 000, 000, inclusive.OutputFor each test case, output, on a single line, a single number representing the minimumaltitude difference between two suitable platform points, one at each mountain.
Did you try to ride a telepherique (cable car)? It is a lot of fun. Our company is trying to build a new telepherique line between two high mountains and you will be invited for a free ride. The trick to get your free ride is to help the company in building the telepherique line.

The company wants to build two platforms, one on each mountain. The line will extend between these two platforms. The suitable points for holding a platform in each mountain were determined, and the altitudes of these points were reported.

One of the talented engineers suggested that the company can save a lot of energy if the two stations have the same altitude or at least have altitudes which are as close to each other as possible. Your job is to select two points, one at each mountain, from those suitable points, so that the altitude difference between the two points is as little as possible.

Input

Your program will be tested on one or more test cases. The first line of the input will be a single integer T , the number of test cases (1 ≤ T ≤ 100). Follows 2T lines containing the test cases, each on a pair of lines.

Each of the two lines in a case describe the altitudes of suitable points to build a platform on one mountain. Each line starts with an integer N , the number of reported altitudes (1 ≤ N ≤ 1,000), followed by N integers, which represent the altitudes reported from this mountain. Any altitude value will be between 1 and 1,000,000, inclusive.

Output

For each test case, output, on a single line, a single number representing the minimum

altitude difference between two suitable platform points, one at each mountain.

 

Example

 

Input:
2
8 1 3 5 7 9 7 3 1
8 2 4 6 8 10 8 6 2
8 2 3 5 10 9 3 2 1
7 1 2 6 12 13 3 2

Output:
1
0
*/
#include<stdio.h>
#include<iostream>
//#include<math.h>
//#include<cstdlib>
#include <algorithm> 

long long int labs(long long int a,long long int b)
{
	return ((a>b)?(a-b):(b-a));
}
using namespace std;

void mergePartition(long long int *array ,int low, int mid, int high)
{
	int i = low, j=mid+1;
	int k = 0;
	long int extra[1010];

	while( i<mid+1 && j<high+1 )
	{
		if(array[i] < array[j])
			extra[k++] = array[i++];
		else
			extra[k++] = array[j++];
		//k++;
	} 

	for( ; i<mid +1 ;i++)
		extra[k++] = array[i];
	for( ; j<high+1 ;j++)
		extra[k++] = array[j];

	k=0;
	for(i=low ; i<high+1; i++)
		array[i]=extra[k++];
}

void mergeSort(long long int *array,int low,int high)
{
	int mid;

	if(low < high)
	{
		mid = (low + high)/2;
		mergeSort(array,low,mid);
		mergeSort(array,mid+1,high);
		mergePartition(array,low,mid,high);
	}
}

long long int minimumAltitudeDifference(long long int *array1,long long int *array2,int size1,int size2)
{
	int i=0,j=0,difference;

		mergeSort(array1,0,size1-1);
		mergeSort(array2,0,size2-1);
		//sort(array1,array1+size1);
		//sort(array2,array2+size2);
		/*printf("Sorted array1:\n");
		for(i=0; i<size1; i++)
			cout<<array1[i]<<" ";

		printf("Sorted array2:\n");
		for(i=0; i<size2; i++)
			cout<<array2[i]<<" ";*/

		difference = labs(array1[0]-array2[0]);
		i=0;j=0;
		while( i<size1 && j<size2)
		{
			if ( (labs(array1[i] - array2[j])) < difference )
				difference = labs(array1[i] - array2[j]);
			if(array1[i] > array2[j])
				j++;
			else if ( array1[i] == array2[j])
					break;
				else
					i++;
		}
		return difference;
}

int main()
{
	int i,testCases;
	long long int altitude1[1010];
	long long int altitude2[1010];
	int altitudeCount1,altitudeCount2;

	//cout<<"Enter no of test cases:\n";
	cin>>testCases;

	while((testCases--) > 0)
	{
		cin>>altitudeCount1;
		for ( i = 0 ; i<altitudeCount1 ; i++)
			cin>>altitude1[i];
		cin>>altitudeCount2;
		for ( i = 0 ; i<altitudeCount2 ; i++)
			cin>>altitude2[i];
		cout<<minimumAltitudeDifference(altitude1,altitude2,altitudeCount1,altitudeCount2)<<"\n";
	}
	return 0;
}