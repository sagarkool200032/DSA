#include <stdio.h>
int len(char * st)
{
    int count=0;
    int i=0;
    while(st[i]!='\0')
    {
        count++;
        i++;
    }
    return count;
}
int main()
{
    char str1[100], str2[100];
    printf("Enter 1st String: ");
    gets(str1);
    printf("Enter 2nd String: ");
    gets(str2);

    if(len(str1)==len(str2))
    {
        for(int i=0;i<len(str1);i++)
            if(str1[i]!=str2[i])
            {
                printf("Not Equal\n");

                if(str1[i]>str2[i])
                    printf("String 1 is Bigger");
                else
                    printf("String 2 is Bigger");
                return 0;
            }
            printf("Equal");
            return 0;
    }
    else
    {
        printf("Not Equal\n");
        if(len(str1)>len(str2))
            printf("String 1 is Bigger\n");
        else
            printf("String 2 is Bigger\n");
        return 0;
    }
}