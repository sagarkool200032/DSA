#include <stdio.h>
// ascii
// A-65        a-97             0-48
// B-65        b-98             1-49
// ...         ...
// ...         ...
// ...         ...
// Z-90        z-122            9-57
int main()
{
    char str[] = "GeeksForGeeks";
    // char str[] = "salon!";
    char str1[] = "WELCOME";
    for(int i=0;str[i]!='\0';i++)
    {
        if(!(str[i]>=65 && str[i]<=90) && !(str[i]>=97 && str[i]<=122) && !(str[i]>=48 && str[i]<=57))     
           {
              printf("String is not valid"); 
              return 0;
           }        
    }
    printf("String is Valid");
    return 0;
}