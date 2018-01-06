#include<stdio.h>

void recurPrint(char *temp,int s,int e,int specialCharacterIndex)
{
    if ( s < 0 || s > e )
        return;

    int mid;
    int flag = 0;
    int actualLength = e - s + 1;

    if( specialCharacterIndex >=s  && specialCharacterIndex <= e)
    {
        actualLength --;
        flag = 1;
    }
    if( actualLength %2 != 0 || actualLength < 4)
    {
        for( int i=s; i <= e; i++)
        {
            printf("%c",temp[i]);
        }
        printf("\n");
    }
    else
    {
        mid = (s + e)/2;

        if( flag == 1)
        {
            if( specialCharacterIndex > mid)
                mid--;
            else
                mid ++;
        }

        recurPrint(temp, s,mid,specialCharacterIndex);
        recurPrint(temp, mid+1, e, specialCharacterIndex);
    }
}

int main()
{
    char *str= "I cant't do this";
    int l= 0;
    while( str[l] != '\0')
        l++;
    printf("%d",l);

    char temp[1000];
    int tLen = 0;
    int specialCharacterIndex = -1;

    for( int i = 0; i < l; i++)
    {
        if( str[i] == ' ' || str[i] == ',') {
            recurPrint(temp,0,tLen-1,specialCharacterIndex);
            tLen = 0;
            specialCharacterIndex = -1;
            while (str[i] == ' ' || str[i] == ',')
                i++;
            i--;
        }
        else
        {
            if( str[i] == '\'')
                specialCharacterIndex = i;
            temp[tLen++] = str[i];
        }
        recurPrint(temp,0,tLen-1,specialCharacterIndex);
    }

    recurPrint(temp,0,tLen-1,specialCharacterIndex);
    return 0;
}