/*
SPOJ Problem Set (classical)

24. Small factorials

Problem code: FCTRL2



You are asked to calculate factorials of some small positive integers.

Input

An integer t, 1<=t<=100, denoting the number of testcases, followed by t lines, each containing a single integer n, 1<=n<=100.

Output

For each integer n given at input, display a line with the value of n!

Example

Sample input:
4
1
2
5
3
Sample output:

1
2
120
6
*/

/*int factorials[120][1000];

long callMultiply(int *m1, int *m2 , int l1 , int l2,int *result)
{ 
	long i ,j,k = 1000,currentlowerLimit = 10000000,lowerLimitOfresult = 10000000;
	int carry , output;

	for ( i = l2 -1 ; i > -1 ; i--)
	{
		k = --currentlowerLimit;
		carry = 0;

		for ( j = l1 -1 ; j > -1 ; j --,k-- )
		{
			output = m2[i] *m1[j] + carry + result[k];
			result[k] = output %10;
			carry = output/10;
		}
		while ( carry > 0 )
		{
			output = result[k] + carry;
			result[k--] =  output % 10;
			carry = output/10;
		}
	}	

	return k+1;
}

void calculateFact(long long int n);
{
	for( i=lowerLimitOfresult; i< )
}
int main()
{
	long long int testcases,n;

	scanf("%lld",testcases);

	while( testcases-- )
	{
		scafn("%lld",&n);
		calculateFact(n);
	}
	return 0;
}*/

#include<stdio.h>
#define size 200
using namespace std;
int main()
{
 int n,a[size],index,temp,i,t;
 scanf("%d",&t);
 while(t--)
 {
 a[0]=1;
 index=0;
 scanf("%d",&n);
 for(;n>=2;n--)
 {
 temp=0;
 for(i=0;i<=index;i++)
 {
 temp=(a[i]*n)+temp;
 a[i]=temp%10;
 temp=temp/10;
 }
 while(temp>0)
 {
 a[++index]=temp%10;
 temp=temp/10;
 }
 }
 for(i=index;i>=0;i--)
 printf("%d",a[i]);
 printf("\n");
 }
 return 0;
}