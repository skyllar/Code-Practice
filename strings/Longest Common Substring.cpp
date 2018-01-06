#include<stdio.h>

int dp[1000][1000];

int LCSRec(char *x,char *y,int e1,int e2)
{
	if( m == -1 || n== -1)
		return 0;

	int max=0;

	if( x[m])



}

LCSubStr(char *x,char *y,int m,int n)
{	
	for( int i = 0, i< m ; i++)
	{
		for( int j = 0, j< n ; j++)
		{
			dp[i][j] = -1;
		}
	}

	printf("%d",LCSRec(x,y,m-1,n-1));

	///printf("%d",LCSIteration(x,y,m-1,n-1));

}

/* Driver program to test above function */
int main()
{
    char X[] = "OldSite:GeeksforGeeks.org";
    char Y[] = "NewSite:GeeksQuiz.com";
 
    int m = strlen(X);
    int n = strlen(Y);
 
    cout << "Length of Longest Common Substring is " << LCSubStr(X, Y, m, n);
    return 0;
}