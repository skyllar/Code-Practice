#include <stdio.h>
#include <stdlib.h>
#include <cstring>

void printRec(char *str1,char *str2,int l1,int l2,int start1,int start2,char *temp,int offset)
{	
	if(l1 + l2 < offset)
	{
		return;
	}

	if(l1 + l2 == offset)
	{
		for(int i=0; i<offset; i++)
		{
			printf("%c",temp[i]);
		}
		printf("\n");
	}

	else
	{
		//for(int i=start1; i<l1; i++)
		//{
			if(start1 < l1)
			{ 
				temp[offset] = str1[start1];
				printRec(str1,str2,l1,l2,start1+1,start2,temp,offset+1);
			}			
		//}
		//for(int i=start2; i<l2; i++)
		//{
			if(start2 < l2)
			{
				temp[offset] = str2[start2];
				printRec(str1,str2,l1,l2,start1,start2+1,temp,offset+1);
			}
		//}
	}
}


void printIls(char *str1,char *str2,int l1,int l2)
{
	char *temp = (char*)malloc(sizeof(char)*(l1+l2+1));
	printRec(str1,str2,l1,l2,0,0,temp,0);
}

// Driver program to test above functions
int main()
{
    char *str1 = "AB";
    char *str2 = "CD";
    printIls (str1, str2, strlen(str1), strlen(str2));
    return 0;
}