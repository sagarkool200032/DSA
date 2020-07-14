#include <stdio.h>
#include <stdlib.h>

// using Hash Table
void findDuplicate(char * str)
{
    int i=0;
    char * H = (char *)malloc(26*sizeof(char));
    for(int j =0;j<26;j++)
        H[j]=0;
    while(str[i]!='\0')
    {
        H[str[i++]-97]++;
    }
    for(int j=0;j<26;j++)
    {
        if(H[j]>1)
            printf("%c is appearing %d times in string\n",j+97,H[j]);
    }
}

void findDuplicate1(char * str)
{
    int H=0,x=0;
     for(int i=0;str[i]!='\0';i++){
        x=1;
        x=x<<str[i]-97;
        if((x&H)>0)  
            printf("%c ",str[i]);         
        H=(H|x);
    }
}

int main()
{
   char *str="sagar verma",*str1="finding";
   findDuplicate(str);
   findDuplicate1(str1);
}