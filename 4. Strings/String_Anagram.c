#include <stdio.h>
#include <stdlib.h>

// using Hash Table
void checkAnagram(char * str1,char * str2)
{
    int i=0;
    char * H = (char *)malloc(26*sizeof(char));
    for(int j =0;j<26;j++)
        H[j]=0;
    while(str1[i]!='\0')
        H[str1[i++]-97]++;
    
    i=0;
    while(str2[i]!='\0')
    {
        H[str2[i]-97]--;
        if(H[str2[i]-97]<0)
            {
                printf("Not Anagram");
                break;
            }
        i++;
    }
    if(str2[i]=='\0')
        printf("Strings are Anagram");   
}

int main()
{
   char *str1="observe",*str2="verbose";
   checkAnagram(str1,str2);
}