#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int data;
    struct Stack *next;
}*top=NULL;

void push(struct Stack *st,int val)
{
    struct Stack *t;
    t=(struct Stack *)malloc(sizeof(struct Stack));
    if(t==NULL)
        printf("Stack is overflow");
    else
    {
        t->data=val;
        t->next=top;
        top=t;
    }
}

int pop(struct Stack *st)
{
    int x=-1;
    struct Stack *p;
    if(top==NULL)
        printf("Stack in underflow");
    else
    {
        p=top;
        x=p->data;
        top=top->next;
        free(p);
    }
    return x;
}

int IsEmpty(struct Stack st)
{
    if(top==NULL)
        return 1;
    else
        return 0;
}

void enqueue(struct Stack *s2,int val)
{
    push(s2,val);
}

int dequeue(struct Stack *st1,struct Stack *st2)
{
    int x=-1;
    if(IsEmpty(*st2))
    {
        if(IsEmpty(*st1))
        {
            printf("Queue is empty");
            return x;
        }
        else
        {
            while(!IsEmpty(*st1))
            {
                push(st2,pop(st1));
            }
        }
    }
    return pop(st2);
}
void display(struct Stack *p)
{
    while(p!=NULL)
    {
        printf("%d " , p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    struct Stack *st1,*st2;
    enqueue(st1,3);
    enqueue(st1,5);
    enqueue(st1,6);

    dequeue(st1,st2);

    display(top);

    return 0;
}