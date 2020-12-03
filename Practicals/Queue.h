//  Circular Queue
#include <stdio.h>
#include <stdlib.h>

// Tree Structure
struct Node
{
    struct Node * lchild;
    int data;
    struct Node * rchild;
};

// QueueLL
struct Node1{
    struct Node * Q;
    struct Node1 * next;
}* front = NULL,* rear = NULL;
typedef struct Node1 * Node1;

void enqueue(struct Node * x)
{
    Node1 t;
    t=(Node1)malloc(sizeof(Node1));
    if(t==NULL)
        printf("Queue is FUll\n");
    else
    {
        t->Q=x;
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

struct Node * dequeue()
{
    struct Node * x=NULL;
    Node1 t;
    if(front==NULL)
        printf("Queue is Empty\n");
    else
    {
        x=front->Q;
        t=front;
        front=front->next;
        free(t);
    }
    return x;
}

int isEmpty()
{
    return front==NULL;
}

void display(Node1 p)
{
    if(p==NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("current Queue---->");
    while(p!=NULL)
    {
        printf("%d ",p->Q);
        p = p->next;
    }
    printf("\n\n");     
}