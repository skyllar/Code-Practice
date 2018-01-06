/*
Print all possible words from phone digits
Before advent of QWERTY keyboards, texts and numbers were placed on the same key. For example 2 has “ABC” if we wanted to write anything starting with ‘A’ we need to type key 2 once. If we wanted to type ‘B’, press key 2 twice and thrice for typing ‘C’. below is picture of such keypad.

phoneKeyboard

Given a keypad as shown in diagram, and a n digit number, list all words which are possible by pressing these numbers.
For example if input number is 234, possible words which can be formed are (Alphabetical order):
adg adh adi aeg aeh aei afg afh afi bdg bdh bdi beg beh bei bfg bfh bfi cdg cdh cdi ceg ceh cei cfg cfh cfi

Let’s do some calculations first. How many words are possible with seven digits with each digit representing n letters? For first digit we have at most four choices, and for each choice for first letter, we have at most four choices for second digit and so on. So it’s simple maths it will be O(4n). Since keys 0 and 1 don’t have any corresponding alphabet and many characters have 3 characters, 4n would be the upper bound of number of words and not the minimum words.
*/

#include <stdio.h>
#include <string.h>
 
// hashTable[i] stores all characters that correspond to digit i in phone
const char hashTable[10][5] = {"", "", "abc", "def", "ghi", "jkl",
                               "mno", "pqrs", "tuv", "wxyz"};

void printWordsUtil(int *numbers,int current,int lengthNumbers,int resultLast,char *result)
{
	//if( current > lengthNumbers)
	//		return;

	if( current == lengthNumbers)
	{
		printf("\n");
		for ( int i=0; i< resultLast;i++)
		{
			printf("%c",result[i]);
		}
		printf("\n");
	}
	else{
	for(int i = 0; i < (sizeof(hashTable[numbers[current]])/sizeof(char)) -2;i++)
	{
		result[resultLast] = hashTable[numbers[current]][i];
		printWordsUtil(numbers,current+1,lengthNumbers,resultLast+1,result);
	}
}
}

void printWords(int numbers[], int n)
{
    char result[n+1];
    result[n] ='\0';
    printWordsUtil(numbers, 0,n,0,result);
}
 
//Driver program
int main(void)
{
    int number[] = {2, 3, 4};
    int n = sizeof(number)/sizeof(number[0]);
    printWords(number, n);
    return 0;
}
