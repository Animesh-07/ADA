#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <limits.h>

void ShiftTable(int *table,char *pattern,int m)
{
    int i=0;
    for(i=0;i<m-1;i++)
        table[pattern[i]]=m-i-1;
}

int horspool(char *text,char *pattern,int *table,int *noOfOcc)
{
    int n=strlen(text);
    int m=strlen(pattern);
    int i=m-1;
    int count=0,k=0;
    while(i<n)
    {
        k=0;
        while(k<=m-1 && (pattern[m-1-k]==text[i-k]))
            k=k+1;
        if(k==m)
        {
            noOfOcc[count++]=i-m+1;
            i=i+table[text[i]];
        }
        else
            i=i+table[text[i]];
    }
    return count;
}

int main()
{
    int table[500];
    char pattern[20];
    char text[50];
    int i=0;
    printf("Enter the text :\t");
    gets(text);
    printf("Enter the pattern:\t");
    gets(pattern);
    int m=strlen(pattern);
    for(i=' ';i<='z';i++)
        table[i]=m;
    ShiftTable(table,pattern,m);
    int noOfOcc[10];
    int count=0;
    if((count=horspool(text,pattern,table,noOfOcc))==0)
        printf("No Match Found");
    else
        for(i=0;i<count;i++)
            printf("Match found at %d\n",noOfOcc[i]+1);
    return 0;
}


