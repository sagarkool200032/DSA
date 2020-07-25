#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first=NULL;

void Display(struct Node *p)
{
    while(p!=NULL)
    {
    printf("%d ",p->data);
        p=p->next;
    }
}

int Count(struct Node *p)
{
    int count=0;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    return count;
}

int Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;

    if(index < 0 || index > Count(p))
        return -1;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;

    if(index == 0)
    {
        t->next=first;
        first=t;
    }
    else
    {
        for(i=0;i<index-1;i++)
            p=p->next;
        t->next=p->next;
        p->next=t;
    }
    return 0;
}

int lastInsert(struct Node *p, int x) 
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if(first==NULL)
        first = t;  
    else
    {
        while(p->next!=NULL)
            p = p->next;       //p is pointing to the last node
        p->next = t;
    }
    return 0;   
}

int main()
{

    Insert(first,0,15);
    Insert(first,1,8);
    Insert(first,2,9);
    Insert(first,3,10);
    Insert(first,0,23);
    lastInsert(first,100);
    lastInsert(first,150);
    
    Display(first);
    return 0;
}