#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
}* front = NULL,* rear = NULL;
typedef struct Node * Node;

void display(Node p)
{
    if(p==NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("current Queue---->");
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n\n");     
}

void enqueue(int x)
{
    Node t;
    t=(Node)malloc(sizeof(struct Node));
    if(t==NULL)
        printf("Queue is FUll\n");
    else
    {
        t->data=x;
        t->next=NULL;
        if(front==NULL)
            front=rear=t;
        else
        {
            rear->next=t;
            rear=t;
        }
    }
}

int dequeue()
{
    int x=-1;
    Node t;
    if(front==NULL)
        printf("Queue is Empty\n");
    else
    {
        x=front->data;
        t=front;
        front=front->next;
        free(t);
    }
    return x;
}

int main()
{
    int option = 1;
    while(option!=0)
    {
        printf("1.Enqueue\n2.Dequeue\n3.Exit \nEnter Option: ");
        scanf("%d",&option);
        if(option==1)
        {
            int n;
            printf("Enter Data: ");
            scanf("%d",&n);
            enqueue(n);
            display(front);
        }
        else if(option==2)
        {
            printf("%d is deleted from queue.\n",dequeue());
            display(front);
        }
        else
            option = 0;    
    }
}