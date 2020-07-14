#include <stdio.h>

int CountWords(char * string)
{
    int words = 0;
    for(int i=0;string[i]!='\0';i++)
    {
        if(string[i]==' ' && string[i-1]!=' ')
            words++;
    }
    return words+1;
}

int CountVowelsConsonants(char * string)
{
    int vcount=0,ccount=0;
    for(int i=0;string[i]!='\0';i++)
    {
        if(string[i]=='a' || string[i]=='e' || string[i]=='i' || string[i]=='o' || string[i]=='u'||
           string[i]=='A' || string[i]=='E' || string[i]=='I' || string[i]=='O' || string[i]=='U')
            vcount++;

        else if((string[i]>=65 && string[i] <=90) || (string[i]>=97 && string[i]<=122))
            ccount++;
    }
    printf("Vowels: %d\n",vcount);
    printf("Consonants: %d\n",ccount);       
}

int main()
{
    char * A = "Geeks For Geeks";
    char * B = "SAGAR VERMA";
    printf("Words: %d\n",CountWords(A));
    CountVowelsConsonants(B);
    return 0;
}