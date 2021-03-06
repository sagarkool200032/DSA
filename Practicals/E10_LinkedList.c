#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
}* start = NULL,* last = NULL;

void display(struct Node *p)
{
    printf("current Linked List---->");
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n\n");     
}

void enterData(int x)
{
    struct Node * temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if(start == NULL)
    {
        start = temp;
        last = temp;
    }
    else
    {
        last->next = temp;
        last = temp;
    }
}

int main()
{
    int option = 1;
    while(option!=0)
    {
        printf("1.Enter Data\n2.Exit \nEnter Option: ");
        scanf("%d",&option);
        if(option==1)
        {
            int n;
            printf("Enter Data: ");
            scanf("%d",&n);
            enterData(n);
            display(start);
        }
        else
            option = 0;    
    }
}