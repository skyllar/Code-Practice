/*
SPOJ Problem Set (classical)

7190. Guess the Number

Problem code: GUESSTHE



You are playing the funny game “Guess the number” with a friend. In this game, one of the
players choose a positive integer and the other has to guess it by using the clues that are
revealed. The i-th clue is either “Y” or “N” indicating whether the hidden number is a multiple
of i or not, respectively. For instance, if the clues so far are “YYNYY” it means that the number
is a multiple of 1, 2, 4 and 5, but it is not a multiple of 3. Given the clues of the game so
far, you have to guess the minimum possible number according to them, or call your friend a
cheater if there is no number such that the clues were correctly given.

Input

The input contains several test cases. Each test case is described in a single line that contains
a non-empty string of at most 20 characters. The string is formed entirely of uppercase letters
“Y” and “N”, and represents the clues given so far, in order from left to right. The last line of
the input contains a single asterisk and should not be processed as a test case.

Output

For each test case output a single line with the minimum positive integer that satisfies all the
clues, or −1 if there is no such a number.

Example

Input:
YYNYY
YYYNNN
*

Output:
20
-1
*/
#include<stdio.h>

#include<string.h>

/*long long int gcd(long long int a,long long int b){
	if( b==0)
		return a;
	else
	{
		long long int rem = a % b;
		a = b;
		b = rem;
		return ( gcd(a,b) );
	}
}*/
long long int gcd(long long int a, long long int b)
{
    if (a<b)
        return gcd(b,a);

    if (b==0)
        return a;

    else 
            return gcd (b,a%b);
}
/*long long int gcd(long long int x,long long int y){
    long long int i;
    for(i=x;i>=1;i--){
         if(x%i==0&&y%i==0){
             break;
         }
    }
    return i;
}*/
/*    long long int gcd(long long int x,long long int y)
{
 while(x!=y)
 {
  if(x>y)
  {
   return gcd(x-y,y);
  }
  else
  {
   return gcd(x,y-x);
  }
 }
 return x;
}*/

int main()
{
	//printf("%lld\n",gcd(10,10));
	char number[10000];
	int i,length;
	long long int multiple;
	char c;

	while((c=getchar()) != '*')
	{
		number[0] = c;
		length =1;
		multiple = 1;

		while( (c=getchar()) != '\n')
			number[length++] = c;

		for( i = length -1 ; i>-1 ; i--)
		{

			if( number[i] == 'N')
			{
				//printf("IF\n");
				if(multiple % (i+1) == 0)
				{	multiple = -1;
					break;
				}
			}
			else
			{
				long long int g = gcd(multiple,i+1);
				multiple = (i+1)*(multiple/g);
				//printf("GCD:%lld\n",g);
				//printf("%lld\n",multiple);
				if( multiple <= length +1 && number[multiple-1] == 'N')
				{
					multiple = -1;
					break;	
				}	
			}
		}
		printf("%lld\n",multiple);
	}
	return 1;
}