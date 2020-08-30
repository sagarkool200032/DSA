// Stack using Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*top=NULL;

void push(int x)
{
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));
    if(t==NULL)
        printf("stack is full\n");
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }
}

int pop()
{
    struct Node *t;
    int x=-1;
    if(top==NULL)
        printf("Stack is Empty\n");
    else
    {
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;
}

// Time Complexity: O(n)
int peek(int index)
{
    struct Node *p=top;
    for(int i=0;i<index-1 && p!=NULL;i++)
        p=p->next;
    if(p)
        return p->data;
    else
        return -1;
}

// Time Complexity: O(n)
void Display()
{
    struct Node *p;
    p=top;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int main()
{
    push(10);
    push(20);
    push(30);

    Display();

    printf("%d is deleted\n",pop());
    printf("%d\n",peek(2));

    return 0;
}
