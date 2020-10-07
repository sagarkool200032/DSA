#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * prev,* next;
}* head = NULL,* last = NULL;

void display(struct Node *p)
{
    printf("current Linked List---->");
    do
    {
        printf("%d ",p->data);
        p = p->next;
    }while(p!=head);
    printf("\n");     
}

void enterData(int x)
{
    struct Node * temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = head;
    if(head == NULL)
    {
        temp->prev = NULL;
        head = temp;
        last = temp;
    }
    else
    {
        temp->prev = last;
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
            printf("Enter Data in Linked List: ");
            scanf("%d",&n);
            enterData(n);
            display(head);
        }
        else
            printf("hello");
    }
}