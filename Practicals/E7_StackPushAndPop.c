#include <stdio.h>

int top = -1; // Global Variable

void Display(int * st)
{
    for(int i=top;i>=0;i--)
        printf("%d ",st[i]);
    printf("\n");
}

void push(int * st, int x)
{
    if(top==100-1)
        printf("Stack overflow\n");
    else
        st[++top]=x;
}

int pop(int *st)
{
    int x=-1;
    if(top==-1)
        printf("Stack Underflow\n");
    else
        x=st[top--];
    return x;
}

int main()
{
    int stack[100];
    int option;
    while(option!=0)
    {
        int n;
        printf("1.Push \n2.Pop \n3.Exit \nEnter Option: ");
        scanf("%d",&option);
            if(option==1)
            {
                printf("Enter Element you want to push: ");
                scanf("%d",&n);
                push(stack,n);
                printf("Current Stack ----> ");Display(stack);
            }       
            else if(option==2)
            {
                printf("%d Deleted from stack: ",pop(stack));
                printf("Current Stack ----> ");Display(stack);
            }
            else
                option=0;
    }   
    return 0;
}   