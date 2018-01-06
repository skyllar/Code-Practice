#include<stdio.h>

int result[10000000];

long callMultiply(int *m1, int *m2 , int l1 , int l2)
{ 
	long i ,j,k,currentlowerLimit = 10000000,lowerLimitOfresult = 10000000;
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
		if ( lowerLimitOfresult > k )
			lowerLimitOfresult = k;
	}	

	return ++lowerLimitOfresult;
}

int main()
{
	int n,l1,l2,m1[10000],m2[10000];;
	long lowerLimitOfresult,i;
	char c;
	
	scanf("%d",&n);
	getchar();

	while ( (n--) > 0 )
	{
		l1=0 ; l2 =0;

		while ( (c = getchar()) != ' ') m1[l1++]=c-'0';

		while ( ( c = getchar()) != '\n') m2[l2++]=c-'0';

		i= lowerLimitOfresult =callMultiply(m1,m2, l1, l2);

		while (  i < 10000000 && result[i++] == 0);

		if ( (--i) >= 10000000 )
			printf("0");
		else
		{
			while ( i < 10000000 )
			{
				printf("%d",result[i]);
				result[i++] = 0;
			}
		}

		printf("\n");
	}
	return 0;
}