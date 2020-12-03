#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
}* top = NULL;
typedef struct Node * Node;

void display(Node p)
{
    if(p==NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("current Stack---->");
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n\n");     
}

void push(int x)
{
    Node temp;
    temp = (Node)malloc(sizeof(struct Node));
    if(temp==NULL)
        printf("Stack is full\n");
    else
    {
        temp->data=x;
        temp->next=top;
        top=temp;
    }
}

int pop()
{
    Node temp;
    int x=-1;
    if(top==NULL)
        printf("Stack is Empty\n");
    else
    {
        temp=top;
        top=top->next;
        x=temp->data;
        free(temp);
    }
    return x;
}

int main()
{
    int option = 1;
    while(option!=0)
    {
        printf("1.Push\n2.Pop\n3.Exit \nEnter Option: ");
        scanf("%d",&option);
        if(option==1)
        {
            int n;
            printf("Enter Data: ");
            scanf("%d",&n);
            push(n);
            display(top);
        }
        else if(option==2)
        {
            printf("%d is deleted from stack.\n",pop());
            display(top);
        }
        else
            option = 0;    
    }
}