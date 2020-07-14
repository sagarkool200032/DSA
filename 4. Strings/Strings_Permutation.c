#include <stdio.h>

int main()
{
    char str[] = "Sagar is kool";
    char B[50];
    int index;
    // Method 1
    int i=0;
    while(str[i]!='\0')
        i++;
    i--;
    index = i;
    int j=0;
    while(i>=0)
    {
        B[j++] = str[i--]; 
    }
    B[j]='\0';
    for(int x = 0;B[x]!='\0';x++)
        printf("%c",B[x]);
    printf("\n\n");

    // method 2 swapping
    j=index;  // last char of array (before '\0')
    i = 0;
    while(i<j)
    {
        int temp = str[j];
        str[j] = str[i];
        str[i] = temp;
        i++;
        j--;
    }
    printf("%s",str);
}