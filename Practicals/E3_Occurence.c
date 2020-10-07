#include <stdio.h>

int findOccurence(char *str, char ch)
{
    int i=0,count=0;
    while(str[i]!='\0')
    {
        if(str[i++]==ch)
            count++;
    }
    return count;
}

int main()
{
    char str[100],ch;
    printf("Enter String: ");
    gets(str);
    printf("Enter Character: ");
    scanf("%c",&ch);
    printf("%c is occuring %d times in the string",ch,findOccurence(str,ch));
}