/*
SPOJ Problem Set (classical)

10401. Aliens at the train

Problem code: ALIEN



The aliens have arrived to Earth and everything is in harmony, the two races can live together. However, one specific Female Alien does not want to see humans on her way to the university, the alien must use the train as every human does. But she can choose any train station such she doesn’t see more than B humans, however, the Alien wants to go as far as possible with the train. Please, help her in this task

                        INPUT:
You will receive one integer T denoting the number of test cases, then, the next line will contain two integers At Bt where At and Bt is the number of stations in the train (1<=At<=100,000) and the number of people that the alien wants to see as maximum (1<=Bt<=10,000,000), after that, one line containing At integers separated by a single space will denote the number of people the Alien can find in the At-i-th station. (For each station there will be as much 100 people)
                        OUTPUT:
Your output should consist on T pair of numbers denoting the number of people the alien will see and the number of stations she will pass respectively.

SAMPLE:


INPUT:
1
5 100
20 15 30 80 100


OUTPUT
65 3

 

Output note:
The alien takes the train at station 1 (with 20 people) and goes to station 2, then the 3rd station, at this point, she have seen 65 people, if she decides to go to station 4 she will see 145 people… Then she exits the station.

The alien, however, can start at station 2 with 15 people, then continue up to the 4th station, then, she would have seen 125 people, but, as she wants to see the minimum people possible and this number of people exceeds what she wants to see, she decides to choose the way from the 1st to the 3rd station.

Clarification: The alien will be moving always forward (remember, she can choose any station as a start), NEVER backwards, and you should choose the best path that satisfies the output specification.
*/

#include<stdio.h>

int main()
{
	long long int i,lowerBound,upperBound,maxLengthTillHere,maxLengthGlobal,maxSumGlobal,maxSumTillHere,testCases;
	long long int station[100010];
	long long int totalStations;
	long long int maxPeople;

	scanf("%lld",&testCases);
	
	while( testCases-- )
	{
		scanf("%lld %lld",&totalStations,&maxPeople);
		for( i=0; i<totalStations; i++)
			scanf("%lld",&station[i]);
		
		lowerBound = 0;
		upperBound = 0;

		maxLengthTillHere = 0;
		maxSumTillHere = 0;

		maxLengthGlobal = 0;
		maxSumGlobal = 0;

		while( upperBound < totalStations )
		{
			maxSumTillHere += station[upperBound];

			if( maxSumTillHere <= maxPeople )
			{
				if( (++maxLengthTillHere) > maxLengthGlobal )
				{
					maxLengthGlobal = maxLengthTillHere;
					maxSumGlobal = maxSumTillHere;
				}
				else if( maxLengthTillHere == maxLengthGlobal && maxSumGlobal > maxSumTillHere )
						maxSumGlobal = maxSumTillHere;

				upperBound++;
			}
			else
			{
				if( lowerBound == upperBound )
				{
					maxSumTillHere = 0;
					maxLengthTillHere = 0;
					upperBound ++;
				}
				else
				{
					maxSumTillHere = maxSumTillHere - station[lowerBound] -station[upperBound];
					maxLengthTillHere = maxLengthTillHere -1;
				}

				lowerBound ++;
			}
		}	

		printf("%lld %lld\n",maxSumGlobal,maxLengthGlobal);
	}

	return 0; 	
}