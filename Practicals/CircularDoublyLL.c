#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * prev,* next;
}* head = NULL;

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

void Rdisplay(struct Node *p)
{
    printf("Reverse Linked List---->");
    do
    {
        printf("%d ",p->data);
        p = p->prev;
    }while(p!=head->prev);
    printf("\n");     
}

void enterData(struct Node *p,int x)
{
    struct Node * temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    if(head == NULL)
    {
        temp->next = temp->prev = temp;
        head = temp;
    }
    else
    {
       struct Node * last = head->prev; // last node
       temp->next = head;
       head->prev = temp;
       temp->prev = last;
       last->next = temp;  
    }
}

int main()
{
    int option = 1;
    while(option!=0)
    {
        printf("1.Enter Data\n2.Reverse Display\n3.Exit \nEnter Option: ");
        scanf("%d",&option);
        if(option==1)
        {
            int n;
            printf("Enter Data in Linked List: ");
            scanf("%d",&n);
            enterData(head,n);
            display(head);
        }
        if(option==2)
            Rdisplay(head->prev);
        else
            option=0;
    }
}