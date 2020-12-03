#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
}* start = NULL;

void display(struct Node *p)
{
    printf("current Linked List---->");
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n\n\n");     
}

int count(struct Node *p)
{
    int count=0;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    return count;
}

void enterData(int x)
{
    struct Node * temp,*p;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    if(start == NULL)
    {
        temp->next = start;
        start = temp;
    }    
    else
    {
        p = start;
        while(p->next!=NULL)
            p = p->next;
        temp->next = p->next;
        p->next = temp; 
    }
}

