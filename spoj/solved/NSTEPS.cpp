#include<iostream>
#include<math.h>

using namespace std;

int main(){
	
	long long int testCases;
	long long int x,y;
	long long int c1,c3,number;

	cin>>testCases;

	while( testCases-- > 0)
	{
		cin>>x>>y;
		//cout<<x<<y;

		//check base case
		if( x==0 && y==0)
			cout<<0<<"\n";
		else if( x==1 && y==1)
			cout<<1<<"\n";
		else
		{
			if( x!=y && y!= x-2){
				cout<<"No Number \n";
				continue;
			}
			if( x%2 == 0){
				c1 = x/2 -1;
				c3 = x/2 -1;
			}
			else
			{
				c1 = x/2;
				c3 = x/2 -1;	
			}
			if( x == y){
				number = 4;
			}
			else
				number = 2;
			number += 3*c3 + 1*c1;
			cout<<number<<"\n";
		}

	}

	return 0;
}
