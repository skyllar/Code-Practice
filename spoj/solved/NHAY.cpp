/*

SPOJ Problem Set (classical)

32. A Needle in the Haystack

Problem code: NHAY



Write a program that finds all occurences of a given pattern in a given input string. This is often referred to as finding a needle in a haystack.

The program has to detect all occurences of the needle in the haystack. It should take the needle and the haystack as input, and output the positions of each occurence, as shown below. The suggested implementation is the KMP algorithm, but this is not a requirement. However, a naive approach will probably exceed the time limit, whereas other algorithms are more complicated... The choice is yours.

Input

The input consists of a number of test cases. Each test case is composed of three lines, containing:

the length of the needle,
the needle itself,
the haystack.
The length of the needle is only limited by the memory available to your program, so do not make any assumptions - instead, read the length and allocate memory as needed. The haystack is not limited in size, which implies that your program should not read the whole haystack at once. The KMP algorithm is stream-based, i.e. it processes the haystack character by character, so this is not a problem.

The test cases come one after another, each occupying three lines, with no additional space or line breaks in between.

Output

For each test case your program should output all positions of the needle's occurences within the haystack. If a match is found, the output should contain the position of the first character of the match. Characters in the haystack are numbered starting with zero.

For a given test case, the positions output should be sorted in ascending order, and each of these should be printed in a separate line. For two different test cases, the positions should be separated by an empty line.

Example

Sample input:

2
na
banananobano
6
foobar
foo
9
foobarfoo
barfoobarfoobarfoobarfoobarfoo
Sample output:

2
4

3
9
15
21
Note the double empty line in the output, which means that no match was fo
*/


#include <iostream>
#include <cstdio>
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

#include<malloc.h>


void matchPattern( int patternLength,char *pattern,int *lps )
{

	int j=0;
	int i = 0;
	char c;
	int flag = 0;

	getchar();

	while( (c = getchar()) >= 'a' && c <= 'z')
	{
		//printf("###--%c\n",c);
		if(c == pattern[j])
		{
			j++;
			i++;
		

			if( j == patternLength )
			{
				//cout<<i - j<<"\n";
				printf("%d\n",i-j);
				j = lps[j-1];
				flag = 1;
			}
		}
		else
		{
			while(j>0 && c != pattern[j])
			{
				j = lps[j-1];

				if(c == pattern[j])
				{
					j++;
					i++;
		
					if( j == patternLength )
					{
						//cout<<i - j<<"\n";
						printf("%d\n",i-j);
						j = lps[j-1];
						flag = 1;
					}
				}
			}

			if( j == 0 )
				i++;
		}

	}

	if( flag == 0 )
		printf("\n");
	//cout<<"$$$$$$";
}

void computeLPS(int patternLength,char *pattern,int *lps )
{
	int current=1,length=0;
	lps[0] = 0;

	while( current < patternLength)
	{
		if(pattern[length] == pattern[current])
		{
			length++;
			lps[current] = length;
			current++;
		}

		else
		{
			if(length == 0)
			{
				lps[current] = 0;
				current++;
			}
			else
			{
				length = lps[length-1];
			}
		}

	}
}


void applyKMP(int patternLength,char *pattern)
{
	int *lps = (int *)malloc(sizeof(int)*(patternLength+1));
	computeLPS(patternLength,pattern,lps);

	//for( int i = 0 ; i  <patternLength; i++)
	//	cout<<lps[i]<<" ";
	matchPattern(patternLength,pattern,lps);

}

int main()
{
	int patternLength;
	 while(scanf("%d\n",&patternLength)!=EOF)
	 {
		//cin>>patternLength;

		char *pattern = (char *)malloc(sizeof(char)*(patternLength+1));

		cin>>pattern;
		//cout<<"\n--"<<pattern<<"\n";
		applyKMP(patternLength,pattern);

	}
	return 0;
}