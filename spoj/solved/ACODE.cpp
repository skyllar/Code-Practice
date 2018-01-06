/*
SPOJ Problem Set (classical)

394. Alphacode

Problem code: ACODE



Alice and Bob need to send secret messages to each other and are discussing ways to encode their messages:

Alice: “Let’s just use a very simple code: We’ll assign ‘A’ the code word 1, ‘B’ will be 2, and so on down to ‘Z’ being assigned 26.”

Bob: “That’s a stupid code, Alice. Suppose I send you the word ‘BEAN’ encoded as 25114. You could decode that in many different ways!”
Alice: “Sure you could, but what words would you get? Other than ‘BEAN’, you’d get ‘BEAAD’, ‘YAAD’, ‘YAN’, ‘YKD’ and ‘BEKD’. I think you would be able to figure out the correct decoding. And why would you send me the word ‘BEAN’ anyway?”
Bob: “OK, maybe that’s a bad example, but I bet you that if you got a string of length 5000 there would be tons of different decodings and with that many you would find at least two different ones that would make sense.”
Alice: “How many different decodings?”
Bob: “Jillions!”

For some reason, Alice is still unconvinced by Bob’s argument, so she requires a program that will determine how many decodings there can be for a given string using her code.

Input

Input will consist of multiple input sets. Each set will consist of a single line of at most 5000 digits representing a valid encryption (for example, no line will begin with a 0). There will be no spaces between the digits. An input line of ‘0’ will terminate the input and should not be processed.

Output

For each input set, output the number of possible decodings for the input string. All answers will be within the range of a 64 bit signed integer.

Example

Input:

25114
1111111111
3333333333
0

Output:

6
89
1
*/

#include<stdio.h>
#include <string.h>

long long int dp[5001];

long long int callRecur(char *sequence, int currentIndex, int length){

	if ( dp[currentIndex] != -1 )
		return dp[currentIndex];

	if( currentIndex == length)
		return 1;

	if( sequence[currentIndex] == '0')
	{
		dp[currentIndex]=0;
		return 0;

	}
	
	if( currentIndex == length -1)
	{
		dp[currentIndex]=1;
		return 1;
	}

	if( sequence[currentIndex] == '1')
	{
		dp[currentIndex] =callRecur(sequence,currentIndex+1,length) +callRecur(sequence,currentIndex+2,length);
	}
	else
	{
		if(  sequence[currentIndex] == '2' )
		{
			if(sequence[currentIndex+1] <= '6')
				dp[currentIndex] =callRecur(sequence,currentIndex+1,length)+callRecur(sequence,currentIndex+2,length);
			else
				dp[currentIndex] =callRecur(sequence,currentIndex+1,length);		
		}
		else
		{
			dp[currentIndex] =callRecur(sequence,currentIndex+1,length);	
		}
	}
	//printf("fUNCTION caLLED:(%d,%d)-->Return:%lld\n",currentIndex,length,dp[currentIndex]);
	return dp[currentIndex];
}

int main()
{
	char comb[5000];
	char c;
	int length,i;
	for( i=0; i<5001; i++)
		dp[i]=-1;

	while( true )
	{
		length= 0;
			
		while( (c = getchar())>= '0' && c <= '9')
			comb[length++] = c; 
		if (comb[0] == '0')
			break;

		/*for( i=0;i <length; i++)
				printf("%c ",comb[i]);
		printf("\n");
		*/

		printf("%lld\n",callRecur(comb,0,length));
		for ( i=0; i<=length; i++)
			dp[i]=-1;
	}
}