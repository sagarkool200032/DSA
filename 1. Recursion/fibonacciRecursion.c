#include <stdio.h>

void Perm(char * str, int k)
{
    static char Result[10];
    static char A[10] = {0};

    if(str[k]=='\0' && Result[k]=='\0')
        printf("%s\n",Result);
    else
    {
        for(int i=0;i<str[i]!='\0';i++)
        {
            if(A[i]==0)
            {
                Result[k] = str[i];
                A[i]++;
                Perm(str,k+1);
                A[i]--;
            }
        }
    }
    
}

int main()
{
    char * str = "ABC";
    Perm(str,0);
}