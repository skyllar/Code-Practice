/*
SPOJ Problem Set (classical)

15980. Ascending Fibonacci Numbers

Problem code: ASCDFIB



John is trying to learn the Fibonacci sequence. This is what he has learned so far. The first two terms of the sequence are f(1) = 0 and f(2) = 1.  The next term f(n) is then calculated by adding the previous two terms f(n-1) and f(n-2). Therefore,

f(1) = 0

f(2) = 1

f(3) = f(2) + f(1) = 1 + 0 = 1

f(4) = f(3) + f(2) = 1 + 1 = 2

f(5) = f(4) + f(3) = 2 + 1 = 3

f(6) = f(5) + f(4) = 3 + 2 = 5

After calculating this for a while, John realized that the values are becoming too big. In order to keep the values small, John changed his algorithm. Instead of calculating f(n) = f(n-1)+f(n-2), he decided he will calculate f(n) = ( f(n-1)+f(n-2) ) % 10^5.

Now John wants to do some research on his new modified Fibonacci sequence. He will give you an integer A (A<=10^5) and an integer B (B<=10^6). You have to output all the terms from f(A) to f(A+B) in ascending order (non-decreasing order). But printing so many numbers is too much of a hassle. So, if there are more than 100 terms in the output, then only print the first 100.

Input

The first line contains an integer T (T<=100), which is the number of test cases. 
Each test case contains two positive integers A and B as mentioned before.

Output

For each test case, print case number (Check sample output) and then print the terms from f(A)  to f(A+B) in ascending order (non-decreasing order). If there are more than 100 terms in the output, then only print the first 100.

Example

Input:
3
1 3
3 3
100 1

Output:

Case 1: 0 1 1 2
Case 2: 1 2 3 5
Case 3: 15075 69026


*/
/*
int **base;
int fibonacci[1000000]={0,1,1};
int **temp;
long int extra[1000000],count;*/
/*
void multiplySame()
{
	int t[2][2];

		t[0][0]=temp[0][0];
		t[0][1]=temp[0][1];
		t[1][0]=temp[1][0];
		t[1][1]=temp[1][1];

		temp[0][0] = t[0][0]*t[0][0] + t[0][1]*t[1][0];
		temp[0][1] = t[0][0]*t[0][1] + t[0][1]*t[1][1];
		temp[1][0] = t[1][0]*t[0][0] + t[1][1]*t[1][0];
		temp[1][1] = t[1][0]*t[0][1] + t[1][1]*t[1][1];
}

void multiplyBase(int **temp , int**temp2)
{
	int t[2][2];

		t[0][0]=temp[0][0];
		t[0][1]=temp[0][1];
		t[1][0]=temp[1][0];
		t[1][1]=temp[1][1];
	temp[0][0] = t[0][0]*temp2[0][0] + t[0][1]*temp2[1][0];
	temp[0][1] = t[0][0]*temp2[0][1] + t[0][1]*temp2[1][1];
	temp[1][0] = t[1][0]*temp2[0][0] + t[1][1]*temp2[1][0];
	temp[1][1] = t[1][0]*temp2[0][1] + t[1][1]*temp2[1][1];	
}

void calculateFib(int n)
{
	if(fibonacci[n] > 0)
	{
		fibonacci[n+1] = fibonacci[n]+fibonacci[n-1];
		temp[0][0]=fibonacci[n+1];
		temp[0][1]=fibonacci[n];
		temp[1][0]=fibonacci[n];
		temp[1][1]=fibonacci[n-1];
		return;
	}
	
	calculateFib(n/2);

	///multiply(temp,temp);
	multiplySame();

	if(n%2 == 1)
		multiplyBase(temp,base);

	fibonacci[n] = temp[0][1];
}
*/


#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
int f[1100010];
int i;
int extra[1100010],count;

void fib(int start,int n)
{
  /* Declare an array to store fibonacci numbers. */ 
  /* 0th and 1st number of the series are 0 and 1*/
 
  for (i = start + 1; i <= n; i++)
  {
      /* Add the previous 2 numbers in the series
         and store it */
      f[i] = (f[i-1] + f[i-2])%100000;
  }

 }

int main()
{
	int A,B,i;
	int testCases;
	int lastCalculated = 2;
	f[1] = 0;
	f[2] = 1;

	/*temp = (int **)(malloc(2*sizeof(int *)));

	for( i=0 ; i<2 ;i++ )
		temp[i]=(int *)(malloc(2*sizeof(int)));

	base = (int **)(malloc(2*sizeof(int *)));

	for( i=0 ; i<2 ;i++ )
		base[i]=(int *)(malloc(2*sizeof(int)));

	base[0][0]=1;
	base[0][1]=1;
	base[1][0]=1;
	base[1][1]=0;
*/
	int j = 1;
	scanf("%d",&testCases);

	while((testCases--)>0)
	{
		scanf("%d %d",&A,&B);

		if(lastCalculated < A)
		{
			fib(lastCalculated,A);	
			lastCalculated = A;
		}
		
		if(lastCalculated < A+B)
		{
			fib(lastCalculated,A+B);
			lastCalculated = A+B;
		}

		for( i = A ; i<= (A+B) ; i++ )
			extra[i] = f[i];

		if( B+1 > 110)
			std::partial_sort (extra+A, extra+A+100, extra+A+B+1);
		else
			std::sort(extra+A,extra+A+B+1);

		printf("Case %d: ",j);
		j++;
		for( i=A,count=0 ; i<(A+B) && count<99 ;i++,count++ )
			printf("%d ",extra[i]);
		printf("%d",extra[i]);
		printf("\n");

		//printf("fib[%d]:%d,fib[%d]:%d\n",A,f[A],A+B,f[A+B]);
	}	
	return 0;
}