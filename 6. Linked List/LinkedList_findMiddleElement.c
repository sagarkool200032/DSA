// Display a Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[],int n)
{
    int i;
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

// Time Complexity: O(n)
void Display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

int FindMiddle(struct Node *p)
{
    struct Node *q;
    p=q=first;
    while(q!=NULL)
    {
        q=q->next;
        if(q)q=q->next;
        if(q)p=p->next;
    }
    return p->data;
}

int main()
{

    int A[]={3,5,7,10,25,8,32,2,23};
    create(A,9);
    Display(first);
    printf("\n");
    printf("Middle Element in Linked List: %d",FindMiddle(first));
    return 0;
}