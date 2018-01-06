/*
Searching for Patterns | Set 3 (Rabin-Karp Algorithm)
Given a text txt[0..n-1] and a pattern pat[0..m-1], write a function search(char pat[], char txt[]) that prints all occurrences of pat[] in txt[]. You may assume that n > m.

Examples:
1) Input:

  txt[] =  "THIS IS A TEST TEXT"
  pat[] = "TEST"
*/
/* Driver program to test above function */

#define d 256
#include<string.h>
#include<stdio.h>


void search(char *pattern,char *text,int q)
{
	int M = strlen(pattern);
    int N = strlen(text);
    
    int i, j;
    int t=0;
    int p =0;
	int h=1;

	for(i=0;i<M-1;i++)
		h = (h*d)%q;

	for(int i=0;i<M;i++)
	{
		p = (d*p + pattern[i])%q;
		t = (d*t + text[i])%q;
	}

	for(i=0; i<=N-M;i++)
	{
		if(p==t)
		{
			for( j = 0;j<M; j++)
			{
				if(pattern[j] != text[i+j])
					break;
			}

			if(j == M)
				printf("Pattern Found At: %d",i);

		}
		
		t = (d*(t - text[i]*h) +text[i+M])%q; 

		if( t<0 )
			t += q;
	}

}

int main()
{
    char *txt = "GEEKS FOR GEEKS";
    char *pat = "GEEK";
    int q = 101;  // A prime number
    search(pat, txt, q);
    getchar();
    return 0;
}