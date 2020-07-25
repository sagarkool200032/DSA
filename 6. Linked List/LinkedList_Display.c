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

// RECURSION
// Total Calls: O(n+1)
// Time Complexity: O(n)
// Space Complexity: O(n+1) = O(n)
void RDisplay(struct Node *p)
{
    if(p!=NULL)
    {
        // printf("%d ",p->data);   // normal display
        RDisplay(p->next);
        printf("%d ",p->data);   // reverse display
    }
}

int main()
{
    // struct Node *temp;
    int A[]={3,5,7,10,25,8,32,2};
    create(A,8);

    Display(first);
    printf("\n\n");
    RDisplay(first);
    return 0;
}