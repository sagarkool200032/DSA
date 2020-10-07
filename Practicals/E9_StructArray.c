#include <stdio.h>
#include <string.h>
#define MAX 10

struct Student
{
    char name[100];
    int age;
    int rollNo;
    char branch[20];
    char dob[20];
};

int main()
{
    struct Student s[MAX];
    for(int i=0;i<MAX;i++)   // for input
    {
        printf("Enter Name: ");
        scanf(" ");
        gets(s[i].name);

        printf("Enter age: ");
        scanf("%d",&s[i].age);

        printf("Enter Roll No. : ");
        scanf("%d",&s[i].rollNo);

        printf("Enter Branch: ");
        scanf(" ");
        gets(s[i].branch);

        printf("Enter DOB: ");
        scanf(" ");
        gets(s[i].dob);

        printf("\n");
    }
    printf("\n\n");

    for(int i=0;i<MAX;i++)  // to display
    {
        int res = strcmp(s[i].branch,"cse");
        if(res==0)
        {
            printf("%d. student name: %s\n",i+1,s[i].name);
            printf("%d. student Age: %d\n",i+1,s[i].age);
            printf("%d. student Roll No. : %d\n",i+1,s[i].rollNo);
            printf("%d. student Branch. : %s\n",i+1,s[i].branch);
            printf("%d. student DOB : %s\n\n",i+1,s[i].dob);
        }  
    }
    return 0;
}