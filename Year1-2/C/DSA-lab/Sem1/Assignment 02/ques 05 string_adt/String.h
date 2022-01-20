#include<stdlib.h>
#include <stdbool.h>
#include<stdio.h>
#define FALSE 0
#define TRUE !(FALSE)
int size(const char arr[])
{
    int i=0;
    while(arr[i] != '\0')
    {
        i++;
    }
    return (i+1);
}
void concatinate(char lhs[] , char rhs[] )
{

    int i=0,j=0;
    char res[30];
    while(lhs[i] != '\0' )
    {
        res[i]  = lhs[i];
        ++i;
    }

    while(rhs[j] != '\0')
    {
        res[i] = rhs[j];
        ++j;
        ++i;
    }
    res[i] = '\0';
    printf("%s",res);
}

bool string_equal(const char lhs[], const char rhs[])
{
    int s1,s2;
    s1 = size(lhs);
    s2 = size(rhs);
    if(s1==s2)
    {
        int i=0; // Not equal
        while(lhs[i]==rhs[i] || i<=s1)
        {
            i++;
        }
        if(i!=s1){ return 0;}
        else { return 1;}
    }
    else{ return 0;}
}
int to_integer(char lhs[])
{
    int num;
    if(sscanf(lhs,"%d",&num)==EOF){
        fprintf(stderr,"Warning ! Incorrect value for device.");
        return FALSE;
    }
    else { return num;}
}
char append_char(char lhs[],char s)
{
    int i=0;
    while(lhs[i]!='\0') {i++;}
    lhs[i] = s;
    lhs[i+1] = '\0';
}
