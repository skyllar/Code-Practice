/*
Dynamic Programming | Set 33 (Find if a string is interleaved of two other strings)
Given three strings A, B and C. Write a function that checks whether C is an interleaving of A and B. C is said to be interleaving A and B, if it contains all characters of A and B and order of all characters in individual strings is preserved.

We have discussed a simple solution of this problem here. The simple solution doesn’t work if strings A and B have some common characters. For example A = “XXY”, string B = “XXZ” and string C = “XXZXXXY”. To handle all cases, two possibilities need to be considered.
*/
#include <iostream>
#include <string.h>
using namespace std;

bool isInterleaved(char *A, char *B, char *C)
{
	
	int M = strlen(A), N = strlen(B);
 	int m = M,n=N;
    // Let us create a 2D table to store solutions of
    // subproblems.  C[i][j] will be true if C[0..i+j-1]
    // is an interleaving of A[0..i-1] and B[0..j-1].
    bool dp[M+1][N+1];
    memset(dp,0,sizeof(dp));
    if ((M+N) != strlen(C))
       return false;
    for ( int i=0; i<=m ; i++)
    {
    	for ( int j=0; j<=n ; j++)
    	{
    		if( i==0 && j== 0)
    			dp[i][j] = true;
    		else if( i==0 )
    		{
    			if( C[j-1] == B[j-1])
    				dp[i][j] = dp[i][j-1];
    		}
    		else if( j==0 )
    		{
    			if( C[i-1] == A[i-1])
    				dp[i][j] = dp[i-1][j];
    		}
    		else
    		{
    			if (A[i-1]==C[i+j-1] && B[j-1]==C[i+j-1])
                	dp[i][j]=(dp[i-1][j] || dp[i][j-1]) ;
    			else if(C[i + j-1] == A[i-1])
    			{
    				dp[i][j] = dp[i-1][j];
    			}
    			else if(C[i + j-1] == B[j-1])
    			{
    				dp[i][j] = dp[i][j-1];
    			}
    		
    		}
    	}
    }


    // for( int i=0; i<=m ; i++)
    // {
    // 	for (int j=0; j<=n; j++)
    // 	{
    // 		cout<<dp[i][j]<<" ";
    // 	}
    // 	cout<<endl;
    // }

    return dp[M][N];
}


// A function to run test cases
void test(char *A, char *B, char *C)
{
    if (isInterleaved(A, B, C))
        cout << C <<" is interleaved of " << A <<" and " << B << endl;
    else
        cout << C <<" is not interleaved of " << A <<" and " << B << endl;
}
 
 
// Driver program to test above functions
int main()
{
    test("XXY", "XXZ", "XXZXXXY");
    test("XY" ,"WZ" ,"WZXY");
    test ("XY", "X", "XXY");
    test ("YX", "X", "XXY");
    test ("XXY", "XXZ", "XXXXZY");
    return 0;
}