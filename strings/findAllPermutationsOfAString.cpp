/*
Write a C program to print all permutations of a given string
A permutation, also called an “arrangement number” or “order,” is a rearrangement of the elements of an ordered list S into a one-to-one correspondence with S itself. A string of length n has n! permutation.
*/



#include<stdio.h>
#include<malloc.h>
#include<vector>
#include<iostream>
using namespace std;

void swap(char *string,int i,int j)
{
	char temp = string[i];
	string[i] = string[j];
	string[j]= temp;
}

void permute(char *string,int start ,int end)
{
	if(start == end)
	{
		// for(int i=0;i<=end;i++)
		// 	printf("%c",string[i]);
		// printf("\n");
		printf("%s\n", string);
	}
	else
	{
		for(int i=start;i<=end;i++)
		{
			swap(string,start,i);
			permute(string,start+1,end);
			swap(string,i,start);
		}
	}
}

int main()
{
   char a[] = "ABC";  
   permute(a, 0, 2);
   //getchar();
   return 0;
}