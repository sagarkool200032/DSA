#include <stdio.h>
// ascii
// A-65        a-97
// B-65        b-98
// ...         ...
// ...         ...
// ...         ...
// Z-90        z-122
int main()
{
    char str[] = "GeeksForGeeks";
    char str1[] = "WELCOME";
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]>=65 && str[i]<=90)    //Capital to lower alphabets
            str[i]+=32;
        else if(str[i]>=97 && str[i]<=122) //lower to capital alphabets
            str[i]-=32;
    }
    printf("New String: %s",str);
    return 0;
}