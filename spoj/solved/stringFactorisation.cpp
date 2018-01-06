#include<stdio.h>
#include <string.h>
#include<iostream>

using namespace std;

int countStringFactors(int *,char*,int,int);

int computerPowerOfPattern(int *dp,char *s,int start,int end,int length)
{
	int i;
	int indexToCompare=start;
	int patternLength = end - start +1;
	int maxCount=0;
	int count =1;
	int rem = (length - start)%patternLength;

	for( i=(end+1) ;i< length -rem; i++)
	{
		if(s[i]==s[indexToCompare])
		{
			indexToCompare = start + (indexToCompare-start+1)%patternLength;
			if(indexToCompare == start)
			{
				count++;
				if(count %2 == 0)
				{
					if(dp[i+1] == -1)
						dp[i+1] = countStringFactors(dp,s,i+1,length);
					
					if((dp[i+1] > 0 || (i+1) == length) && maxCount < dp[i+1]+count)
						maxCount = dp[i+1]+count;
				}
			}
		}
		else
			break;
	}
	return maxCount;
}

int countStringFactors(int *dp ,char *s,int start,int length)
{
	int i;
	int count =0;
	int maxCount = 0; 

	for(i=start; i< (start + (length-start)/2); i++ )
	{
		count = computerPowerOfPattern(dp,s,start,i,length);		
		if(maxCount < count)
			maxCount = count;
	}
	return maxCount;
}

int main()
{ 
	char s[100010];
	int testCases;
	int length;
	int dp[100010];
	int i;

	scanf("%d",&testCases);
	while((testCases--)>0)
	{
		scanf("%s",s);
		length = strlen(s);
		for(i=0;i<length;i++)
			dp[i] = -1;
		dp[length] = 0;
		//printf("%s---length:%d\n",s,strlen(s));
		printf("%d\n",countStringFactors(dp,s,0,length));
	}
	return 0;
}