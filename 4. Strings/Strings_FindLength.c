#include <stdio.h>

int main()
{
    char str[] = "GeeksForGeeks";
    int length=0, i=0;
    while(str[i++]!='\0'){length++;}
    printf("LENGTH: %d",length);
    return 0;
}