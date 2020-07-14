#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "madam";
    
    int j=strlen(str)-1;
    int i = 0;
    while(i<j)
    {
        if(str[i]!=str[j])
        {
            printf("Not Palindrome");
            return -1;
        }
        i++;
        j--;      
    }
    printf("Palindrome");
    return 0;
}